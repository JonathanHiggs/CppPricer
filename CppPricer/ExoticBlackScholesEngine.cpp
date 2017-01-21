#include "stdafx.h"
#include "ExoticBlackScholesEngine.h"
#include <cmath>


using namespace std;
using namespace Pricer::Instrument;
using namespace Pricer::Parameters;
using namespace Pricer::Statistics;
using namespace Pricer::Util;


namespace Pricer {
	namespace Service {

		ExoticBlackScholesEngine::ExoticBlackScholesEngine(
			unique_ptr<PathDependent>& product,
			shared_ptr<Parameter> r,
			shared_ptr<Parameter> d,
			shared_ptr<Parameter> vol,
			unique_ptr<RandomBase>& generator,
			double spot
		)
			: ExoticEngine(product, r), generator(move(generator))
		{
			vector<double> times(this->Product()->LookAtTimes());
			numberOfTimes = times.size();

			this->generator->ResetDimensionality(numberOfTimes);
			drifts.resize(numberOfTimes);
			standardDeviations.resize(numberOfTimes);

			double variance = vol->IntegralSquare(0.0, times[0]);

			drifts[0] = r->IntegralSquare(0.0, times[0]) - d->IntegralSquare(0.0, times[0]) - 0.5 * variance;
			standardDeviations[0] = sqrt(variance);

			for (unsigned long j = 1; j < numberOfTimes; ++j)
			{
				double thisVariance = vol->IntegralSquare(times[j - 1], times[j]);
				drifts[j] = r->IntegralSquare(times[j - 1], times[j]) - d->IntegralSquare(times[j - 1], times[j]) - 0.5 * thisVariance;
				standardDeviations[j] = sqrt(thisVariance);
			}

			logSpot = log(spot);
			variates.resize(numberOfTimes);
		}


		void ExoticBlackScholesEngine::GetOnePath(vector<double>& spotValues)
		{
			generator->GetGaussians(variates);

			double currentLogSpot = logSpot;

			for (unsigned long j = 0; j < numberOfTimes; j++)
			{
				currentLogSpot += drifts[j];
				currentLogSpot += standardDeviations[j] * variates[j];
				spotValues[j] = exp(currentLogSpot);
			}
		}
	}
}