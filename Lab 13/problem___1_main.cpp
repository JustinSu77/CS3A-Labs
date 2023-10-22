/**
	Date: 10/12/2023
	By: Justin Su
	Purpose: main.cpp for Problem #1 of Lab #13
**/
#include <iostream>
#include <string>
#include <fstream>
#include "Polynomial.h"
using namespace std;

/**
	Purpose: Add elements from file opened by given ifstream object to given int dynamic array.
	Input: Given inputFile as ifstream object
		   Given array as int dynamic array
	Input Requirements: 
					   File opened by inputFile should be a text file
					   File opened by inputFile should have a single positive digit for the 
					   first line for the highest degree and 2 digits the rest of the file with the 
					   left side representing coefficients and right side representing the degree
					   The first digit pair of the text file should have the degree equal to the highest degree
					   Given dynamic array should have one more space than the first digit read from file
	Result: The digit pairs after the first line of the file are placead in the given 
			int dynamic array with the first digit as the value and the second digit as the index of array
**/
void readFromFile(ifstream& inputFile, int* array);

/**
	Result: Output elements of given array to terminal.
	Input: Given array as int dynamic array
		   arraySize as number of elements in given array as int
	Input Requirements: Number of elements in given array should be equal to given arraySize
					    arraySize should not be negative
	Result: Elements of given array are outputted to terminal
**/
void outputArray(int* array, int arraySize);

/**
	Result: Print the given array as a polynomial.
	Input: Given array as int dynamic array
		   Given arraySize as number of elements in array as int
	Input Requirements: Given array is filled with data from file
					    Number of elements in given array is equal to given arraySize
					    Given arraySize should not be negative
	Result: The elements of given array are printed backwards and x, +, - and ^ 
			are added in between each element depending on its index and if it is positive or negative
		    If there is only 1 element output that element and return
**/
void printArrayAsPolynomial(int* array, int arraySize);
/**
	Purpose: Return whether or not the elements that are not the 
			 first element of given dynamic array are all zeroes.
	Input: Given array as int dynamic array
		   Given arraySize as number of elements in array as int
	Input Requirement: Given array is filled with data from file
					   Number of elements in given array is equal to given arraySize
					   Given arraySize should not be negative
	Result: True is returned if all the elements besides first elements are zeroes
		    False otherwise
**/
bool allElementsNotFirstElementAreZeroes(int* array, int arraySize);

