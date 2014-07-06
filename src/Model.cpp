/*
 * Model.cpp
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#include "Model.h"

const std::string Model::UNDEFINED_OPERATION_ID = "undefined";

double Model::calculate() {
    if(_currentOperationId == "add")
        return _value1 + _value2;
    if(_currentOperationId == "sub")
        return _value1 - _value2;
    return 0;
}

void Model::setValue1(double value) {
    _value1 = value;
}

Model::Model(): _value1(0), _value2(0), _currentOperationId(UNDEFINED_OPERATION_ID) {
}

void Model::setValue2(double value) {
    _value2 = value;
}

void Model::setCurrentOperation(std::string  operationId) {
    _currentOperationId = operationId;
}
