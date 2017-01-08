#include "stdafx.h"
#include "MeanResult.h"


using namespace std;


MeanResult::MeanResult(double mean)
	: mean(mean)
{}


void MeanResult::Serialize(ostream& os) const
{
	os << mean;
}