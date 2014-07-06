//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ConsoleLogger.h"
#include "View.h"
#include "Model.h"
#include "Presenter.h"
#include <gtkmm/main.h>

using namespace std;

int main(int argc, char *argv[]) {
    ConsoleLogger logger;
	View view (argc, argv, &logger);
	Model model;
	Presenter presenter (&view, &model);
	presenter.run();
	return 0;
}
