/*
 * PayOff2.h
 *
 *  Created on: 5 May 2016
 *      Author: Michael
 */

#ifndef PAYOFF2_H_
#define PAYOFF2_H_

class PayOff {
public:
	PayOff();
	virtual ~PayOff();
	virtual double operator() (double Spot) const = 0;
	virtual  PayOff* clone() const=0;
private:
protected:
	double max(double a,double b) const;
	double min(double a, double b) const;

};

//==================PAY OFF CALL ============VANILLA !!!

class PayOffCall: public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall(){}
	virtual PayOff* clone() const;
private:
	double Strike;
};

//==================PAY OFF PUT ============VANILLA !!!

class PayOffPut:public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut(){}
	virtual  PayOff* clone() const;
private:
	double Strike;
};


#endif /* PAYOFF2_H_ */
