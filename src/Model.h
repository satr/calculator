/*
 * Model.h
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#ifndef MODEL_H_
#define MODEL_H_
#include <iostream>

using namespace std;

class Model {
private:
    static const std::string UNDEFINED_OPERATION_ID;
    double _value1;
    double _value2;
    std::string _currentOperationId;

public:
    Model();
    double calculate();
    void setValue1(double);
    void setValue2(double);
    void setCurrentOperation(std::string);
};

#endif /* MODEL_H_ */
