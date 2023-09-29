/**
	Date: 9/28/2023
	By: Justin Su
	Purpose: Problem #2 of Lab #2
**/

#include "rational.h"
#include <iostream>
using namespace std;

int main()
{
	int numerator, denominator;
	cout << "Enter rational for r1 : ";
	cin >> numerator >> denominator;
	Rational r1(numerator, denominator);

	cout << "Enter rational for r2 : ";
	cin >> numerator >> denominator;
	Rational r2(numerator, denominator);


	Rational r3 = r1.add(r2);
	Rational r4 = r1.subtract(r2);
	Rational r5 = r1.multiply(r2);
	Rational r6 = r1.divide(r2);

	cout << "r1 + r2 = "; r3.print();
	cout << "r2 - r2 = "; r4.print();
	cout << "r1 * r2 = "; r5.print();
	cout << "r1 / r2 = "; r6.print();
	
	return 0;
}