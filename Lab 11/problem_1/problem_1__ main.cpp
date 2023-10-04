/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: main.ccp for Problem #1 of Lab #11
**/
#include "Complex.h"
 
int main()
{
	double r1, r2, i1, i2;
	cout << "Enter real and imaginary for Complex c1 : ";
	cin >> r1 >> i1;
	Complex c1(r1, i1);
	
	cout << "Enter real and imaginary for Complex c2 : ";
	cin >> r2 >> i2;
	Complex c2(r2, i2);

	Complex add = addition(c1, c2);
	Complex sub = subtraction(c1, c2);
	Complex mul = multiplication(c1, c2);
	
	cout << "c1  = (" << c1.getReal() << ", " << c1.getImaginary() << ")" << endl;
	cout << "c2  = (" << c2.getReal() << ", " << c2.getImaginary() << ")" << endl;
	cout << "add = (" << add.getReal() << ", " << add.getImaginary() << ")" << endl;
	cout << "sub = (" << sub.getReal() << ", " << sub.getImaginary() << ")" << endl;
	cout << "mul = (" << mul.getReal() << ", " << mul.getImaginary() << ")" << endl;
	
}