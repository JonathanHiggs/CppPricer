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
	PayOff callPayOff(strike, OptionType::call);
	PayOff putPayOff(strike, OptionType::put);
	double spot = 80;
	double vol = 0.05;
	double discountRate = 0.05;
	unsigned long numberOfPaths = 10000;

	double callPrice = SimpleMonteCarlo(callPayOff, expiry, spot, vol, discountRate, numberOfPaths);
	double putPrice = SimpleMonteCarlo(putPayOff, expiry, spot, vol, discountRate, numberOfPaths);

	cout << "The call price is:  " << callPrice << endl;
	cout << "The put price is:   " << putPrice << endl;

	string tmp;
	cin >> tmp;

	return 0;
}

