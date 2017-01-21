#pragma once


namespace Pricer {
	namespace Instrument {

		class TreeInstrument
		{
		public:
			TreeInstrument(double finalTime);

			virtual TreeInstrument* Clone() const = 0;
			double GetFinalTime() const;
			virtual double FinalPayOff(double spot) const = 0;
			virtual double PreFinalValue(double spot, double time, double discountedFutureValue) const = 0;

			virtual ~TreeInstrument() {};

		private:
			double finalTime;
		};
	}
}