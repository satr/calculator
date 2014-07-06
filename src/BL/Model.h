/*
 * Model.h
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#ifndef MODEL_H_
#define MODEL_H_
#include <iostream>
#include <vector>
#include "Operations/OperationBase.h"

using namespace std;

class Model {
private:
    static const std::string UNDEFINED_OPERATION_ID;
    double _value1;
    double _value2;
    std::string _currentOperationId;
    std::vector<OperationBase*> _operations;

public:
    Model();
    double calculate();
    void setValue1(double);
    void setValue2(double);
    void setCurrentOperation(std::string);
    std::vector<OperationBase*> getOperations();
};

#endif /* MODEL_H_ */
