#include "stdafx.h"
#include "StatisticsGatherer.h"


using namespace std;


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