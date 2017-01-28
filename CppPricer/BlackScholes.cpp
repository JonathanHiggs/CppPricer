#include "stdafx.h"
#include "BlackScholes.h"
#include "StandardNormalDistribution.h"
#include <cmath>


using namespace Pricer::Util;


namespace Pricer {
	namespace Models {

		double BlackScholes::Call(double spot, double strike, double drift, double discount, double vol, double timeToExpiry)
		{
			double standardDeviation = vol * sqrt(timeToExpiry);
			double moneyness = log(spot / strike);
			double d1 = (moneyness + (drift - discount) * timeToExpiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
			double d2 = d1 - standardDeviation;
			return spot * exp(-drift * timeToExpiry) * StandardNormalDistribution::CumulativeDensity(d1) - strike * exp(-discount * timeToExpiry) * StandardNormalDistribution::CumulativeDensity(d2);
		}


		double BlackScholes::Put(double spot, double strike, double drift, double discount, double vol, double timeToExpiry)
		{
			double standardDeviation = vol * sqrt(timeToExpiry);
			double moneyness = log(spot / strike);
			double d1 = (moneyness + (drift - discount) * timeToExpiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
			double d2 = d1 - standardDeviation;
			return spot * exp(-discount * timeToExpiry) * (1.0 - StandardNormalDistribution::CumulativeDensity(d2)) - spot * exp(-drift * timeToExpiry) * (1.0 - StandardNormalDistribution::CumulativeDensity(d1));
		}


		double BlackScholes::DigitalCall(double spot, double strike, double drift, double discount, double vol, double timeToExpiry)
		{
			double standardDeviation = vol * sqrt(timeToExpiry);
			double moneyness = log(spot / strike);
			double d2 = (moneyness + (drift - discount) * timeToExpiry - 0.5 * standardDeviation * standardDeviation) / standardDeviation;
			return exp(-discount * timeToExpiry) * StandardNormalDistribution::CumulativeDensity(d2);
		}


		double BlackScholes::CallVega(double spot, double strike, double drift, double discount, double vol, double timeToExpiry)
		{
			double standardDeviation = vol * sqrt(timeToExpiry);
			double moneyness = log(spot / strike);
			double d1 = (moneyness + (drift - discount) * timeToExpiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
			return spot * exp(-discount * timeToExpiry) * sqrt(timeToExpiry) * StandardNormalDistribution::ProbabilityDensity(d1);
		}
	}
}