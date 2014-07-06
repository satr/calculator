/*
 * IPresenter.h
 *
 *  Created on: Jul 5, 2014
 *      Author: user1
 */

#ifndef IPRESENTER_H_
#define IPRESENTER_H_


class IPresenter{
public:
    virtual ~IPresenter(){};
    virtual void run() = 0;
};


#endif /* IPRESENTER_H_ */
