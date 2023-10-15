/**
	Date: 10/12/2023
	By: Justin Su
	Purpose: Polynomial.cpp for Problem #1 of Lab #13
**/
#include "Polynomial.h"

/**
	Purpose: Default constructor.
	Result: Private member variable coef is set to nullptr
			Private member variable degree is set to 1
**/
Polynomial::Polynomial()
{
	 
	// Set private member variable coef to nullptr
	this->coef = nullptr;
	// Set private member variable degree to 1
	this->degree = 1;
}

/**
	Purpose: Constructor with 2 arguments.
	Input: coef as int dynamic array
		   degree as the highest degree object created will have as int
	Input Requirement: degree should be positive
	Result: Private member variable degree is set to given degree
			Private member variable coef points to a int dynamic array with MAX_COUNT size of 0s
			Elements from given coef is then copied into private member variable coef up to given degree + 1
**/
Polynomial::Polynomial(int* coef, int degree)
{
	// Set private member variable degree to given degree
	this->degree = degree;
	// Set private member variable coef to dynamic array of MAX_COUNT with 0s
	this->coef = new int[MAX_COUNT] {};
	// Loop up to given degree + 1
	for (int i = 0; i < degree + 1; i++)
	{
		// Copy elements from given coef to private member variable coef
		this->coef[i] = coef[i];
	}
}

/**
	Purpose: Copy Constructor
	Input: const reference of existing object of this class
	Input Requirement: Given object reference references an object 
			          of this class that is already instantiated
	Result: Private member variable degree is set to the degree of given object reference
			Private member variable coef is set to int dynamic array with size of MAX_COUNT of 0s
			Copy degree + 1 elements from the private member variable coef of given object reference 
			of this class to the private member variable coef
**/
Polynomial::Polynomial(const Polynomial& poly)
{
	// Deallocate dynamic array pointed to by private member variable coef
	delete[] this->coef;
	// Set private member variable degree to the private 
	// member variable of given object reference of this class
	this->degree = poly.degree;
	// Set private member variable coef to int dynamic array of MAX_COUNT with 0s
	this->coef = new int[MAX_COUNT] {};
	// Loop up to degree + 1
	for (int i = 0; i < degree + 1; i++)
	{
		// Copy elements from given reference of this class to private member variable coef
		this->coef[i] = poly.coef[i];
	}
}
/**
	Purpose: Destructor
	Result: The private member variable coef is deallocated
**/
Polynomial::~Polynomial()
{
	// Deallocate dynamic array pointed to by private member variable coef
	delete[] coef;
}

/**
	Purpose: Setter for private member variable degree.
	Input: degree as int
	Input Requirement: Given degree should be >= 0
	Result: Sets private member degree to given degree
**/
void Polynomial::setDegree(int degree)
{
	// Set private member variable degree to given degree
	this->degree = degree;
}
/**
	Purpose: Setter function for private member variable coef.
	Input: coef as pointer to int dynamic array
		   degree as int
	Input Requirement: Give degree should be >= 0
	Result: Set private member variable degree to given degree
			Set private member variable coef to be int dynamic array with size of MAX_COUNT of 0s
			Copy elements of given coef to private member variable coef
**/
void Polynomial::setCoef(int* coef, int degree)
{
	// Deallocate dynamic array pointed to by private member variable coef
	delete[] this->coef;
	// Set private member variable degree to given degree
	this->degree = degree;
	// Set private member variable coef to int dynamic array with MAX_COUNT size of 0s
	this->coef = new int[MAX_COUNT] {};
	// Loop to degree + 1
	for (int i = 0; i < degree + 1; i++)
	{
		// Copy the elements from given coef to private member variable coef
		this->coef[i] = coef[i];
	}

}

/**
	Purpose: Getter function for private member variable degree.
	Result: Private member variable degree is returned
**/
int Polynomial::getDegree()
{
	return degree;
}

/**
	Purpose: Getter function for private variable coef.
	Result: Private member variable coef is returned
**/
int* Polynomial::getCoef()
{
	return coef;
}

/**
	Purpose: Overload Assignment operator.
	Input: rightSide as const reference as existing object of this class
	Input Requirement: Given object rightSide should be instantiated
	Result: Deallocates private member coef
			Sets private member variable degree to the private member degree of given rightSide object
			Sets private mmeber coef to dynamic array of int with MAX_COUNT size of 0s
			Copy the elements from the private member coef of given rightSide object to private member variable coef
**/
Polynomial& Polynomial::operator=(const Polynomial& rightSide)
{
	// Deallocate private member variable coef
	delete[] this->coef;
	// Set private member variable degree to the private member degree of given rightSide object
	this->degree = rightSide.degree;
	// Set private member variable coef to int dynamic array
	this->coef = new int[MAX_COUNT] {};
	// Loop up to degree + 1
	for (int i = 0; i < degree + 1; i++)
	{
		// Copy elements
		this->coef[i] = rightSide.coef[i];
	}
	// Return the object of this class on the leftSide
	return *this;
}

