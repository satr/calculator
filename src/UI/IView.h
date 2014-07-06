/*
 * IView.h
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#ifndef IVIEW_H_
#define IVIEW_H_
#include "IPresenter.h"

class IView{
public:
    virtual ~IView(){};
    virtual void show() = 0;
    virtual void setPresenter(IPresenter*) = 0;
    virtual void setResult(double value) = 0;
};

#endif /* IVIEW_H_ */
