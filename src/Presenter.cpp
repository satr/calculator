/*
 * Presenter.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#include "Presenter.h"

Presenter::Presenter(View *view) {
	_view = view;
}

Presenter::~Presenter() {
}

void Presenter::run(){
	_view->show();
}

