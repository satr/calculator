/*
 * Presenter.cpp
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#include "Presenter.h"

Presenter::Presenter(IView *view, Model *model, ILogger *logger)
    : _view(view), _model(model), _logger(logger) {
    _view->setPresenter(this);
}

void Presenter::run(){
	_view->show();
}

void Presenter::calculate() {
    _view->setResult(_model->calculate());
    _logger->logDebug("calculate invoked");
}

void Presenter::setValue1(double value) {
     _model->setValue1(value);
    _logger->logDebug("new value1 set");
}

void Presenter::setValue2(double value) {
    _model->setValue2(value);
    _logger->logDebug("new value2 set");
}

void Presenter::setCurrentOperation(std::string operationId) {
    _model->setCurrentOperation(operationId);
    _logger->logDebug("operation set: " + operationId);
}
