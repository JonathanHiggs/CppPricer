#include "stdafx.h"
#include "Random.h"
#include "PayOff.h"
#include "Option.h"
#include "Parameter.h"
#include "Statistics.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif


void SimpleMonteCarlo(
	const VanillaOption& option,
	double spot,
	const Parameter& vol,
	const Parameter& discountRate,
	unsigned long numberOfPaths,
	Statistics& gatherer)
{
	double expiry = option.GetExpiry();
	double variance = vol.IntegralSquare(0, expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = spot * exp(discountRate.Integral(0, expiry) + itoCorrection);
	double discount = exp(-discountRate.Integral(0, expiry));
	double thisSpot, thisGaussian, thisPayOff;

	for (unsigned long i = 0; i < numberOfPaths; i++)
	{
		thisGaussian = getOneGaussianByBoxMiller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		thisPayOff = option.OptionPayOff(thisSpot);
		gatherer.DumpOneResult(thisPayOff * discount);
	}

	return;
}