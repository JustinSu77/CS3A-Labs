#pragma once
class Rational
{
	public:
		Rational();
		Rational(int, int);
		Rational add(const Rational&);
		Rational subtract(const Rational&);
		Rational multiply(const Rational&);
		Rational divide(const Rational&);
		void print();
	private:
		int numerator;
		int denominator;
		void reduce(); // make 2/4 --> 1/2 (reduce function is used only in the class
};

