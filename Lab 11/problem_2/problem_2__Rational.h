#pragma once
/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: Rational.h for Problem #2 of Lab #11
**/
#include <iostream>
using namespace std;

class Rational
{
public:
	Rational() : numerator(0), denominator(0) {};
	Rational(int n, int d) : numerator(n), denominator(d) {
		reduce();
	}
	
	/**
		Setter for private member variable numerator.
		Precondition: Rational object is instantiated.
		Postcondition: Private variable numerator is set to given n.
			n as new value for private member variable numerator as int
	**/
	
	void setNumerator(int n);
	
	/**
		Setter for private member variable denominator.
		Precondition: Rational object is instantiated
		Postcondition: Private variable denominator is set to given n
			d as new value for private member variable denominator as int
	**/
	void setdenominator(int d);

	/**
		Constant getter function for private member variable numerator.
		Precondition: An object of this class is instantiated
		Postcondition: The private member variable numerator is returned
	**/
	int getNumerator() const;
	
	/**
		Constant getter function for private member variable denominator.
		Precondition: An object of this class is instantiated
		Postcondition: The private member variable denominator is returned
	**/
	int getDenominator() const;
	
	/**
		Friend function to return instance of this class where the numerator and denominator is 
		the reduced result of adding the numerator and denominator of the given object1 and object 2.
		Precondition: Given object1 and object2 are instantiated
		Postcondition: Return instance of this class with reduced numerator and denominator from adding the numerator and denominator			of the given object1 and object2
			object1 as a const reference of this class
			object2 as a const reference of this class
	**/
	friend Rational addition(const Rational& object1, const Rational& object2);
	
	/**
		Return instance of this class where the numerator and denominator is the reduced result of 
		subtracting the numerator and denominator of the given object1 and object 2.
		Precondition: Given object1 and object2 are instantiated
		Postcondition: Return instance of this class with the reduced numerator and 
					   denominator from subtracting the numerator and denominator of the given object1 and object2
		object1 as a const reference of this class
		object2 as a const reference of this class
**/
	friend Rational subtract(const Rational& object1, const Rational& object2);
	/**
		Return instance of this class where the numerator and denominator is 
		the reduced result of multiplying the numerator and denominator of the given object1 and object 2.
		Precondition: Given object1 and object2 are instantiaed
		Postcondition: Instance of this class with the reduced numerator and denominator from multiplying the numerator and				         denominator of the given object1 and object2
		object1 as a const reference of this class
		object2 as a const reference of this class
**/
	friend Rational multiply(const Rational& object1, const Rational& object2);
	/**
	Return instance of this class where the numerator and denominator is the reduced result of dividing the numerator and denominator of the given object1 and object 2.
	Precondition: Given object1 and object2 are instantiaed
	Postcondition: Return instance of this class with the reduced numerator and denominator from dividing the numerator and denominator of the given object1 and object2
		object1 as a const reference of this class
		object2 as a const reference of this class
**/
	friend Rational divide(const Rational& object1, const Rational& object2);

private:
	// Private member variable numerator
	int numerator;
	// Private member variable denominator
	int denominator;
	
	// Helper functions
	int gcd(int a, int b) const;
	void reduce();
};

