// main.cpp : Defines the entry point for the console application.


#include "stdafx.h"

#include "AntiThetic.h"
#include "ConvergenceTableGatherer.h"
#include "MeanGatherer.h"
#include "MonteCarloService.h"
#include "Option.h"
#include "Parameter.h"
#include "ParameterConstant.h"
#include "PayOff.h"
#include "PayOffCall.h"
#include "PayOffPut.h"
#include "PayOffDigitalCall.h"
#include "PayOffDigitalPut.h"
#include "PayOffDoubleDigital.h"
#include "RandomParkMiller.h"
#include "StatisticsGatherer.h"

#include <iostream>
#include <string>
#include <memory>


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Parameters;
using namespace Pricer::Service;
using namespace Pricer::Statistics;
using namespace Pricer::Util;


void runMontaCarlo()
{
	double expiry = 1;
	double strike = 85;

	ConvergenceTableGatherer callOptionStats(make_unique<MeanGatherer>());
	Option callOption(make_unique<PayOffCall>(strike), expiry);

	MeanGatherer putOptionStats;
	Option putOption(make_unique<PayOffPut>(strike), expiry);

	MeanGatherer digitalCallOptionStats;
	Option digitalCallOption(make_unique<PayOffDigitalCall>(strike), expiry);
	
	MeanGatherer digitalPutOptionStats;
	Option digitalPutOption(make_unique<PayOffDigitalPut>(strike), expiry);
	
	MeanGatherer doubleDigitalOptionStats;
	Option doubleDigitalOption(make_unique<PayOffDoubleDigital>(82.0, 85.0), expiry);
	
	double spot = 80;
	ParameterConstant vol(0.05);
	ParameterConstant discountRate(0.05);
	unsigned long numberOfPaths = 1000000;

	unique_ptr<RandomBase> generator = make_unique<AntiThetic>(make_unique<RandomParkMiller>(1));
	MonteCarloService monteCarloService(generator);
	
	monteCarloService.Run(callOption, spot, vol, discountRate, numberOfPaths, callOptionStats);
	monteCarloService.Run(putOption, spot, vol, discountRate, numberOfPaths, putOptionStats);
	monteCarloService.Run(digitalCallOption, spot, vol, discountRate, numberOfPaths, digitalCallOptionStats);
	monteCarloService.Run(digitalPutOption, spot, vol, discountRate, numberOfPaths, digitalPutOptionStats);
	monteCarloService.Run(doubleDigitalOption,  spot, vol, discountRate, numberOfPaths, doubleDigitalOptionStats);

	cout << "The call option results:" << endl << callOptionStats.GetResultTable() << endl << endl;

	cout << "The call price is:           " << callOptionStats.GetResultsSoFar() << endl;
	cout << "The put price is:            " << putOptionStats.GetResultsSoFar() << endl;
	cout << "The digital call price is:   " << digitalCallOptionStats.GetResultsSoFar() << endl;
	cout << "The digital put price is:    " << digitalPutOptionStats.GetResultsSoFar() << endl;
	cout << "The double digital price is: " << doubleDigitalOptionStats.GetResultsSoFar() << endl;
}


void testAntiTheticConvergence()
{
	unsigned long numberOfPaths = 1000000;
	double expiry = 1.0, strike = 85.0, spot = 80.0;
	ParameterConstant vol(0.05), discountRate(0.05);
	
	Option callOption(make_unique<PayOffCall>(strike), expiry);

	ConvergenceTableGatherer gatherer(make_unique<MeanGatherer>());
	unique_ptr<RandomBase> generator = make_unique<RandomParkMiller>(1);
	MonteCarloService service(generator);
	service.Run(callOption, spot, vol, discountRate, numberOfPaths, gatherer);

	cout << "Normal sampling:" << endl << gatherer.GetResultTable() << endl;

	ConvergenceTableGatherer antiTheticGatherer(make_unique<MeanGatherer>());
	unique_ptr<RandomBase> antiTheticGenerator = make_unique<AntiThetic>(make_unique<RandomParkMiller>(1));
	service.SetGenerator(antiTheticGenerator);
	service.Run(callOption, spot, vol, discountRate, numberOfPaths, antiTheticGatherer);

	cout << "AntiThetic sampling:" << endl << antiTheticGatherer.GetResultTable() << endl;
}


int main()
{
	//runMontaCarlo();
	testAntiTheticConvergence();
}