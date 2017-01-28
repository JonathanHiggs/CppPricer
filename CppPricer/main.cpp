// main.cpp : Defines the entry point for the console application.


#include "stdafx.h"

#include "AntiThetic.h"
#include "BinomialTree.h"
#include "Bisection.h"
#include "BlackScholesCall.h"
#include "ConvergenceTableGatherer.h"
#include "ExoticBlackScholesEngine.h"
#include "MeanGatherer.h"
#include "MonteCarloService.h"
#include "NewtonRaphson.h"
#include "VanillaOption.h"
#include "Parameter.h"
#include "ParameterConstant.h"
#include "PathDependentAsian.h"
#include "PayOff.h"
#include "PayOffCall.h"
#include "PayOffPut.h"
#include "PayOffDigitalCall.h"
#include "PayOffDigitalPut.h"
#include "PayOffDoubleDigital.h"
#include "RandomParkMiller.h"
#include "StatisticsGatherer.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "TreeInstrument.h"

#include <iostream>
#include <string>
#include <memory>


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Models;
using namespace Pricer::Parameters;
using namespace Pricer::Service;
using namespace Pricer::Solvers;
using namespace Pricer::Statistics;
using namespace Pricer::Tree;
using namespace Pricer::Util;


void testMontaCarlo()
{
	double expiry = 1.0;
	double strike = 85;

	ConvergenceTableGatherer callOptionStats(make_unique<MeanGatherer>(), 100000);
	VanillaOption callOption(make_unique<PayOffCall>(strike), expiry);

	MeanGatherer putOptionStats;
	VanillaOption putOption(make_unique<PayOffPut>(strike), expiry);

	MeanGatherer digitalCallOptionStats;
	VanillaOption digitalCallOption(make_unique<PayOffDigitalCall>(strike), expiry);
	
	MeanGatherer digitalPutOptionStats;
	VanillaOption digitalPutOption(make_unique<PayOffDigitalPut>(strike), expiry);
	
	MeanGatherer doubleDigitalOptionStats;
	VanillaOption doubleDigitalOption(make_unique<PayOffDoubleDigital>(82.0, 85.0), expiry);
	
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


void testConvergence()
{
	unsigned long numberOfPaths = 100000;
	double expiry = 1.0, strike = 85.0, spot = 80.0;
	ParameterConstant vol(0.05), discountRate(0.05);
	
	VanillaOption callOption(make_unique<PayOffCall>(strike), expiry);

	// Regular sampling
	ConvergenceTableGatherer gatherer(make_unique<MeanGatherer>(), 10000);
	unique_ptr<RandomBase> generator = make_unique<RandomParkMiller>(1);
	MonteCarloService service(generator);
	service.Run(callOption, spot, vol, discountRate, numberOfPaths, gatherer);

	cout << "Normal sampling:" << endl << gatherer.GetResultTable() << endl;

	// AntiThetic sampling
	ConvergenceTableGatherer antiTheticGatherer(make_unique<MeanGatherer>(), 10000);
	unique_ptr<RandomBase> antiTheticGenerator = make_unique<AntiThetic>(make_unique<RandomParkMiller>(1));
	service.SetGenerator(antiTheticGenerator);
	service.Run(callOption, spot, vol, discountRate, numberOfPaths, antiTheticGatherer);

	cout << "AntiThetic sampling:" << endl << antiTheticGatherer.GetResultTable() << endl;
}


void testPathDependent()
{
	double expiry = 2.5;
	double strike = 82.0;
	double spot = 80.0;
	unsigned long numberOfPaths = 10000;
	unsigned long numberOfDates = 5;

	shared_ptr<Parameter> vol = make_shared<ParameterConstant>(0.05);
	shared_ptr<Parameter> r = make_shared<ParameterConstant>(0.05);
	shared_ptr<Parameter> d = make_shared<ParameterConstant>(0.03);

	vector<double> times(numberOfDates);
	for (unsigned long i = 0; i < numberOfDates; i++)
		times[i] = (i + 1.0) * expiry / numberOfDates;

	unique_ptr<PathDependent> option = make_unique<PathDepenentAsian>(times, expiry, make_unique<PayOffCall>(strike));

	ConvergenceTableGatherer gatherer(make_unique<MeanGatherer>(), 1000);
	unique_ptr<RandomBase> generator = make_unique<AntiThetic>(make_unique<RandomParkMiller>(1));

	ExoticBlackScholesEngine engine(option, r, d, vol, generator, spot);

	engine.Run(gatherer, numberOfPaths);

	cout << "Path Dependent Asia:" << endl << gatherer.GetResultTable() << endl;
}


void testBinomialTree()
{
	unsigned long steps = 14;
	double expiry = 2.5, strike = 90.0, spot = 87.0, vol = 0.075;

	unique_ptr<Parameter> r = make_unique<ParameterConstant>(0.05);
	unique_ptr<Parameter> d = make_unique<ParameterConstant>(0.02);

	unique_ptr<TreeInstrument> europeanOption = make_unique<TreeEuropean>(expiry, make_unique<PayOffCall>(strike));
	unique_ptr<TreeInstrument> americanOption = make_unique<TreeAmerican>(expiry, make_unique<PayOffCall>(strike));

	BinomialTree tree(spot, r, d, vol, steps, expiry);

	double europeanPrice = tree.Price(europeanOption);
	double americanPrice = tree.Price(americanOption);

	cout << "European price: " << europeanPrice << endl;
	cout << "American price: " << americanPrice << endl;
}


void testSovlers()
{
	double discount = 0.05;
	double drift = 0.05;
	double timeToExpiry = 1.0;
	double spot = 80;
	double strike = 85;
	double price = 0.5465;

	BlackScholesCall call(discount, drift, timeToExpiry, spot, strike);
	double vol = NewtonRaphson<BlackScholesCall, &BlackScholesCall::Price, &BlackScholesCall::Vega>(price, 0.5, 0.00001, call);

	cout << "The vol: " << vol << endl;
}


int main()
{
	//testMontaCarlo();
	//testConvergence();
	//testPathDependent();
	//testBinomialTree();
	testSovlers();
}