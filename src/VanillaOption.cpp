/*
 * VanillaOption.cpp
 *
 *  Created on: 7 May 2016
 *      Author: Michael
 */

#include "VanillaOption.h"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_,double Expiry_)
:ThePayOff(ThePayOff_),Expiry(Expiry_)
{
}

VanillaOption::~VanillaOption() {
}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}
double VanillaOption::OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}

/*
VanillaOption::VanillaOption(const VanillaOption& original)
{
	Expiry = original.Expiry;
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

VanillaOption& VanillaOption::operator =(const VanillaOption& original)
{
	if(this!=&original)
	{
		Expiry = original.Expiry;
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;

}
*/
