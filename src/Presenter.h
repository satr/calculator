/*
 * Presenter.h
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#ifndef PRESENTER_H_
#define PRESENTER_H_
#include "IPresenter.h"
#include "View.h"
#include "Model.h"

class Presenter: public virtual IPresenter {
private:
	View *_view;
	Model *_model;

public:
	Presenter(View *view, Model *model);
	virtual void run();
	virtual void calculate();
    virtual void setValue1(double);
    virtual void setValue2(double);
};

#endif /* PRESENTER_H_ */
