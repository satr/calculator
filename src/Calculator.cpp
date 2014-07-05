//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Presenter.h"
#include "View.h"
#include <gtkmm/main.h>

using namespace std;

int main(int argc, char *argv[]) {
	View view (argc, argv);
	Presenter presenter (&view);
	presenter.run();
	return 0;
}
