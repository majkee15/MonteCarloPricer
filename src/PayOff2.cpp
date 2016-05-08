/*
 * PayOff2.cpp
 *
 *  Created on: 5 May 2016
 *      Author: Michael
 */

#include "PayOff2.h"

PayOff::PayOff() {
	// TODO Auto-generated constructor stub

}

PayOff::~PayOff() {
	// TODO Auto-generated destructor stub
}

double PayOff::max(double a, double b) const
{
	if (a>b)
		return a;
	else
		return b;
}
double PayOff::min(double a, double b) const
{
	if (a<b)
		return a;
	else
		return b;
}


///==============PAYOFF VANILLA ========

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}
double PayOffCall::operator() (double Spot) const
{
	return max(Spot - Strike, 0.0);
}

PayOff* PayOffCall::clone() const
{
	return new PayOffCall(*this);  //call copy constructor
}

double PayOffPut::operator() (double Spot) const
{
	return max(Strike - Spot, 0.0);
}
PayOffPut::PayOffPut(double Strike_) : Strike (Strike_)
{
}

PayOff* PayOffPut::clone() const
{
	return new PayOffPut(*this); //call copy constructor
}
