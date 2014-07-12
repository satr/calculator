//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Diagnostics/ConsoleLogger.h"
#include "UI/View.h"
#include "BL/Model.h"
#include "UI/Presenter.h"
#include <gtkmm/main.h>

using namespace std;

int main(int argc, char *argv[]) {
    ConsoleLogger logger;
	View view (argc, argv, &logger);
	Model model;
	Presenter presenter (&view, &model, &logger);
	presenter.run();
	return 0;
}
