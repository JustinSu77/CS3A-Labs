#pragma once
/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: Complex.h for Problem #1 of Lab #11
**/
#include <iostream>
using namespace std;
class Complex
{
	public:
		Complex() : real(0), imaginary(0) {};
		Complex(double r, double i) : real(r), imaginary(i) {};
		
		/**
			Setter function for private member variable real.
			Precondition: Complex object is instantiated.
			Postcondition: Private member variable real is set to given r.
				r as new value for private variable real as double
		**/
		void setReal(double r);
		
		/**
		Setter function for private member variable imaginary.
		Precondition: Complex object is instantiated.
		Postcondition: Private member variable imaginary is set to given i
				i as new value for private member variable imaginary as double
		**/
		void setImaginary(double i);
		
		
		/**
			Constant getter function for private member variable real.
			Precondition: Complex object is instantiated.
			Postcondition: Private member variable real is returned.
		**/
		double getReal() const;
		
		/**
			Constant getter function for private member variable imaginary.
			Precondition: Complex object is instantiated
			Postcondition: Private member variable imaginary is returned
		**/
		double getImaginary() const;
		
		/**
			Friend function to add two given Complex objects.
			Precondition: Given Complex objects object1 and object2 are instantiated
			Postcondition: Return an instance of this class that has its private member variable real set to the sum of the private				 member variable real of object1 and object2 and its private member variable imaginary set to the sum of the			 private member variable imaginary of object1 and object2.
			object1 as const reference of this class
			object2 as const reference of this
						   
		**/
		friend Complex addition(const Complex& object1, const Complex& object2);
		
		/**
			Friend function to add two given Complex objects.
			Precondition: Given Complex objects object1 and object2 are instantiated
			Postcondition: Return an instance of this class that has its private member variable real set to the difference of the				 private member variable real of object1 and object2 and its private member variable imaginary set to the			 	 difference of the private member variable imaginary of object1 and object2.
			object1 as const reference of this class
			object2 as const reference of this class
		**/
		friend Complex subtraction(const Complex& object1, const Complex& object2);

		/**
			Friend function to multiply two Complex objects.
			Precondition: Given Complex objects object1 and object2 are instantiated
			Postcondition: Apply formula (a + bi) * (c + di) = (ac-bd) + (ad + bc)
						   Return an instance of this class whose real private member variable is set to 
						   the result of (ac - bd) with object1 and object2 and whose imaginary private member variable 
						   is set to the result of (ad + bc) with object1 and object2.
			object1 as const reference of this class
			object2 as const reference of this class
		**/
		friend Complex multiplication(const Complex& object1, const Complex& object2);
 
	private:
		double real;
		double imaginary;
};

