#pragma once


#include "StatisticsResult.h"
#include <iostream>
#include <memory>
#include <vector>


namespace Pricer {
	namespace Statistics {
		class ResultSet
		{
		public:
			ResultSet();
			ResultSet(size_t size);

			inline void Append(std::shared_ptr<StatisticResult> result) { results.push_back(result); };
			inline size_t Count() const { return results.size(); };
			inline std::shared_ptr<StatisticResult> operator[](size_t index) const { return results[index]; };
			friend std::ostream& operator<<(std::ostream& os, const ResultSet& results);

		private:
			std::vector<std::shared_ptr<StatisticResult>> results;
		};
	}
}