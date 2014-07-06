/*
 * Presenter.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#include "Presenter.h"

Presenter::Presenter(View *view) {
	_view = view;
    _view->setPresenter(this);
}

void Presenter::run(){
	_view->show();
}

void Presenter::calculate() {
    _view->setResult(1.23);
}
