//============================================================================
// Name        : BlackScholes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<random>
#include "SimpleMonteCarlo.h"
#include "PayOff2.h"
#include "PayOffDoubleDigital.h"
#include "VanillaOption.h"
#include "Parameters.h"
using namespace std;

int main() {

	//cout << "Gaussian:" << r.GetOneGaussianByBoxMuller() <<endl; // prints !!!Hello World!!!
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

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);
	PayOffCall callPayOff(Strike);
	PayOffPut putPayOff(Strike);
	PayOffDoubleDigital digitalPayOff(lower, upper);
	VanillaOption call(callPayOff,Expiry);
	VanillaOption put(putPayOff,Expiry);
	VanillaOption digital(digitalPayOff,Expiry);
	double resultCall = m.SimpleMonteCarlo1(call,Spot,VolParam,rParam,NumberOfPaths);
	double resultPut = m.SimpleMonteCarlo1(put,Spot,VolParam,rParam,NumberOfPaths);
	double resultDigital = m.SimpleMonteCarlo1(digital,Spot,VolParam,rParam,NumberOfPaths);

	cout<<"Result call: "<<endl;
	cout<<resultCall<<endl;


	cout<<"Result put: "<<endl;
	cout<<resultPut<<endl;

	cout <<"Result digital:"<<endl;
	cout<<resultDigital<<endl;


	//PayOff1 call(Strike, PayOff1::call);
	//PayOff1 put(Strike, PayOff1::put);
	//cout<<"Result call: "<<endl;
	//cout<<m.SimpleMonteCarlo(call,Expiry, Spot, Vol, r, NumberOfPaths)<<endl;


	//cout<<"Result put: "<<endl;
	//cout<<m.SimpleMonteCarlo1(put,Expiry, Spot, Vol, r, NumberOfPaths)<<endl;
	/*
	double ran,sum,var,exp,sumsqr;
	int rep=10000;
	sum=0;
	sumsqr=0;
	std::normal_distribution<double> dist(0,1);
	std::default_random_engine generator;
	for(int i=0; i<rep; i++)
	{
		ran=Random1::GetOneGaussianByBoxMuller();
		//r=dist(generator);
		cout<<ran<<endl;
		sum+=ran;
		sumsqr+=pow(ran,2);

	}
	exp=sum/rep;
	var=sumsqr/rep;
	cout<<"EXPECTATION:"<<exp<<endl;
	cout<<"VARIANCE:"<<var<<endl;
	//cout<<Random1::GetOneGaussianByBoxMuller();;
	cout<<"hulmiho";
	*/

}

