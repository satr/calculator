/*
 * Model.cpp
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#include "Model.h"

double Model::calculate() {
    return _value1 + _value2;
}

void Model::setValue1(double value) {
    _value1 = value;
}

Model::Model(): _value1(0), _value2(0) {
}

void Model::setValue2(double value) {
    _value2 = value;
}
