#pragma once


#include <iostream>


namespace Pricer {
	namespace Statistics {
		class StatisticResult
		{
		public:
			StatisticResult() {};

			virtual void Serialize(std::ostream& os) const = 0;
		};


		std::ostream& operator << (std::ostream& os, const StatisticResult& result);
		std::ostream& operator << (std::ostream& os, const StatisticResult* result);
	}
}