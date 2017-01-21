#include "stdafx.h"
#include "MeanGatherer.h"
#include "MeanResult.h"
#include <memory>


using namespace std;


namespace Pricer {
	namespace Statistics {

		MeanGatherer::MeanGatherer()
			: runningSum(0.0), pathsDone(0UL)
		{}


		MeanGatherer* MeanGatherer::Clone() const
		{
			return new MeanGatherer(*this);
		}


		void MeanGatherer::DumpOneResult(double result)
		{
			pathsDone++;
			runningSum += result;
		}


		ResultSet MeanGatherer::GetResultsSoFar() const
		{
			ResultSet results;

			shared_ptr<StatisticResult> result{ new MeanResult(runningSum / pathsDone) };

			results.Append(result);

			return results;
		}


		void MeanGatherer::Reset()
		{
			runningSum = 0.0;
			pathsDone = 0UL;
		}
	}
}