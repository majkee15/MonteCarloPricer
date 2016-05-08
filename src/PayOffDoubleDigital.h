/*
 * PayOffDoubleDigital.h
 *
 *  Created on: 6 May 2016
 *      Author: Michael
 */

#ifndef PAYOFFDOUBLEDIGITAL_H_
#define PAYOFFDOUBLEDIGITAL_H_

#include "PayOff2.h"

class PayOffDoubleDigital: public PayOff {
public:
	PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
	virtual double operator() (double Spot) const;
	virtual ~PayOffDoubleDigital();
	virtual  PayOff* clone() const;
private:
	double LowerLevel;
	double UpperLevel;

};

#endif /* PAYOFFDOUBLEDIGITAL_H_ */
