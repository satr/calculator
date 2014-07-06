/*
 * View.h
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#ifndef VIEW_H_
#define VIEW_H_
#include <gtkmm.h>
#include "ILogger.h"
#include "IPresenter.h"

class View {
private:
    ILogger *_logger;
    Glib::RefPtr<Gtk::Application> _app;
    Glib::RefPtr<Gtk::Builder> _builder;
    Gtk::Window *_appWindow;
    Gtk::SpinButton *_numValue1;
    Gtk::SpinButton *_numValue2;
    Gtk::Label *_lblResult;
	IPresenter *_presenter;
    void closeApplication();
    Glib::RefPtr<Gtk::Builder> createBuilder(const std::string& layoutFileName);
    void createApplication(int argc, char** argv, const char* applicationName);
    std::string toString(double value);
	template <class T> void bindButtonOnClick(const std::string& buttonName,
	                                                  T* obj, void (T::*func)(void));
	template <class T> Gtk::SpinButton* bindNumValueUpdate(const std::string&  buttonName,
	                                                       T* obj, void (T::*func)(void));
	template <class T_handler, class T_widget> void bindWidgetToSignal(T_widget* widget, const std::string&  buttonName,
	        Glib::SignalProxy0<void> (T_widget::*signal)(void), T_handler* obj, void (T_handler::*func)(void));
	void valueUpdated(Gtk::SpinButton* numButton, void (IPresenter::*setValueFunc)(double));
	void value1Updated();
	void value2Updated();

public:
	View(int, char**, ILogger*);
	virtual ~View();
	void show();
	void setPresenter(IPresenter*);
	void setResult(double value);
};



#endif /* VIEW_H_ */
