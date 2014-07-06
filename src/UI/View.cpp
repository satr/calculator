/*
 * View.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#include "View.h"
#include <iostream>

using namespace std;

const char* View::APPLICATION_NAME = "c.a.l.c.u.l.a.t.o.r";
const char* View::LAYOUT_FILE_NAME = "/home/user1/spikes/cpp/calculator/src/res/Main.glade";

View::View(int argc, char **argv, ILogger *logger): _logger(logger) {

    createApplication(argc, argv, APPLICATION_NAME);
    _builder = createBuilder(LAYOUT_FILE_NAME);
    const char* appWindowName = "applicationwindow";
    _builder->get_widget(appWindowName, _appWindow);
    if(!_appWindow){
        _logger->logError("Application window not fount in layout definition");
        return;
    }
    _builder->get_widget("lblResult", _lblResult);
}

View::~View() {
	if(_appWindow)
		delete _appWindow;
}

void View::show(){
	if(_appWindow)
		_app->run(*_appWindow);
}

//Find a button by the builder and bind a click-signal to a function of an object
template <class T_handler> void View::bindButtonOnClick(const std::string& widgetName, T_handler* obj,
                                                        void (T_handler::*func)(void)) {
    View::bindWidgetToSignal<T_handler, Gtk::Button>(widgetName, &Gtk::Button::signal_clicked, obj, func);
}

//Find a button by the builder and bind a change-value-signal to a function of an object
template <class T_handler> Gtk::SpinButton* View::bindNumValueUpdate(const std::string&  widgetName, T_handler* obj,
                                                                     void (T_handler::*func)(void)) {
    return View::bindWidgetToSignal<T_handler, Gtk::SpinButton>(widgetName, &Gtk::SpinButton::signal_value_changed, obj, func);
}

template<class T_handler> Gtk::ComboBoxText* View::bindComboBoxOnChange(const std::string& widgetName,
        T_handler* obj, void (T_handler::*func)(void)) {
    return View::bindWidgetToSignal<T_handler, Gtk::ComboBoxText>(widgetName, &Gtk::ComboBox::signal_changed, obj, func);
}

//Find a widget by the builder and bind a signal to a function of an object
template <class T_handler, class T_widget> T_widget* View::bindWidgetToSignal(const std::string&  buttonName,
                                                                              Glib::SignalProxy0<void> (T_widget::*signal)(void),
                                                                              T_handler* obj, void (T_handler::*func)(void)) {
    if(!_builder)
        return 0;

    T_widget* widget = 0;
    _builder->get_widget(buttonName, widget);
    if (!widget)
        return widget;

    (widget->*signal)().connect(sigc::mem_fun(obj, func));
    return widget;
}

void View::closeApplication() {
    if (_appWindow)
        _app->remove_window(*_appWindow);
}

void View::setPresenter(IPresenter* presenter) {
    _presenter = presenter;
    bindButtonOnClick("btnCalculate", _presenter, &IPresenter::calculate);
    _numValue1 = bindNumValueUpdate("numValue1", this, &View::value1Updated);
    _numValue2 = bindNumValueUpdate("numValue2", this, &View::value2Updated);
    _lstOperation = bindComboBoxOnChange("lstOperation", this, &View::operationUpdated);
}

void View::createApplication(int argc, char** argv, const char* applicationName) {
    //applicationName - unique name, it should contain at least one full-stop
   _app = Gtk::Application::create(argc, argv, applicationName);
}

Glib::RefPtr<Gtk::Builder> View::createBuilder(const std::string& layoutFileName) {
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    try {
        builder->add_from_file(layoutFileName);
    } catch (const Glib::FileError& ex) {
        _logger->logError("FileError", ex.what());
    } catch (const Glib::MarkupError& ex) {
        _logger->logError("MarkupError", ex.what());
    } catch (const Gtk::BuilderError& ex) {
        _logger->logError("BuilderError", ex.what());
    }
    return builder;
}

void View::value1Updated(){
    valueUpdated(_numValue1, &IPresenter::setValue1);
}

void View::value2Updated(){
    valueUpdated(_numValue2, &IPresenter::setValue2);
}

void View::valueUpdated(Gtk::SpinButton* numButton, void (IPresenter::*func)(double)){
    if(!numButton || !_presenter)
        return;
    (_presenter->*func)(numButton->get_value());
}

void View::operationUpdated() {
    if(!_lstOperation || !_presenter)
        return;
    _presenter->setCurrentOperation(_lstOperation->get_active_id());
}

void View::setResult(double value) {
    if(!_lblResult)
        return;
    _lblResult->set_text(toString(value));
}

std::string View::toString(double value)
{
  std::ostringstream str;
  str << value;
  return str.str();
}

void View::addOperation(std::string id, std::string name) {
    if(!_lstOperation)
        return;
    _lstOperation->append(id, name);
}

void View::setCurrentOperation() {
    _lstOperation->set_active(0);
}
