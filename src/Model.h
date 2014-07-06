/*
 * Model.h
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#ifndef MODEL_H_
#define MODEL_H_

class Model {
private:
    double _value1;
    double _value2;
public:
    Model();
    double calculate();
    void setValue1(double);
    void setValue2(double);
};

#endif /* MODEL_H_ */
