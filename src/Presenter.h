/*
 * Presenter.h
 *
 *  Created on: Jun 28, 2014
 *      Author: user1
 */

#ifndef PRESENTER_H_
#define PRESENTER_H_
#include "View.h"

class Presenter {
private:
	View *_view;
public:
	Presenter(View *view);
	virtual ~Presenter();
	void run();
};

#endif /* PRESENTER_H_ */
