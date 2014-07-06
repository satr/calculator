//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "View.h"
#include "Model.h"
#include "Presenter.h"
#include <gtkmm/main.h>

using namespace std;

int main(int argc, char *argv[]) {
	View view (argc, argv);
	Model model;
	Presenter presenter (&view, &model);
	presenter.run();
	return 0;
}
