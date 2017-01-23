#pragma once


namespace Pricer {
	namespace Models {

		class BlackScholes
		{
		public:
			static double Call(double spot, double strike, double drift, double discount, double vol, double timeToExpiry);
		};
	}
}