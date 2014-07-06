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
	IPresenter *_presenter;
	void bindButtonOnClick(Glib::RefPtr<Gtk::Builder> builder, const std::string& widgetName, void (View::*)(void));
    void closeApplication();
    Glib::RefPtr<Gtk::Builder> createBuilder(const std::string& layoutFileName);
    void createApplication(int argc, char** argv, const char* applicationName);
    void logError(const char* message);
    void logError(const char* message, const Glib::Exception& ex);

public:
	View(int, char**);
	virtual ~View();
	void show();
	void onCalculateClicked();
	void setPresenter(IPresenter*);
};



#endif /* VIEW_H_ */
