// main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SimpleMonteCarlo.h"
#include "Option.h"
#include "PayOff.h"
#include "StatisticsGatherer.h"
#include "MeanGatherer.h"
#include "ConvergenceTableGatherer.h"
#include <iostream>
#include <string>
#include <memory>


using namespace std;


int main()
{
	double expiry = 1;
	double strike = 85;

	ConvergenceTableGatherer callOptionStats(unique_ptr<StatisticsGatherer>(new MeanGatherer()));
	VanillaOption callOption(new PayOffCall(strike), expiry);

	MeanGatherer putOptionStats;
	VanillaOption putOption(new PayOffPut(strike), expiry);

	MeanGatherer digitalCallOptionStats;
	VanillaOption digitalCallOption(new PayOffDigitalCall(strike), expiry);
	
	MeanGatherer digitalPutOptionStats;
	VanillaOption digitalPutOption(new PayOffDigitalPut(strike), expiry);
	
	MeanGatherer doubleDigitalOptionStats;
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

	cout << "The call option results:" << endl << callOptionStats.GetResultTable() << endl << endl;

	cout << "The call price is:           " << callOptionStats.GetResultsSoFar() << endl;
	cout << "The put price is:            " << putOptionStats.GetResultsSoFar() << endl;
	cout << "The digital call price is:   " << digitalCallOptionStats.GetResultsSoFar() << endl;
	cout << "The digital put price is:    " << digitalPutOptionStats.GetResultsSoFar() << endl;
	cout << "The double digital price is: " << doubleDigitalOptionStats.GetResultsSoFar() << endl;

	return 0;
}

