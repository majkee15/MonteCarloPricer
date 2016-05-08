/*
 * SimpleMonteCarlo.cpp
 *
 *  Created on: 24 Jan 2016
 *      Author: Michael
 */

#include "SimpleMonteCarlo.h"
#include<cmath>
#include<iostream>
#include "Random1.h"

SimpleMonteCarlo::SimpleMonteCarlo() {
	// TODO Auto-generated constructor stub

}

SimpleMonteCarlo::~SimpleMonteCarlo() {
	// TODO Auto-generated destructor stub
}

double SimpleMonteCarlo::SimpleMonteCarlo1(const VanillaOption& TheOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths)
{
	double Expiry =TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0,Expiry);
	double rootVariance =sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot=Spot*exp(r.Integral(0,Expiry)+itoCorrection);
	double thisSpot;
	double runningSum = 0;
	for(unsigned long i= 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = Random1::GetOneGaussianByBoxMuller();
		thisSpot=movedSpot*exp(rootVariance*thisGaussian);
		double thisPayoff = TheOption.OptionPayOff(thisSpot);
		runningSum += thisPayoff;

	}

	double mean = runningSum/NumberOfPaths;
	mean *= exp(-r.Integral(0,Expiry)*Expiry);
	return mean;
}
