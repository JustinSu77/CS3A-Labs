#pragma once
#include <iostream>
using namespace std;
class Complex
{
public:
	Complex();
	Complex(double, double);

	Complex addition(Complex&);
	Complex subtraction(Complex&);
	Complex multiplication(Complex&);

	double getReal() { return real; }
	double getImaginary() { return imaginary; }
	void print();
private:
	double real;
	double imaginary;
};

