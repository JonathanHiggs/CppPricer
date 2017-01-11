#pragma once


#include "Option.h"
#include "Parameter.h"
#include "StatisticsGatherer.h"


namespace Pricer {
	namespace Service {
		class MonteCarloService
		{
		public:
			MonteCarloService();

			void Run(
				const Pricer::Instrument::VanillaOption& option,
				double spot,
				const Pricer::Parameters::Parameter& volatility,
				const Pricer::Parameters::Parameter& discountRate,
				unsigned long numberOfPaths,
				Pricer::Statistics::StatisticsGatherer& statisticsGatherer
			) const;
		};
	}
}