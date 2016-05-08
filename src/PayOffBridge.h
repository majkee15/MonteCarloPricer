/*
 * PayOffBridge.h
 *
 *  Created on: 8 May 2016
 *      Author: Michael
 */

#ifndef PAYOFFBRIDGE_H_
#define PAYOFFBRIDGE_H_
#include "PayOff2.h"
class PayOffBridge {
public:
	PayOffBridge(const PayOffBridge& original);
	PayOffBridge(const PayOff& innerPayOff);

	inline double operator()(double Spot) const;
	virtual ~PayOffBridge();
	PayOffBridge& operator= (const PayOffBridge& original);

private:
	PayOff* ThePayOffPtr;

};

inline double PayOffBridge::operator() (double Spot) const
{
	return ThePayOffPtr->operator()(Spot);
}

#endif /* PAYOFFBRIDGE_H_ */
