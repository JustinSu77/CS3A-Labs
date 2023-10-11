/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: main.cpp for Problem #2 of Lab #11
**/
#include "Rational.h"

int main()
{
	int n1, d1, n2, d2;
	cout << "Enter numerator and denominator for Rational r1 : ";
	cin >> n1 >> d1;
	Rational r1(n1, d1);

	cout << "Enter numerator and denominator for Rational r2 : ";
	cin >> n2 >> d2;
	Rational r2(n2, d2);

	Rational add = addition(r1, r2);
	Rational sub = subtract(r1, r2);
	Rational mul = multiply(r1, r2);
	Rational div = divide(r1, r2);

	cout << "r1  = " << r1.getNumerator() << " / " << r1.getDenominator() << endl;
	cout << "r2  = " << r2.getNumerator() << " / " << r2.getDenominator() << endl;
	cout << "add = " << add.getNumerator() << " / " << add.getDenominator() << endl;
	cout << "sub = " << sub.getNumerator() << " / " << sub.getDenominator() << endl;
	cout << "mul = " << mul.getNumerator() << " / " << mul.getDenominator() << endl;
	cout << "div = " << div.getNumerator() << " / " << div.getDenominator() << endl;
	
}