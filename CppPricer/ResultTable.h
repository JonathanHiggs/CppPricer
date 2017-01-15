#pragma once


#include "ResultSet.h"
#include <iostream>
#include <memory>
#include <vector>


namespace Pricer {
	namespace Statistics {

		class ResultTable
		{
		public:
			ResultTable();

			inline void Append(ResultSet result) { results.push_back(result); };
			inline size_t Count() const { return results.size(); };
			inline ResultSet operator[](size_t index) const { return results[index]; };
			friend std::ostream& operator<<(std::ostream& os, const ResultTable& results);

		private:
			std::vector<ResultSet> results;
		};
	}
}