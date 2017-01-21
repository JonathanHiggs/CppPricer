#pragma once


#include "Parameter.h"
#include "TreeInstrument.h"
#include <memory>
#include <vector>


namespace Pricer {
	namespace Tree {

		class BinomialTree
		{
		public:
			BinomialTree(
				double spot,
				std::unique_ptr<Parameters::Parameter>& r,
				std::unique_ptr<Parameters::Parameter>& d,
				double volatility,
				unsigned long steps,
				double time
			);

			double Price(std::unique_ptr<Instrument::TreeInstrument>& option);

		protected:
			void BuildTree();

		private:
			double spot;
			std::unique_ptr<Parameters::Parameter> r;
			std::unique_ptr<Parameters::Parameter> d;
			double volatility;
			unsigned long steps;
			double time;
			bool treeBuilt;

			std::vector<std::vector<std::pair<double, double>>> tree;
			std::vector<double> discounts;
		};
	}
}