#include "stdafx.h"
#include "Random.h"
#include "PayOff.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif


double SimpleMonteCarlo(
	const PayOff& payOff,
	double expiry,
	double spot,
	double vol,
	double discountRate,
	unsigned long numberOfPaths)
{
	double variance = vol * vol * expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = spot * exp(discountRate * expiry * itoCorrection);
	double thisSpot, thisGaussian, thisPayOff;
	double runningSum = 0.0;

	for (unsigned long i = 0; i < numberOfPaths; i++)
	{
		thisGaussian = getOneGaussianByBoxMiller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		thisPayOff = payOff(thisSpot);
		runningSum += thisPayOff;
	}

	double mean = runningSum / numberOfPaths;
	mean *= exp(-discountRate * expiry);
	return mean;
}