/*
 * AddOperation.cpp
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#include "AddOperation.h"

AddOperation::AddOperation(): OperationBase("add", "+") {
}

double AddOperation::execute(double value1, double value2) {
    return value1 + value2;
}
