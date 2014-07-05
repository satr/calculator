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
	  app = Gtk::Application::create(argc, argv, "c.a.l.c.u.l.a.t.o.r");
	  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
	  try
	  {
	    builder->add_from_file("/home/user1/spikes/cpp/calculator/src/res/Main.glade");
	  }
	  catch(const Glib::FileError& ex)
	  {
	    std::cerr << "FileError: " << ex.what() << std::endl;
	  }
	  catch(const Glib::MarkupError& ex)
	  {
	    std::cerr << "MarkupError: " << ex.what() << std::endl;
	  }
	  catch(const Gtk::BuilderError& ex)
	  {
	    std::cerr << "BuilderError: " << ex.what() << std::endl;
	  }

	  builder->get_widget("applicationwindow", appWindow);
	  if(!appWindow)
	      return;

	  BindButtonOnClick(builder, "btnCalculate", &View::OnCalculateClicked);
}

View::~View() {
	if(appWindow)
		delete appWindow;
}

void View::show(){
	if(appWindow)
		app->run(*appWindow);
}

//Find a button by the builder and bind a click-signal to a function
void View::BindButtonOnClick(Glib::RefPtr<Gtk::Builder> builder,
                             const std::string& buttonName,
                             void (View::*func)(void)) {
	Gtk::Button* button = 0;
	builder->get_widget(buttonName, button);
	if (!button)
		return;
	button->signal_clicked().connect(sigc::mem_fun(this, func));
}

void View::CloseApplication() {
    if (appWindow)
        app->remove_window(*appWindow);
}

//temporary closing the window
void View::OnCalculateClicked(){
    CloseApplication();
}

