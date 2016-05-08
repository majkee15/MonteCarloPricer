/*
 * Random1.cpp
 *
 *  Created on: 22 Jan 2016
 *      Author: Michael
 */

#include "Random1.h"
#include <cmath>
#include <cstdlib>
#include<time.h>
#

Random1::Random1() {
	// TODO Auto-generated constructor stub

}

Random1::~Random1() {
	// TODO Auto-generated destructor stub
}

double Random1::GetOneGaussianByBoxMuller()
{//Box muller method
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
      return n2;
    }
}
