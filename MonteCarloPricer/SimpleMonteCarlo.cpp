#include "stdafx.h"
#include "Random.h"
#include "PayOff.h"
#include "Option.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif


double SimpleMonteCarlo(
	const VanillaOption& option,
	double spot,
	double vol,
	double discountRate,
	unsigned long numberOfPaths)
{
	double variance = vol * vol * option.GetExpiry();
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = spot * exp(discountRate * option.GetExpiry() * itoCorrection);
	double thisSpot, thisGaussian, thisPayOff;
	double runningSum = 0.0;

	for (unsigned long i = 0; i < numberOfPaths; i++)
	{
		thisGaussian = getOneGaussianByBoxMiller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		thisPayOff = option.OptionPayOff(thisSpot);
		runningSum += thisPayOff;
	}

	double mean = runningSum / numberOfPaths;
	mean *= exp(-discountRate * option.GetExpiry());
	return mean;
}