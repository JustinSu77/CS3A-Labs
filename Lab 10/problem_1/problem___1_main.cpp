/**
	Date: 9/28/2023
	By: Justin Su
	Purpose: main.cpp for Problem #1 of Lab #10
**/
 
#include "complex.h"

int main()
{
	// Declare and initialize variables used in creating the objects
	double real = 0;
	double imaginary = 0;
	// Prompt user to enter the variables
	cout << "Enter real and imaginary number for c1 : ";
	// Store user inputs into the variables
	cin >> real >> imaginary;
	// Create first object with given variables
	Complex c1(real, imaginary);
	// Prompt user to enter the variables again
	cout << "Enter real and imaginary number for c2 : ";
	// Store user inputs into the variables again
	cin >> real >> imaginary;
	// Create second object with given variables
	Complex c2(real, imaginary);
	// Output newline to terminal for readability
	cout << endl;
	// Output first complex object like a complex number
	cout << "c1 = ";
	c1.print();
	// Output first complex object like a comple number
	cout << "c2 = ";
	c2.print();
	// Output newline to terminal for readability
	cout << endl;
	// Create and set sum object
	Complex sum = c1.addition(c2);
	// Output sum object
	cout << "Sum            : ";
	sum.print();
	// Create difference object
	Complex difference = c1.subtraction(c2);
	// Output difference object
	cout << "Subtraction    : ";
	difference.print();
	// Create product object
	Complex product = c1.multiplication(c2);
	// Output product object
	cout << "Multiplication : ";
	product.print();

	return 0;
}