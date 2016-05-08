/*
 * StatisticsMC.cpp
 *
 *  Created on: 8 May 2016
 *      Author: Michael
 */

#include "StatisticsMC.h"

StatisticsMC::StatisticsMC() {
	// TODO Auto-generated constructor stub

}

StatisticsMC::~StatisticsMC() {
	// TODO Auto-generated destructor stub
}

StatisticsMean::StatisticsMean()
:RunningSum(0.0),PathsDone(0UL)
{
}
StatisticsMean::~StatisticsMean()
{

}

void StatisticsMean::DumpOneResult(double result)
{
	PathsDone++;
	RunningSum += result;
}

std::vector<std::vector<double> > StatisticsMean::GetResultSoFar() const
{
	std::vector<std::vector<double> > Results(1);
	Results[0].resize(1);
	Results[0][0] = RunningSum / PathsDone;
	return Results;
}
StatisticsMC* StatisticsMean::clone() const
{
	return new StatisticsMean(*this);
}
std::string StatisticsMean::toString() const
{
	return 0;
}
