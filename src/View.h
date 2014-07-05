/*
 * View.h
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#ifndef VIEW_H_
#define VIEW_H_
#include <gtkmm.h>

class View {
private:
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Window *appWindow;
	void BindButtonOnClick(Glib::RefPtr<Gtk::Builder> builder, const std::string& widgetName, void (View::*)(void));
    void CloseApplication();

public:
	View(int, char**);
	virtual ~View();
	void show();
	void OnCalculateClicked();
};



#endif /* VIEW_H_ */
