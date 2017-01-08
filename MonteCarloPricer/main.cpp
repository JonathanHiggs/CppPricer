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

	VanillaOption* callOption = new VanillaOption(new PayOffCall(strike), expiry);

	VanillaOption* putOption = new VanillaOption(new PayOffPut(strike), expiry);

	VanillaOption* digitalCallOption = new VanillaOption(new PayOffDigitalCall(strike), expiry);
	
	VanillaOption* digitalPutOption = new VanillaOption(new PayOffDigitalPut(strike), expiry);
	
	VanillaOption* doubleDigitalOption = new VanillaOption(new PayOffDoubleDigital(82.0, 85.0), expiry);
	
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

