#pragma once


namespace Pricer {
	namespace Util {

		class StandardNormalDistribution {
		public:
			static double ProbabilityDensity(const double& x);
			static double CumulativeDensity(const double& x);

			static double InverseCumulativeDensity(const double& quartile);
		};
	}
}