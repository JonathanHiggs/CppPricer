// MonteCarloPricer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SimpleMonteCarlo.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
	double expiry = 1;
	double strike = 85;
	PayOffCall call(strike);
	PayOffPut put(strike);
	PayOffDigitalCall digitalCall(strike);
	PayOffDigitalPut digitalPut(strike);
	PayOff* doubleDigital = new PayOffDoubleDigital(82.0, 85.0);
	double spot = 80;
	double vol = 0.05;
	double discountRate = 0.05;
	unsigned long numberOfPaths = 1000000;

	double callPrice = SimpleMonteCarlo(call, expiry, spot, vol, discountRate, numberOfPaths);
	double putPrice = SimpleMonteCarlo(put, expiry, spot, vol, discountRate, numberOfPaths);
	double digitalCallPrice = SimpleMonteCarlo(digitalCall, expiry, spot, vol, discountRate, numberOfPaths);
	double digitalPutPrice =  SimpleMonteCarlo(digitalPut, expiry, spot, vol, discountRate, numberOfPaths);
	double doubleDigitalPrice = SimpleMonteCarlo(*doubleDigital, expiry, spot, vol, discountRate, numberOfPaths);

	cout << "The call price is:           " << callPrice << endl;
	cout << "The put price is:            " << putPrice << endl;
	cout << "The digital call price is:   " << digitalCallPrice << endl;
	cout << "The digital put price is:    " << digitalPutPrice << endl;
	cout << "The double digital price is: " << doubleDigitalPrice << endl;

	return 0;
}

