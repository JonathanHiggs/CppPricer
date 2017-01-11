#include "stdafx.h"
#include "StatisticsResult.h"


using namespace std;


namespace Pricer {
	namespace Statistics {
		ostream& operator << (ostream& os, const StatisticResult& result)
		{
			result.Serialize(os);
			return os;
		}


		ostream& operator << (ostream& os, const StatisticResult* result)
		{
			result->Serialize(os);
			return os;
		}
	}
}