int main()
{
	// File One
	// Declare and initialize variable for name of first file
	string fileNameOne = "";
	// Prompt user for file name of first file
	cout << "Enter name of file1 : ";
	// Get input from user and store into variable
	getline(cin, fileNameOne);
	// Declare ifstream object
	ifstream inputFile;
	// Open given file from user
	inputFile.open(fileNameOne);
	// If failed to open file
	if (inputFile.fail())
	{
		// Output new line for readability
		cout << endl;
		// Notify
		cout << "Failed to open file: " << fileNameOne << endl;
		//Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable for highest degree of file one
	int highestDegreeOne = 0;
	// Read first line of file and store into variable
    inputFile >> highestDegreeOne;
	// Declare and initialize int dynamic array for first file with 
	// space one more than highest degree to 0s
	int* arrayOne = new int[highestDegreeOne + 1] {};
	// Fill array with data from file
	readFromFile(inputFile, arrayOne);
	// Close ifstream object
	inputFile.close();

	// File Two
	// Declare and initialize variable for name of second file
	string fileNameTwo = "";
	// Prompt user for file name of second file
	cout << "Enter name of file2 : ";
	// Get input from and store into variable
	getline(cin, fileNameTwo);
	// Open given file from user
	inputFile.open(fileNameTwo);
	// If failed to open file
	if (inputFile.fail())
	{
		// Output new line for readability
		cout << endl;
		// Notify
		cout << "Failed to open file: " << fileNameTwo << endl;
		//Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable for highest degree of file 2
	int highestDegreeTwo = 0;
	// Read first line of file and store into variable
	inputFile >> highestDegreeTwo;
	// Declare and initialize int dynamic array for second file with 
	// space one more than highest degree to 0s
	int* arrayTwo = new int[highestDegreeTwo + 1] {};
	// Fill array with data from file
	readFromFile(inputFile, arrayTwo);
	// Close ifstream object
	inputFile.close();

	// File Three
	// Declare and initialize variable for name of third file
	string fileNameThree = "";
	// Prompt user for file name of third file
	cout << "Enter name of file3 : ";
	// Get input from and store into variable
	getline(cin, fileNameThree);
	// Open given file from user
	inputFile.open(fileNameThree);
	// If failed to open file
	if (inputFile.fail())
	{
		// Output new line for readability
		cout << endl;
		// Notify
		cout << "Failed to open file: " << fileNameThree << endl;
		//Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable for highest degree of file 3
	int highestDegreeThree = 0;
	// Read first line of file and store into variable
	inputFile >> highestDegreeThree;
	// Declare and initialize int dynamic array for third file
	//  with space one more than highest degree to 0s
	int* arrayThree = new int[highestDegreeThree + 1] {};
	// Fill array with data from file
	readFromFile(inputFile, arrayThree);
	// Close ifstream object
	inputFile.close();

	// File Four
	// Declare and initialize variable for name of fourth file
	string fileNameFour = "";
	// Prompt user for file name of fourth file
	cout << "Enter name of file4 : ";
	// Get input from and store into variable
	getline(cin, fileNameFour);
	// Open given file from user
	inputFile.open(fileNameFour);
	// If failed to open file
	if (inputFile.fail())
	{
		// Output new line for readability
		cout << endl;
		// Notify
		cout << "Failed to open file: " << fileNameFour << endl;
		//Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable for highest degree of fourth file
	int highestDegreeFour = 0;
	// Read first line of file and store into variable
	inputFile >> highestDegreeFour;
	// Declare and initialize int dynamic array for fourth file
	//  with space one more than highest degree to 0s
	int* arrayFour = new int[highestDegreeFour + 1] {};
	// Fill array with data from file
	readFromFile(inputFile, arrayFour);
	// Close ifstream object
	inputFile.close(); 
	// Output newlines for space in temrinal
	cout << endl;
	cout << endl;
	// Declare and initialize Polynomial object with corresponding dynamic array and degree
	Polynomial p1(arrayOne, highestDegreeOne);
	Polynomial p2(arrayTwo, highestDegreeTwo);
	// Declare and initialize Polynomial object sum as the result of adding objects p1 and p2
	Polynomial sum = p1 + p2;
	// Declare and initialize Polynomial object difference as the result of subtracting objects p1 and p2
	Polynomial difference = p1 - p2;
	// Output Polynomial object p1
	cout << "Polynomial A   : ";
	printArrayAsPolynomial(p1.getCoef(), p1.getDegree() + 1);
	// Output Polynomial object p2
	cout << "Polynomial B   : ";
	printArrayAsPolynomial(p2.getCoef(), p2.getDegree() + 1);
	// Output Polynomial object sum
	cout << "Polynomial A+B : ";
	printArrayAsPolynomial(sum.getCoef(), sum.getDegree());
	// Output Polynomial object difference
	cout << "Polynomial A-B : ";
	printArrayAsPolynomial(difference.getCoef(), difference.getDegree());
	// Output newline for space in teminal 
	cout << endl;
	
	// Declare and initialize Polynomial object with corresponding dynamic array and degree
	Polynomial p3(arrayThree, highestDegreeThree);
	Polynomial p4(arrayFour, highestDegreeFour);
	// Declare and initialize Polynomial object sumTwo as the result of adding objects p3 and p4
	Polynomial sumTwo = p3 + p4;
	// Declare and initialize Polynomial object differenceTwo as the reslt of subtracting objects p3 and p4
	Polynomial differenceTwo = p3 - p4;
	// Output Polynomial object p3
	cout << "Polynomial C   : ";
	printArrayAsPolynomial(p3.getCoef(), p3.getDegree() + 1);
	// Output Polynomial object p4
	cout << "Polynomial D   : ";
	printArrayAsPolynomial(p4.getCoef(), p4.getDegree() + 1);
	// Output Polynomial object sumTwo
	cout << "Polynomial C+D : ";
	printArrayAsPolynomial(sumTwo.getCoef(), sumTwo.getDegree());
	// Output Polynomial object differenceTwo
	cout << "Polynomial C-D : ";
	printArrayAsPolynomial(differenceTwo.getCoef(), differenceTwo.getDegree());
	
	return 0;
}

void readFromFile(ifstream& inputFile, int* array)
{
	// Declare and initialize variable to store coefficient
	int coefficient = 0;
	// Declare and initialize variable to store degree
	int degree = 0;
	// Keep reading from file until the end
	while (!inputFile.eof())
	{
		// Read in the digit pair and store in variables coefficient and degree
		inputFile >> coefficient >> degree;
		// Set the degree as index of array to store coefficient
		array[degree] = coefficient;
	}
}

void outputArray(int* array, int arraySize)
{
	// Loop through given int dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Output elements with space in betwen
		cout << array[i] << " ";
	}
	// Output newline for readability in terminal
	cout << endl;
}

void printArrayAsPolynomial(int* array, int arraySize)
{
	// If only the first element is not 0, then just output the first element
	// For edge case where adding arrays gives a single integer
	if (allElementsNotFirstElementAreZeroes(array, arraySize))
	{
		cout << array[0] << endl;
		return;
	}
	// Declare and initialize flag to determine 
	// if current value of array is the first coefficient seen
	bool isFirstCoefficient = true;
	// Read elements from given array backwards
	for (int i = arraySize - 1; i >= 0; i--)
	{

		// Declare and initialize variable to store current element of array
		int coefficient = array[i];

		// If coefficient is not 0
		if (coefficient != 0)
		{

			// If coefficient is the last element and is positive
			if (i == 0 && coefficient > 0)
			{
				// Output a plus symbol to terminal
				cout << " + ";
				// Output coefficient to terminal
				cout << coefficient;
				// Output x 
				cout << "x";
				// Output exponent symbol
				cout << "^";
				// Output 0
				cout << "0";
			}
			// If coefficient is the last element and is negative
			else if (i == 0 && coefficient < 0)
			{
				cout << " + ";
				// Output coefficient to terminal
				cout << coefficient;
				// Output variable
				cout << "x";
				// Output exponent sign
				cout << "^";
				// Output 0
				cout << "0";
			}
			// If coefficient is the first coefficient seen
			else if (isFirstCoefficient)
			{
				// Outout coefficient
				cout << coefficient;
				// Output a x to terminal
				cout << "x";
				// Output exponent symbol to terminal
				cout << "^";
				// Output current index as the exponent to terminal
				cout << i;
				 
			}
			else if (coefficient < 0)
			{
				// Outout coefficient
				cout << " + ";
				cout << coefficient;
				// Output a x to terminal
				cout << "x";
				// Output exponent symbol to terminal
				cout << "^";
				// Output current index as the exponent to terminal
				cout << i;
				

			}

			// If coefficent is positive
			else if (coefficient > 0)
			{
				// Output a plus symbol to terminal
				cout << " + ";
				// Output coefficient to terminal
				cout << coefficient;
				// Output a x
				cout << "x";
				// Output exponent symbol to terminal
				cout << "^";
				// Output current index as exponent to terminal
				cout << i;
				
			}
			// After first iteration, set flag to false	
			isFirstCoefficient = false;
		}
	}
	// Skip a line in terminal for readability
	cout << endl;
}
bool allElementsNotFirstElementAreZeroes(int* array, int arraySize)
{
	// Loop through array starting at second element
	for (int i = 1; i < arraySize; i++)
	{
		// If any element is not 0 than return false
		if (array[i] != 0)
		{
			return false;
		}
	}
	// Otherwise return true
	return true;
}
