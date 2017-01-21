#include "stdafx.h"
#include "PathDependent.h"


using namespace std;
using namespace Pricer::Instrument;


PathDependent::PathDependent(const vector<double>& lookAtTimes)
	: lookAtTimes(lookAtTimes)
{}


const vector<double>& PathDependent::LookAtTimes() const
{
	return lookAtTimes;
}