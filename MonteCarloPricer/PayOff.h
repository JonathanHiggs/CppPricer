#pragma once


namespace Pricer {
	namespace Instrument {
		class PayOff
		{
		public:
			PayOff() {};
			virtual double operator()(double spot) const = 0;
			virtual ~PayOff() {};

			virtual PayOff* clone() const = 0;
		};


		class PayOffCall : public PayOff
		{
		public:
			PayOffCall(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffCall() {};

			virtual PayOffCall* clone() const;

		private:
			double strike;
		};


		class PayOffPut : public PayOff
		{
		public:
			PayOffPut(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffPut() {};

			virtual PayOffPut* clone() const;

		private:
			double Strike;
		};


		class PayOffDigitalCall : public PayOff
		{
		public:
			PayOffDigitalCall(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffDigitalCall() {};

			virtual PayOffDigitalCall* clone() const;

		private:
			double Strike;
		};


		class PayOffDigitalPut : public PayOff
		{
		public:
			PayOffDigitalPut(double strike);
			virtual double operator() (double spot) const;
			virtual ~PayOffDigitalPut() {};

			virtual PayOffDigitalPut* clone() const;

		private:
			double Strike;
		};


		class PayOffDoubleDigital : public PayOff
		{
		public:
			PayOffDoubleDigital(double lowerLevel, double upperLevel);
			virtual double operator() (double spot) const;
			virtual ~PayOffDoubleDigital() {};

			virtual PayOffDoubleDigital* clone() const;

		private:
			double LowerLevel;
			double UpperLevel;
		};
	}
}