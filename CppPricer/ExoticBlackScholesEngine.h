#pragma once


#include "ExoticEngine.h"
#include "Random.h"
#include <vector>


namespace Pricer {
	namespace Service {

		class ExoticBlackScholesEngine : public ExoticEngine
		{
		public:
			ExoticBlackScholesEngine(
				std::unique_ptr<Instrument::PathDependent>& product,
				std::shared_ptr<Parameters::Parameter> r,
				std::shared_ptr<Parameters::Parameter> d,
				std::shared_ptr<Parameters::Parameter> vol,
				std::unique_ptr<Util::RandomBase>& generator,
				double spot
			);

			virtual void GetOnePath(std::vector<double>& spotValues);
			virtual ~ExoticBlackScholesEngine() {};

		private:
			std::unique_ptr<Util::RandomBase> generator;
			std::vector<double> drifts;
			std::vector<double> standardDeviations;
			double logSpot;
			unsigned long numberOfTimes;
			std::vector<double> variates;
		};
	}
}