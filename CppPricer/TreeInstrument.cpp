#include "stdafx.h"
#include "TreeInstrument.h"


namespace Pricer {
	namespace Instrument {

		TreeInstrument::TreeInstrument(double finalTime)
			: finalTime(finalTime)
		{}


		double TreeInstrument::GetFinalTime() const
		{
			return finalTime;
		}
	}
}