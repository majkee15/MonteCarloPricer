//============================================================================
// Name        : BlackScholes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<random>
#include<vector>
#include "SimpleMonteCarlo.h"
#include "PayOff2.h"
#include "PayOffDoubleDigital.h"
#include "VanillaOption.h"
#include "Parameters.h"
#include "StatisticsMC.h"
using namespace std;

int main() {

	srand(time(0));
	SimpleMonteCarlo m;
	double Expiry=1;
	double Strike=100;
	double Spot=100;
	double Vol=0.22;
	double r=0.05;
	unsigned long NumberOfPaths=100000;


	double lower = 90;
	double upper = 110;

	StatisticsMean gatherer1;
	StatisticsMean gatherer2;
	StatisticsMean gatherer3;
	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	PayOffCall callPayOff(Strike);
	PayOffPut putPayOff(Strike);
	PayOffDoubleDigital digitalPayOff(lower, upper);
	VanillaOption call(callPayOff,Expiry);
	VanillaOption put(putPayOff,Expiry);
	VanillaOption digital(digitalPayOff,Expiry);
	double resultCall = m.SimpleMonteCarlo1(call,Spot,VolParam,rParam,NumberOfPaths,gatherer1);
	double resultPut = m.SimpleMonteCarlo1(put,Spot,VolParam,rParam,NumberOfPaths,gatherer2);
	double resultDigital = m.SimpleMonteCarlo1(digital,Spot,VolParam,rParam,NumberOfPaths,gatherer3);

	std::vector<vector<double> > results1 = gatherer1.GetResultSoFar();
	std::vector<vector<double> > results2 = gatherer2.GetResultSoFar();
	std::vector<vector<double> > results3 = gatherer3.GetResultSoFar();
	for(int i =0; i< results1.size(); i++)
	{
		for(int j =0; j< results1[i].size(); j++)
		{
			cout<<results1[i][j]<<" ";
		}
	}

/*
	cout<<"Result put: "<<endl;
	cout<<resultPut<<endl;

	cout <<"Result digital:"<<endl;
	cout<<resultDigital<<endl;
*/
}

