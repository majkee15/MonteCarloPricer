/*
 * SimpleMonteCarlo.h
 *
 *  Created on: 24 Jan 2016
 *      Author: Michael
 */

#ifndef SIMPLEMONTECARLO_H_
#define SIMPLEMONTECARLO_H_
#include "VanillaOption.h"
#include "Parameters.h"
class SimpleMonteCarlo {
public:
	SimpleMonteCarlo();

	virtual ~SimpleMonteCarlo();

	double SimpleMonteCarlo1(const VanillaOption& TheOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths);
};

#endif /* SIMPLEMONTECARLO_H_ */
