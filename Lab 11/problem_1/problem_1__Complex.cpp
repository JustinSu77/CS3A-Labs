/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: Complex.cpp for Problem #1 of Lab #11
**/
#include "Complex.h"

void Complex::setReal(double r)
{
	// Set private member variable real to given r
	real = r;
}

void Complex::setImaginary(double i)
{
	// Set private member variable imaginary to given i
	imaginary = i;
}

double Complex::getReal() const
{
	// Return private member variable real
	return real;
}

double Complex::getImaginary() const
{
	// Return the private member variable imaginary
	return imaginary;
}

Complex addition(const Complex& object1, const Complex& object2)
{
	// Add the private member variable real of both given objects
	double realSum = object1.real + object2.real;
	// Add the private member variable imaginary of both given objects
	double realImaginary = object1.imaginary + object2.imaginary;
	// Create new Complex object using the above variables
	Complex result(realSum, realImaginary);
	// Return the new object
	return result;
}

Complex subtraction(const Complex& object1, const Complex& object2)
{
	// Subtract the private member variable real of both given objects
	double realDifference = object1.real - object2.real;
	// Subtract the private member variable imaginary of both given objects
	double imaginaryDifference = object1.imaginary - object2.imaginary;
	// Create the new Complex object using the above variables
	Complex result(realDifference, imaginaryDifference);
	// Return the new object
	return result;
}

Complex multiplication(const Complex& object1, const Complex& object2)
{
	// (a + bi) * (c + di) = (ac - bd) + (ad + bc)
	// Find (ac - bd)
	double real = (object1.real * object2.real) - (object1.imaginary * object2.imaginary);
	// Find (ad + bc)
	double imaginary = (object1.real * object2.imaginary) +  (object1.imaginary * object2.real);
	// Create new Complex object
	Complex result(real, imaginary);
	// Return the new object
	return result;
}
