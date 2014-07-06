/*
 * View.h
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#ifndef VIEW_H_
#define VIEW_H_
#include <gtkmm.h>
#include "IPresenter.h"

class View {
private:
    Glib::RefPtr<Gtk::Application> _app;
    Glib::RefPtr<Gtk::Builder> _builder;
    Gtk::Window *_appWindow;
    Gtk::Label *_lblResult;
	IPresenter *_presenter;
    void closeApplication();
    Glib::RefPtr<Gtk::Builder> createBuilder(const std::string& layoutFileName);
    void createApplication(int argc, char** argv, const char* applicationName);
    void logError(const char* message);
    void logError(const char* message, const Glib::Exception& ex);
    std::string toString(double value);
	template <class T> void bindButtonOnClick(Glib::RefPtr<Gtk::Builder> builder, const std::string& buttonName,
	                                          T* obj, void (T::*func)(void));

public:
	View(int, char**);
	virtual ~View();
	void show();
	void setPresenter(IPresenter*);
	void setResult(double value);
};



#endif /* VIEW_H_ */
