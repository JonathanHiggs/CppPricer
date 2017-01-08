// main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SimpleMonteCarlo.h"
#include "Option.h"
#include "PayOff.h"
#include "Statistics.h"
#include "ConvergenceTable.h"
#include <iostream>
#include <string>
#include <memory>


using namespace std;


ostream& display_result(ostream& os, ConvergenceTable& convergenceTable)
{
	vector<vector<double>> results = convergenceTable.GetResultsSoFar();
	double price, paths;

	for (auto i = 0; i < results.size(); i++)
	{
		price = results[i][0];
		paths = results[i][1];

		os << "Price after " << (int)paths << " paths  is " << price << endl;
	}

	return os;
}


int main()
{
	double expiry = 1;
	double strike = 85;

	ConvergenceTable callOptionStats(new StatisticsMean());
	VanillaOption callOption(new PayOffCall(strike), expiry);

	StatisticsMean putOptionStats;
	VanillaOption putOption(new PayOffPut(strike), expiry);

	StatisticsMean digitalCallOptionStats;
	VanillaOption digitalCallOption(new PayOffDigitalCall(strike), expiry);
	
	StatisticsMean digitalPutOptionStats;
	VanillaOption digitalPutOption(new PayOffDigitalPut(strike), expiry);
	
	StatisticsMean doubleDigitalOptionStats;
	VanillaOption doubleDigitalOption(new PayOffDoubleDigital(82.0, 85.0), expiry);
	
	double spot = 80;
	ParameterConstant vol(0.05);
	ParameterConstant discountRate(0.05);
	unsigned long numberOfPaths = 1000000;

	SimpleMonteCarlo(callOption, spot, vol, discountRate, numberOfPaths, callOptionStats);
	SimpleMonteCarlo(putOption, spot, vol, discountRate, numberOfPaths, putOptionStats);
	SimpleMonteCarlo(digitalCallOption, spot, vol, discountRate, numberOfPaths, digitalCallOptionStats);
	SimpleMonteCarlo(digitalPutOption, spot, vol, discountRate, numberOfPaths, digitalPutOptionStats);
	SimpleMonteCarlo(doubleDigitalOption,  spot, vol, discountRate, numberOfPaths, doubleDigitalOptionStats);

	cout << "The call option:" << endl;
	display_result(cout, callOptionStats) << endl << endl;

	cout << "The call price is:           " << callOptionStats.GetResultsSoFar()[0][0] << endl;
	cout << "The put price is:            " << putOptionStats.GetResultsSoFar()[0][0] << endl;
	cout << "The digital call price is:   " << digitalCallOptionStats.GetResultsSoFar()[0][0] << endl;
	cout << "The digital put price is:    " << digitalPutOptionStats.GetResultsSoFar()[0][0] << endl;
	cout << "The double digital price is: " << doubleDigitalOptionStats.GetResultsSoFar()[0][0] << endl;

	return 0;
}

