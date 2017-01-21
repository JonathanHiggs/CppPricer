#pragma once


#include "VanillaOption.h"
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

			void SetGenerator(std::unique_ptr<Util::RandomBase>& generator);

			void Run(
				const Instrument::VanillaOption& option,
				double spot,
				const Parameters::Parameter& volatility,
				const Parameters::Parameter& discountRate,
				unsigned long numberOfPaths,
				Statistics::StatisticsGatherer& statisticsGatherer
			) const;

		private:
			std::unique_ptr<Util::RandomBase> generator;
		};
	}
}