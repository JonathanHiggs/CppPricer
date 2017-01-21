#include "stdafx.h"
#include "MonteCarloService.h"
#include <cmath>
#include <memory>


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Parameters;
using namespace Pricer::Statistics;
using namespace Pricer::Util;


namespace Pricer {
	namespace Service {

		MonteCarloService::MonteCarloService(unique_ptr<RandomBase>& generator)
			: generator(move(generator))
		{}

		void MonteCarloService::SetGenerator(unique_ptr<RandomBase>& newGenerator)
		{
			generator.release();
			generator = move(newGenerator);
		}

		void MonteCarloService::Run(
			const VanillaOption& option,
			double spot,
			const Parameter& volatility,
			const Parameter& discountRate,
			unsigned long numberOfPaths,
			StatisticsGatherer& gatherer
		) const
		{
			generator->ResetDimensionality(1);

			double expiry = option.GetExpiry();
			double variance = volatility.IntegralSquare(0, expiry);
			double rootVariance = sqrt(variance);
			double itoCorrection = -0.5 * variance;

			double movedSpot = spot * exp(discountRate.Integral(0, expiry) + itoCorrection);
			double discount = exp(-discountRate.Integral(0, expiry));
			double thisSpot, thisPayOff;
			vector<double> variate(1);

			for (unsigned long i = 0; i < numberOfPaths; i++)
			{
				generator->GetGaussians(variate);
				thisSpot = movedSpot * exp(rootVariance * variate[0]);
				thisPayOff = option.GetPayOff(thisSpot);
				gatherer.DumpOneResult(thisPayOff * discount);
			}
		}
	}
}