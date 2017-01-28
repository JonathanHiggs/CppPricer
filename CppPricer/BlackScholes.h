#pragma once


namespace Pricer {
	namespace Models {

		class BlackScholes
		{
		public:
			static double Call(double spot, double strike, double drift, double discount, double vol, double timeToExpiry);
			static double Put(double spot, double strike, double drift, double discount, double vol, double timeToExpiry);
			static double DigitalCall(double spot, double strike, double drift, double discount, double vol, double timeToExpiry);
			static double CallVega(double spot, double strike, double drift, double discount, double vol, double timeToExpiry);
		};
	}
}