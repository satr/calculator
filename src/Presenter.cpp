/*
 * Presenter.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#include "Presenter.h"

Presenter::Presenter(View *view, Model *model)
    : _view(view), _model(model) {
    _view->setPresenter(this);
}

void Presenter::run(){
	_view->show();
}

void Presenter::calculate() {
    _view->setResult(_model->calculate());
}

void Presenter::setValue1(double value) {
    _model->setValue1(value);
}

void Presenter::setValue2(double value) {
    _model->setValue2(value);
}
