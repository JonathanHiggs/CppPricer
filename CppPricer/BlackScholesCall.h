#pragma once


namespace Pricer {
	namespace Models {

		class BlackScholesCall
		{
		public:
			BlackScholesCall(double discount, double drift, double timeToExpiry, double spot, double strike);

			double Price(double vol) const;
			double Vega(double vol) const;

		private:
			double discount;
			double drift;
			double timeToExpiry;
			double spot;
			double strike;
		};
	}
}