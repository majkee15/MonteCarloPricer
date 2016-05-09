/*
 * StatisticsMC.h
 *
 *  Created on: 8 May 2016
 *      Author: Michael
 */

#ifndef STATISTICSMC_H_
#define STATISTICSMC_H_
#include <vector>
#include <string>
class StatisticsMC {
public:
	StatisticsMC();
	virtual ~StatisticsMC();
	virtual void DumpOneResult(double result)=0;
	virtual std::vector<std::vector<double> > GetResultsSoFar() const = 0;
	virtual StatisticsMC* clone() const = 0;
	//virtual std::string toString();
private:

};

class StatisticsMean:public StatisticsMC
{
public:
	StatisticsMean();
	virtual ~StatisticsMean();
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double> > GetResultsSoFar() const;
	virtual StatisticsMC* clone() const;
	//virtual std::string toString() const;
private:
	double RunningSum;
	unsigned long PathsDone;
};
#endif /* STATISTICSMC_H_ */
