#include "stdafx.h"
#include "ConvergenceTable.h"


using namespace std;


ConvergenceTable::ConvergenceTable(Statistics& inner)
	: inner(inner.clone()), stoppingPoint(2), pathsDone(0UL)
{}


ConvergenceTable::ConvergenceTable(unique_ptr<Statistics> inner)
	: inner(move(inner)), stoppingPoint(2), pathsDone(0UL)
{}


void ConvergenceTable::DumpOneResult(double result)
{
	inner->DumpOneResult(result);
	pathsDone++;

	if (pathsDone == stoppingPoint)
	{
		stoppingPoint *= 2;
		vector<vector<double>> thisResult(inner->GetResultsSoFar());

		for (auto i = 0; i < thisResult.size(); i++)
		{
			thisResult[i].push_back(pathsDone);
			resultsSoFar.push_back(thisResult[i]);
		}
	}
}


vector<vector<double>> ConvergenceTable::GetResultsSoFar() const
{
	vector<vector<double>> tmp(resultsSoFar);

	if (pathsDone * 2 != stoppingPoint)
	{
		vector<vector<double>> thisResult(inner->GetResultsSoFar());

		for (auto i = 0; i < thisResult.size(); i++)
		{
			thisResult[i].push_back(pathsDone);
			tmp.push_back(thisResult[i]);
		}
	}

	return tmp;
}


unique_ptr<Statistics> ConvergenceTable::clone() const
{
	return unique_ptr<Statistics>(new ConvergenceTable(inner->clone()));
}