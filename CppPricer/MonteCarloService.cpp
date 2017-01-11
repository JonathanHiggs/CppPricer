#include "stdafx.h"
#include "MonteCarloService.h"
#include "Random.h"
#include <cmath>


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Parameters;
using namespace Pricer::Statistics;
using namespace Pricer::Util;


namespace Pricer {
	namespace Service {
		MonteCarloService::MonteCarloService()
		{}


		void MonteCarloService::Run(
			const VanillaOption& option,
			double spot,
			const Parameter& volatility,
			const Parameter& discountRate,
			unsigned long numberOfPaths,
			StatisticsGatherer& gatherer
		) const
		{
			double expiry = option.GetExpiry();
			double variance = volatility.IntegralSquare(0, expiry);
			double rootVariance = sqrt(variance);
			double itoCorrection = -0.5 * variance;

			double movedSpot = spot * exp(discountRate.Integral(0, expiry) + itoCorrection);
			double discount = exp(-discountRate.Integral(0, expiry));
			double thisSpot, thisGausian, thisPayOff;

			for (auto i = 0; i < numberOfPaths; i++)
			{
				thisGausian = getOneGaussianByBoxMiller();
				thisSpot = movedSpot * exp(rootVariance * thisGausian);
				thisPayOff = option.OptionPayOff(thisSpot);
				gatherer.DumpOneResult(thisPayOff * discount);
			}
		}
	}
}