/**
	Purpose: Overload + operator.
	Input: leftSide as const reference of this class
		   rightSide as const reference of this class
	Input Requirement: Given leftSide object should be instantiated
					   Given rightSide object should be instantiated
	Result: Create new int dynamic array with size of whatever degree from given objects is highest + 1
			If the degree of given objects are equal than traverse their coef arrays backwards and add the elements
			If the degree of given objects are different, find the largestValue from both arrays and set that to be the last element, then traverse array of backwards and add the elements
**/
Polynomial operator+(const Polynomial& leftSide, const Polynomial& rightSide)
{
	// Set largestDegree as the degree of given leftSide
	int largestDegree = leftSide.degree;
	// Flag to check if leftSide has larger degree
	bool leftSideHasLargerDegree = true;
	// If the degree of the rightSide is larger
	if (rightSide.degree > largestDegree)
	{
		// Make it the largestDegree
		largestDegree = rightSide.degree;
		// Set flag to false
		leftSideHasLargerDegree = false;
	}
	 
	// Declare and initialize resultArray with size of MAX_COUNT to 0s 
	int* resultArray = new int[MAX_COUNT] {};
	//If the degrees of given objects are not equal
	if (leftSide.degree != rightSide.degree)
	{
		// If the leftSide has larger degree
		if (leftSideHasLargerDegree)
		{
			// Set the last element of resultArray to the last element of leftSide array
			resultArray[largestDegree] = leftSide.coef[largestDegree];
		}
		else
		{
			// Otherwise set the last element of resultArray as the last element of rightSide arrays
			resultArray[largestDegree] = rightSide.coef[largestDegree];
		}
		// Loop through the rest of the elements starting from second to last element backwards
		for (int i = largestDegree - 1; i >= 0; i--)
		{
			// Set the current index of resultArray as the sum of the values at the 
			// current index of the arrays of the given objects
			resultArray[i] = leftSide.coef[i] + rightSide.coef[i];
		}
	}
	// Otherwise if the degrees of given object ar equal
	else
	{
		// Just loop backwards 
		for (int i = largestDegree; i >= 0; i--)
		{
			// Set the value at current index of resultArray to the sum of the 
			// current index of the arrays of given objects
			resultArray[i] = leftSide.coef[i] + rightSide.coef[i];
		}
	}
	// Create object of this class
	Polynomial result(resultArray, largestDegree + 1);
	// Return it
	return result;
}

/**
	Purpose: Overload - operator.
	Input: leftSide as const reference of this class
		   rightSide as const reference of this class
	Input Requirement: Given leftSide object should be instantiated
					   Given rightSide object should be instantiated
	Result: Create new int dynamic array with size of whatever degree from given objects is highest + 1
			If the degree of given objects are equal than traverse their coef arrays backwards and subtract the elements
			If the degree of given objects are different, find the largestValue from both arrays, make it negative and set that to be the last element, then traverse array of backwards and subtract the elements
**/
Polynomial operator-(const Polynomial& leftSide, const Polynomial& rightSide)
{
	// Set largestDegree as the degree of given leftSide
	int largestDegree = leftSide.degree;
	// Flag to check if leftSide has larger degree
	bool leftSideHasLargerDegree = true;
	// If the degree of the rightSide is larger
	if (rightSide.degree > largestDegree)
	{
		// Make it the largestDegree
		largestDegree = rightSide.degree;
		// Set flag to false
		leftSideHasLargerDegree = false;
	}

	// Declare and initialize resultArray with size of MAX_COUNT to 0s 
	int* resultArray = new int[MAX_COUNT] {};
	//If the degrees of given objects are not equal
	if (leftSide.degree != rightSide.degree)
	{
		// If the leftSide has larger degree
		if (leftSideHasLargerDegree)
		{
			// Set the last element of resultArray to the last 
			// element of leftSide array multipied by -1
			// multiply by -1 0 minus a positive element is negative
			resultArray[largestDegree] = leftSide.coef[largestDegree] * -1;
		}
		else
		{
			// Otherwise set the last element of resultArray as the last 
			// element of rightSide arrays multiplied by 1
			// multiply by -1 0 minus a positive element is negative
			resultArray[largestDegree] = rightSide.coef[largestDegree] * -1;
		}
		// Loop through the rest of the elements starting from second to last element backwards
		for (int i = largestDegree - 1; i >= 0; i--)
		{
			// Set the current index of resultArray as the sum of the values at the 
			// current index of the arrays of the given objects
			resultArray[i] = leftSide.coef[i] - rightSide.coef[i];
		}
	}
	// Otherwise if the degrees of given object ar equal
	else
	{
		// Just loop backwards 
		for (int i = largestDegree; i >= 0; i--)
		{
			// Set the value at current index of resultArray to the sum of the 
			// current index of the arrays of given objects
			resultArray[i] = leftSide.coef[i] - rightSide.coef[i];
		}
	}
	// Create object of this class
	Polynomial result(resultArray, largestDegree + 1);
	// Return it
	return result;
}
