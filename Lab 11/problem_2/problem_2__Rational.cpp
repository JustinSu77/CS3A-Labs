/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: Rational.cpp for Problem #2 of Lab #11
**/
#include <cmath>
#include "Rational.h"

void Rational::setNumerator(int n)
{
    // Set private member variable numerator to given n
    numerator = n;
}

void Rational::setdenominator(int d)
{
    // Set private member variable denominator to given d
    denominator = d;
}

int Rational::getNumerator() const
{
    // Return the private member variable numerator
    return numerator;
}

int Rational::getDenominator() const
{
    // Return the private member variable denominator
    return denominator;
}

Rational addition(const Rational& object1, const Rational& object2)
{
    // Store numerator for instance of this class to be returned
    int numerator = (object1.numerator * object2.denominator) + (object2.numerator * object1.denominator);
    // Store denominator for instance of this class to be returned
    int denominator = object1.denominator * object2.denominator;
    // Create new instance of this class with the variables above
    Rational result(numerator, denominator);
    // Simplify the numerator and denominator using reduce function
    result.reduce();
    // Return the instance
    return result;
}

Rational subtract(const Rational& object1, const Rational& object2)
{
    // Store numerator for instance of this class to be returned 
    int numerator = (object1.numerator * object2.denominator) - (object2.numerator * object1.denominator);
    // Store denominator for instance of this class to be returned
    int denominator = object1.denominator * object2.denominator;
    // Create new instance of this class with the variables above
    Rational result(numerator, denominator);
    // Simplify the numerator and denominator using reduce function
    result.reduce();
    // Return the instance
    return result;
   
}

Rational multiply(const Rational& object1, const Rational& object2)
{
    // Store the numerator for instance of this class to be returned
    int numerator = object1.numerator * object2.numerator;
    // Store the denominator for instance of this class to be returned
    int denominator = object1.denominator * object2.denominator;
    // Instantiate instance of this class using the variables above
    Rational result(numerator, denominator);
    // Simplify the numerator and denominator using reduce function
    result.reduce();
    // Return the instance
    return result;
}

Rational divide(const Rational& object1, const Rational& object2)
{
    // Store numerator of the instance of this class to be returned 
    int numerator = object1.numerator * object2.denominator;
    // Store denominator of the instance of this class to be returned 
    int denominator = object1.denominator * object2.numerator;
    Rational result(numerator, denominator);
    // Simplify the numerator and denominator using reduce function
    result.reduce();
    // Return the instance
    return result;
}

int Rational::gcd(int a, int b) const
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return abs(a);
}

void Rational::reduce()
{
    int gcd_result = gcd(numerator, denominator);
    numerator = numerator / gcd_result;
    denominator = denominator / gcd_result;
}