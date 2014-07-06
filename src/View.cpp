/*
 * View.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#include "View.h"
#include <iostream>

using namespace std;

View::View(int argc, char **argv) {
    const char* APPLICATION_NAME = "c.a.l.c.u.l.a.t.o.r";
    const char* LAYOUT_FILE_NAME = "/home/user1/spikes/cpp/calculator/src/res/Main.glade";

    createApplication(argc, argv, APPLICATION_NAME);
    _builder = createBuilder(LAYOUT_FILE_NAME);
    const char* appWindowName = "applicationwindow";
    _builder->get_widget(appWindowName, _appWindow);
    if(!_appWindow){
        logError("Application window not fount in layout definition");
        return;
    }
}

View::~View() {
	if(_appWindow)
		delete _appWindow;
}

void View::show(){
	if(_appWindow)
		_app->run(*_appWindow);
}

//Find a button by the builder and bind a click-signal to a function
void View::bindButtonOnClick(Glib::RefPtr<Gtk::Builder> builder,
                             const std::string& buttonName,
                             void (View::*func)(void)) {
	Gtk::Button* button = 0;
	builder->get_widget(buttonName, button);
	if (!button)
		return;
	button->signal_clicked().connect(sigc::mem_fun(this, func));
}

void View::closeApplication() {
    if (_appWindow)
        _app->remove_window(*_appWindow);
}

//temporary closing the window
void View::onCalculateClicked(){
    closeApplication();
}

void View::setPresenter(IPresenter* presenter) {
    _presenter = presenter;
    bindButtonOnClick(_builder, "btnCalculate", &View::onCalculateClicked);
}

void View::createApplication(int argc, char** argv, const char* applicationName) {
    //applicationName - unique name, it should contain at least one full-stop
   _app = Gtk::Application::create(argc, argv, applicationName);
}

void View::logError(const char* message, const Glib::Exception& ex) {
    std::cerr << message << ex.what() << std::endl;
}

void View::logError(const char* message) {
    std::cerr << message << std::endl;
}

Glib::RefPtr<Gtk::Builder> View::createBuilder(const std::string& layoutFileName) {
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    try {
        builder->add_from_file(layoutFileName);
    } catch (const Glib::FileError& ex) {
        logError("FileError: ", ex);
    } catch (const Glib::MarkupError& ex) {
        logError("MarkupError: ", ex);
    } catch (const Gtk::BuilderError& ex) {
        logError("BuilderError: ", ex);
    }
    return builder;
}

