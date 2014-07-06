/*
 * Presenter.h
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#ifndef PRESENTER_H_
#define PRESENTER_H_
#include "View.h"
#include "IPresenter.h"

class Presenter: public virtual IPresenter {
private:
	View *_view;
public:
	Presenter(View *view);
	virtual void run();
	void calculate();
};

#endif /* PRESENTER_H_ */
