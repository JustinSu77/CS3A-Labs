/**
	Date: 9/28/2023
	By: Justin Su
	Purpose: rational.cpp file for Problem #2 of Lab #10
**/

#include "rational.h"
#include <iostream>
using namespace std;
/**
	Default constructor.
	Precondition: Object of this class is instantiated.
	Postcondition: Private member variable numerator is set to 0.
				   Private member variable denominator is set to 1.
**/
Rational::Rational()
{

	// Set private variable numerator to 0
	numerator = 0;
	// Set private variable denominator to 1
	denominator = 1;
}
/**
	Constructor with 2 arguments.
	Precondition: Object of this class is instantiated.
	Postcondition: Private member variable numerator is set to given newNumerator.
				   Private member variable denominator is set to given newDenominator.
						If given newDenomiator is 0, notify and exit program with error code 1
	newNumerator as the numerator of Rational object as int
	newDenominator as the denominator of Rational object as int
**/
Rational::Rational(int newNumerator, int newDenominator)
{
	// Rational numbers cannot have a denominator as 0
	// If given newDenonminator is 0 
	if (newDenominator == 0)
	{
		// Notify
		cout << "A Rational number cannot have 0 as denominator";
		// Exit program
		exit(1);
	}
	// Set numerator to given newNumerator
	numerator = newNumerator;
	// Set denonminator to newDenominator
	denominator = newDenominator;
}

/**
	Return an instance of this class with its numerator and denominator set to the sum of the corresponding numerator and denominator
	of the calling object of this class and the given object of this class using standard procedure to add fractions.
	Precondition: Object of this class is instantiated.
	Postcondition: An instance of this class is returned.
**/
Rational Rational::add(const Rational& object)
{
	// Declare variable to store new numerator
	// New numerator is the sum of cross multiplying each corresponding numerator with the denominator of the other object
	int newNumerator = (numerator * object.denominator) + (object.numerator * denominator);
	// Declare variable to store new denominator
	// New denominator is the product of the denominator of the calling object and the denominator of the given object
	int newDenominator = denominator * object.denominator;
	// Create a instance of this class using the variables above
	Rational result(newNumerator, newDenominator);
	// Call helper function to simplify the fraction
	result.reduce();
	// Return the instance
	return result;
}

/**
	Return an instance of this class with its numerator and denominator set to the difference of the corresponding numerator and denominator.
	of the calling object of this class and the given object of this class using standard procedure to subtract fractions.
	Precondition: Object of this class is instantiated.
	Postcondition: An instance of this class is returned.
**/
Rational Rational::subtract(const Rational& object)
{
	// Declare variable to store new numerator.
	// New numerator is the difference of cross multiplying each corresponding numerator with the denominator of the other object
	int newNumerator = (numerator * object.denominator) - (object.numerator * denominator);
	// Declare variable to store new denominator
	// New denominator is the product of the denominator of the calling object and the denominator of the given object
	int newDenominator = denominator * object.denominator;

	// Create a instance of this class using the variables above
	Rational result(newNumerator, newDenominator);
	// Call helper function to simplify the fraction
	result.reduce();
	// Return the instance
	return result;
}

/**
	Return an instance of this class with its numerator and denominator set to the product of the corresponding numerator and denominator.
	of the calling object of this class and the given object of this class using standard procedure to multiply fractions.
	Precondition: Object of this class is instantiated.
	Postcondition: An instance of this class is returned.
**/
Rational Rational::multiply(const Rational& object)
{
	// Declare variable to store new numerator
	// New numerator is the product of the numerator of the calling object and the numerator of the given object
	int newNumerator = numerator * object.numerator;
	// Declare variable to store new denominator
	// New denominator is the product of the denominator of the calling object and the denominator of given object
	int newDenominator = denominator * object.denominator;
	// Create a instance of this class using the variables above
	Rational result(newNumerator, newDenominator);
	// Call helper function to simplify the fraction
	result.reduce();
	// Return the instance
	return result;
}

/**
	Return an instance of this class with its numerator and denominator set to the sum of the corresponding numerator and denominator
	of the calling object of this class and the given object of this class using standard procedure to divide fractions.
	Precondition: Object of this class is instantiated.
	Postcondition: An instance of this class is returned.
**/
Rational Rational::divide(const Rational& object)
{
	// Declare variable to store new numerator
	// New numerator is the product of the numerator of the calling object and the denominator of the given object 
	int newNumerator = numerator * object.denominator;
	// Declare variable to store new denominator
	// new denominator is the product of the denominator of the calling object and the numerator of the given object
	int newDenominator = denominator * object.numerator;
	// Create instance of this class using the variables above
	Rational result(newNumerator, newDenominator);
	// Call helper function to simplify the fraction
	result.reduce();
	// Return the instance
	return result;
}

/**
	Output the numerator and denominator as a fraction.
Precondition: Object of this class is instantiated.
	Postcondition: The numerator and denominator is outputted to terminal with a / between them.
**/
void Rational::print()
{
	// Output numerator and denominator as fraction
	cout << numerator << "/" << denominator << endl;
}

/**
	Divide the numerator and the denominator private member variables by their greatest common divisor.
	Precondition: Object of this class is instantiated.
	Postcondition: Private member variables numerator and denominator are divided by their greatest common divisor.
**/
void Rational::reduce()
{
	// Declare and initialize the smallest variable to be which is smaller numerator or denomianator
	// Initialize smallest variable to  be numerator first
	int smallest = denominator;
	// If the numerator is larger than denominator 
	// and numerator is not zero to prevent division by 0
	if (smallest > numerator && numerator != 0)
	{
		// Set the denominator as the smallest
		smallest = numerator;
	}
	// Set the initial greatestCommon Divisor to be the smallest number
	int greatestCommonDivisor = smallest;

	// If initial greatestCommonDivisor is negative
	if (greatestCommonDivisor < 0)
	{
		// Make it positive
		greatestCommonDivisor *= -1;
	}
	
	// Find the greatest common divisor
	// While greatest common divisor is greater than 0
	while (greatestCommonDivisor > 0)
	{
		// If the greatest common divisor can divide numerator and denominator evenly
		if ((numerator % greatestCommonDivisor == 0) && (denominator % greatestCommonDivisor == 0))
		{
			// Get out of loop
			break;
		}
		// Otherwise decrease greatest common divisor by 1
		greatestCommonDivisor--;
	}
	
	// Set numerator to it divided by greatest common divisor
	numerator = numerator / greatestCommonDivisor;
	// Set denominator to it divided by greatest common divisor
	denominator = denominator / greatestCommonDivisor;
}
