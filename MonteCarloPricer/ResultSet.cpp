#include "stdafx.h"
#include "ResultSet.h"


using namespace std;


namespace Pricer {
	namespace Statistics {
		ResultSet::ResultSet()
			: results()
		{}


		ResultSet::ResultSet(size_t size)
			: results(size)
		{}


		ostream& operator<<(ostream& os, const ResultSet& results)
		{
			for (auto i = 0; i < results.Count(); i++)
			{
				os << results[i] << "\t";
			}

			return os;
		}
	}
}