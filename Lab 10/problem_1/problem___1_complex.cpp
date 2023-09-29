/**
	Date: 9/28/2023
	By: Justin Su
	Purpose: complex.cpp for Problem #1 of Lab #10
**/
#include "complex.h"
/**
	Default constructor.
	Precondition: Complex object is instantiated.
	Postcondition: Private member variable real is set to 0.
				   Private member variable imaginary is set to 0.
**/
Complex::Complex()
{
	// Set private member variables real and imaginary to 0
	real = 0;
	imaginary = 0;
}
/**
	Constructor with 2 variables.
	Precondition: Complex object is ininstantiated.
	Postcondition: Private member variable real is set to given newReal.
				   Private member variable imaginary is set to given newImaginary.
	newReal as value for real private member variable as double
	newImaginary as value for real private member variable as double
**/
Complex::Complex(double newReal, double newImaginary)
{
	// Set private member variable real to given newReal
	real = newReal;
	// Set private member variable imaginary to given newImaginary
	imaginary = newImaginary;
}

/**
	Returns a object of this class whose real and imaginary private member variables
	are the sums of the corresponding real and imaginary private member variables
	of the calling instance of this class and a given instance of this class.
	Precondition: Complex object is instantiated.
	Postcondition: Complex object that has each of its private member variables defined as the sum of
				   the corresponding private member variables of the calling instance of this
				   class and the given Complex object is returned.
	object as existing Complex object
	**/
Complex Complex::addition(Complex& object)
{
	// Add the real private member variables together and store it in a variable
	double realSum = real + object.getReal();
	// Add the imaginary private member variable together and store it in a variable
	double imaginarySum = imaginary + object.getImaginary();
	// Create Complex object using the variables above
	Complex result(realSum, imaginarySum);
	// Return the created Complex object
	return result;
}

/**
	Returns a object of this class whose real and imaginary private member variables
	are the differences of the corresponding real and imaginary private member variables
	of the calling instance of this class and a given instance of this class.
	Precondition: Complex object is instantiated.
	Postcondition: Complex object that has each of its private member variables defined as the
				   difference of the corresponding private member variables of the calling instance
				   of this class and the given Complex object is returned.
	object as existing Complex object
**/
Complex Complex::subtraction(Complex& object)
{
	// Find the difference between the real private member variables and store it in a variable
	double realDifference = real - object.getReal();
	// Find the difference between the imaginary private member variables and store it in a variable
	double imaginaryDifference = imaginary - object.getImaginary();
	// Create Complex object using the variables above
	Complex result(realDifference, imaginaryDifference);
	// Return the Complex object
	return result;
}

/**
	Returns a object of this class whose real and imaginary private member variables
	are the products of the corresponding real and imaginary private member variables
	of the calling instance of this class and a given instance of this class.
	Precondition: Complex object is instantiated.
	Postcondition: Complex object that has each of its private member variables defined based
				   on the formula of multiplying complex numbers is returned.
	object as existing Complex object
**/
Complex Complex::multiplication(Complex& object)
{
	// Use formula (a + bi) * (c + di) = (ac-bd) + (ad + bc)i
	// Calculate (ac-bd) and store in a variable
	double newReal = ((real * object.getReal()) - (imaginary * object.getImaginary()));
	// Calculate (ad +bc) and store in a variable
	double newImaginary = ((real * object.getImaginary()) + (imaginary * object.getReal()));
	// Create Complex object using the variables above
	Complex result(newReal, newImaginary);
	// Return the Complex object
	return result;

}

/**
	Output the private member variables of an instance of this class
	like how actual complex numbers are written to the terminal
	Precondition: Complex object is instantiated
	Postcondition: The private member variables of an instance of this class are outputted
				   to the terminal like complex numbers
**/
void Complex::print()
{
	// Output the private member variables like a complex number
	cout << real << " + " << imaginary << "i" << endl;
}
