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
	    builder->add_from_file("../src/res/Main.glade");
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
	    Gtk::Button* pButton = 0;
	    builder->get_widget("btnCalculate", pButton);
	    if(pButton)
	    {
	      pButton->signal_clicked().connect( sigc::mem_fun(*this, &View::OnCalculateClicked));
	    }
}

View::~View() {
	if(appWindow)
		delete appWindow;
}

void View::show(){
	if(appWindow)
		app->run(*appWindow);
}

void View::OnCalculateClicked(){
  if(appWindow)
	  app->remove_window(*appWindow);
}

