#pragma once


#include "Parameter.h"
#include "PathDependent.h"
#include "StatisticsGatherer.h"
#include <memory>
#include <vector>


namespace Pricer {
	namespace Service {

		class ExoticEngine
		{
		public:
			ExoticEngine(std::unique_ptr<Instrument::PathDependent>& product, std::shared_ptr<Parameters::Parameter> r);

			double DoOnePath(const std::vector<double> spotValues) const;
			virtual void GetOnePath(std::vector<double>& spotValues) = 0;
			//std::vector<double> LookAtTimes() const;
			void Run(Statistics::StatisticsGatherer& gatherer, unsigned long numberOfPaths);
			const std::unique_ptr<Instrument::PathDependent>& Product() const;
			virtual ~ExoticEngine() {};

		private:
			std::unique_ptr<Instrument::PathDependent> product;
			std::shared_ptr<Parameters::Parameter> r;
			std::vector<double> discounts;
			mutable std::vector<Instrument::Cashflow> theseCashflows;
		};
	}
}