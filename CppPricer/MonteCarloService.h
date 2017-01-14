#pragma once


#include "Option.h"
#include "Parameter.h"
#include "Random.h"
#include "StatisticsGatherer.h"
#include <memory>


namespace Pricer {
	namespace Service {
		class MonteCarloService
		{
		public:
			MonteCarloService(std::unique_ptr<Util::RandomBase>& generator);

			void Run(
				const Pricer::Instrument::VanillaOption& option,
				double spot,
				const Pricer::Parameters::Parameter& volatility,
				const Pricer::Parameters::Parameter& discountRate,
				unsigned long numberOfPaths,
				Pricer::Statistics::StatisticsGatherer& statisticsGatherer
			) const;

		private:
			std::unique_ptr<Util::RandomBase> generator;
		};
	}
}