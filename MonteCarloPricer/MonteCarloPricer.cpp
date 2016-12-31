// MonteCarloPricer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.h"
#include <iostream>
#include <cmath>
#include <string>


using namespace std;

double simpleMonteCarlo(
	double expiry,
	double strike,
	double spot,
	double vol,
	double discountRate,
	unsigned long numberOfPaths)
{
	double variance = vol * vol * expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = spot * exp(discountRate * expiry * itoCorrection);
	double thisSpot, thisPayoff, thisGaussian;
	double runningSum = 0.0;

	for (unsigned long i = 0; i < numberOfPaths; i++)
	{
		thisGaussian = getOneGaussianByBoxMiller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		thisPayoff = thisSpot - strike;
		thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
		runningSum += thisPayoff;
	}

	double mean = runningSum / numberOfPaths;
	mean *= exp(-discountRate * expiry);
	return mean;
}

int main()
{
	double expiry = 1;
	double strike = 85;
	double spot = 80;
	double vol = 0.05;
	double discountRate = 0.05;
	unsigned long numberOfPaths = 10000;

	double result = simpleMonteCarlo(expiry, strike, spot, vol, discountRate, numberOfPaths);

	cout << "The price is: " << result;

	string tmp;
	cin >> tmp;

	return 0;
}

