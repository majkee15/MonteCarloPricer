/*
 * VanillaOption.h
 *
 *  Created on: 7 May 2016
 *      Author: Michael
 */

#ifndef VANILLAOPTION_H_
#define VANILLAOPTION_H_

#include "PayOff2.h"
#include "PayOffBridge.h"
class VanillaOption {
public:
	VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
	VanillaOption(const VanillaOption& original);
	VanillaOption& operator= (const VanillaOption& original);
	virtual ~VanillaOption();
	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOffBridge ThePayOff;
};

#endif /* VANILLAOPTION_H_ */
