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

double SimpleMonteCarlo::SimpleMonteCarlo1(const VanillaOption& TheOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, StatisticsMC& gatherer)
{
	double Expiry =TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0,Expiry);
	double rootVariance =sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot=Spot*exp(r.Integral(0,Expiry)+itoCorrection);
	double thisSpot;
	double discounting = exp(-r.Integral(0,Expiry));
	for(unsigned long i= 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = Random1::GetOneGaussianByBoxMuller();
		thisSpot=movedSpot*exp(rootVariance*thisGaussian);
		double thisPayoff = TheOption.OptionPayOff(thisSpot);
		gatherer.DumpOneResult(thisPayoff*discounting);

	}

	return 0;
}
