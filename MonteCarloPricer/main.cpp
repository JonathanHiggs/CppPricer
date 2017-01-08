// main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SimpleMonteCarlo.h"
#include "Option.h"
#include "PayOff.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
	double expiry = 1;
	double strike = 85;

	PayOffCall payOffCall(strike);
	VanillaOption* callOption = new VanillaOption(payOffCall, expiry);

	PayOffPut payOffPut(strike);
	VanillaOption* putOption = new VanillaOption(payOffPut, expiry);

	PayOffDigitalCall payOffDigitalCall(strike);
	VanillaOption* digitalCallOption = new VanillaOption(payOffDigitalCall, expiry);
	
	PayOffDigitalPut payOffDigitalPut(strike);
	VanillaOption* digitalPutOption = new VanillaOption(payOffDigitalPut, expiry);
	
	PayOffDoubleDigital payOffDoubleDigital(82.0, 86.0);
	VanillaOption* doubleDigitalOption = new VanillaOption(payOffDoubleDigital, expiry);
	
	double spot = 80;
	ParameterConstant vol(0.05);
	ParameterConstant discountRate(0.05);
	unsigned long numberOfPaths = 1000000;

	double callPrice = SimpleMonteCarlo(*callOption, spot, vol, discountRate, numberOfPaths);
	double putPrice = SimpleMonteCarlo(*putOption, spot, vol, discountRate, numberOfPaths);
	double digitalCallPrice = SimpleMonteCarlo(*digitalCallOption, spot, vol, discountRate, numberOfPaths);
	double digitalPutPrice =  SimpleMonteCarlo(*digitalPutOption, spot, vol, discountRate, numberOfPaths);
	double doubleDigitalPrice = SimpleMonteCarlo(*doubleDigitalOption,  spot, vol, discountRate, numberOfPaths);

	cout << "The call price is:           " << callPrice << endl;
	cout << "The put price is:            " << putPrice << endl;
	cout << "The digital call price is:   " << digitalCallPrice << endl;
	cout << "The digital put price is:    " << digitalPutPrice << endl;
	cout << "The double digital price is: " << doubleDigitalPrice << endl;

	return 0;
}

