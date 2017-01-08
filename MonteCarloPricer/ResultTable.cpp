#include "stdafx.h"
#include "ResultTable.h"


using namespace std;


ResultTable::ResultTable()
	: results()
{}


ostream& operator<<(ostream& os, const ResultTable& results)
{
	for (auto i = 0; i < results.Count(); i++)
	{
		os << results[i] << endl;
	}

	return os;
}