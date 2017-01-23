#include "stdafx.h"
#include "BlackScholes.h"
#include "Normals.h"
#include <cmath>


using namespace Pricer::Util;


namespace Pricer {
	namespace Models {

		double BlackScholes::Call(double spot, double strike, double drift, double discount, double vol, double timeToExpiry)
		{
			double standardDeviation = vol * sqrt(timeToExpiry);
			double moneyness = log(spot / strike);
			double d1 = (moneyness + (drift - discount) * timeToExpiry + 0.5 * standardDeviation * standardDeviation) / standardDeviation;
			double d2 = d1 - standardDeviation;
			return spot * exp(-drift * timeToExpiry) * CumulativeNormal(d1) - strike * exp(-discount * timeToExpiry) * CumulativeNormal(d2);
		}
	}
}