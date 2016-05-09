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
#include "ConvergenceTable.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"
#include "ParkMiller.h"
#include "Antithetic.h"

using namespace std;

int main() {

	srand(time(0));
	SimpleMonteCarlo m;
	double Expiry=1;
	double Strike=100;
	double Spot=100;
	double Vol=0.22;
	double r=0.05;
	double d =3;
	unsigned long NumberOfPaths=100000;
	unsigned int NumberOfDates=12;
	MJArray times(NumberOfDates);

	double lower = 90;
	double upper = 110;

	StatisticsMean gatherer1;
	StatisticsMean gatherer2;
	StatisticsMean gatherer3;
	StatisticsMean gatherer;
	ConvergenceTable gathererOne(gatherer1);
	ConvergenceTable gathererEx(gatherer);
	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	ParametersConstant dParam(r);
	PayOffCall exoticPayOff(Strike);
	PayOffCall callPayOff(Strike);
	PayOffPut putPayOff(Strike);
	PayOffDoubleDigital digitalPayOff(lower, upper);
	VanillaOption call(callPayOff,Expiry);
	VanillaOption put(putPayOff,Expiry);
	VanillaOption digital(digitalPayOff,Expiry);
	//PathDependentAsian theOption(times,Expiry,exoticPayOff);



	//RandomParkMiller generator(NumberOfDates);
	//AntiThetic GenTwo(generator);
	//ExoticBSEngine theEngine(theOption,rParam,dParam,VolParam,GenTwo,Spot);
	//theEngine.DoSimulation(gathererEx,NumberOfPaths);
	m.SimpleMonteCarlo1(call,Spot,VolParam,rParam,NumberOfPaths,gatherer1);
	m.SimpleMonteCarlo1(put,Spot,VolParam,rParam,NumberOfPaths,gatherer2);
	m.SimpleMonteCarlo1(digital,Spot,VolParam,rParam,NumberOfPaths,gatherer3);

	//std::vector<std::vector<double> > resex = gathererEx.GetResultsSoFar();
	std::vector<vector<double> > results1 = gatherer1.GetResultsSoFar();
	std::vector<vector<double> > results2 = gatherer2.GetResultsSoFar();
	std::vector<vector<double> > results3 = gatherer3.GetResultsSoFar();
	/*
	cout<<"Asian call price:"<<endl;
	for(int i =0; i< resex.size(); i++)
		{
			for(int j =0; j< resex[i].size(); j++)
			{
				cout<<results1[i][j]<<" ";
				cout<<endl;
			}
		}
*/

	cout<<"Call:"<<endl;

	for(int i =0; i< results1.size(); i++)
	{
		for(int j =0; j< results1[i].size(); j++)
		{
			cout<<results1[i][j]<<" ";
			cout<<endl;
		}
	}

	cout<<"Put:"<<endl;
	for(int i =0; i< results2.size(); i++)
	{
			for(int j =0; j< results2[i].size(); j++)
			{
				cout<<results2[i][j]<<" ";
						cout<<endl;
			}
	}
	cout<<"Digital:"<<endl;
		for(int i =0; i< results3.size(); i++)
		{
				for(int j =0; j< results3[i].size(); j++)
				{
					cout<<results3[i][j]<<" ";
							cout<<endl;
				}
		}
/*
	cout<<"Result put: "<<endl;
	cout<<resultPut<<endl;

	cout <<"Result digital:"<<endl;
	cout<<resultDigital<<endl;
*/
}

