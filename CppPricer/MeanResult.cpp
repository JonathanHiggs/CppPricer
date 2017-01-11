#include "stdafx.h"
#include "MeanResult.h"


using namespace std;


namespace Pricer {
	namespace Statistics {
		MeanResult::MeanResult(double mean)
			: mean(mean)
		{}


		void MeanResult::Serialize(ostream& os) const
		{
			os << mean;
		}
	}
}