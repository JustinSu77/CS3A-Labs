/**
	Date: 9/19/2023
	By: Justin Su
	Purpose: Problem #2 of Lab #7
**/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
	Add each element at same index from given arrayOne and given arrayTwo and save it to given resultArray.
	Precondition: Given arrayOne and arrayTwo have some elements
	Postcondition: The sum of each element of arrayOne and arrayTwo at same index and store it
					into corresponding index of resultArray
	arrayOne as dynamicArray with data type of int
	arrayTwo as dynamicArray with data type of int
	resultArray as dynamicArray with data type of int
	resultArraySize as the number of elements in all 3 given dynamic arrays
**/
void addElementsOfArrays(int* arrayOne, int* arrayTwo, int* resultArray, int resultArraySize);

/**
	Print the given array as a polynomial.
	Precondition: Given array has some elements
	Postcondition: The elements of given array are printed backwards and x, +, - and ^ are added in between each element depending on its index and if it is positive or negative
				   If there is only 1 element output that element and return
	arrayOne as dynamic array with data type of int
	arraySize as number of integers in given dynamic array as int
**/
void printArrayAsPolynomial(int* array, int arraySize);

/**
	Fill given array with data read from given file.
	Precondition: File opened by given inputFile object has some lines of 2 integers where second integer is >= 0
	Postcondition: Given array is filled by assigning the first integer from given file
				   to the index of the second integer from given file
	array as dynamic array with data type of int
	inputFile as ifstream object
**/
void fillArrayFromFile(int* array, ifstream& inputFile);

/**
	Return whether or not the elements that are not the first element of given dynamic array are all zeroes.
	Precondition: Given array has some elements
	Postcondition: True is returned if all the elements besides first elements are zeroes
				   False otherwise
	array as dynamic array with data type of int
	arraySize as size of given dynamic array
**/
bool allElementsNotFirstElementAreZeroes(int* array, int arraySize);

int main()
{
	// Declare and initialize cstrings to store name of given files
	char fileOneName[20] = "";
	char fileTwoName[20] = "";
	// Prompt user for name of first file
	cout << "Enter file1 : ";
	// Get file name for first file
	cin >> fileOneName;
	// Prompt user for name of second file
	cout << "Enter file2 : ";
	// Get file name for second file
	cin >> fileTwoName;
	// Declare ifstream object to read file
	ifstream inputFile;
	// Open the first file
	inputFile.open(fileOneName);
	// If fail to open file
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open file 1" << endl;
		// Exit program with error code of 1
		exit(1);
	}
	// Declare and initialize variable to store the first integer of each line of given file
	int coefficient = 0;
	// Declare and initialize variables to store the second integer of each given file
	// value of first line of given text files
	int fileOneMaxExponent = 0;
	int fileTwoMaxExponent = 0;
	// Read the first line of first file and store the 2 integers of each line into 
	// the coefficient and fileOneMaxExponent variables
	inputFile >> coefficient >> fileOneMaxExponent;
	// Close ifstream object
	inputFile.close();
	// Open file 2 
	inputFile.open(fileTwoName);
	// If fail to open file
	if (inputFile.fail())
	{
		// notify
		cout << "Failed to open file 2" << endl;
		// Exit program with error code of 1
		exit(1);
	}
	// Read the first line of file 2 and store the 2 integers of each line
	// into coefficient and fileTwoMaxExponent
	inputFile >> coefficient >> fileTwoMaxExponent;
	// Declare and initialize variable to store the largest exponent seen
	int largestExponent = fileOneMaxExponent;
	// If the exponent of file 2 is larger than exponent of file 1
	if (fileTwoMaxExponent > fileOneMaxExponent)
	{
		// Set the largest
		largestExponent = fileTwoMaxExponent;
	}
	// Declare and initialize the size for dynamic arrays using the largestExponent seen plus 1
	int arraySize = largestExponent + 1;
	// Declare and initalize 2 dynamic array with size of arraySize to 0s
	// The dynamic array with have the size of the largest exponent seen from the files so addition is easier
	int* fileOneArray = new int[arraySize] {};
	int* fileTwoArray = new int[arraySize] {};
	// Close inputFile object
	inputFile.close();
	// Open file 1
	inputFile.open(fileOneName);
	// If fail to open file
	if (inputFile.fail())
	{
		// notify
		cout << "Failed to open file 1" << endl;
		// Exit program 
		exit(1);
	}
	// Call function to fill fileOneArray with data from file 1
	fillArrayFromFile(fileOneArray, inputFile);
	// Close ifstream object
	inputFile.close();
	// Open file 2
	inputFile.open(fileTwoName);
	// If fail to open file 2
	if (inputFile.fail())
	{
		// notify
		cout << "Failed to open file 1" << endl;
		// Exit program with error code of 1
		exit(1);
	}
	// Fill fileTwoArrat with data from file 2
	fillArrayFromFile(fileTwoArray, inputFile);
	// Declare and initialize resultArray with size of arraySize and filled with 0s
	int* resultArray = new int[arraySize] {};
	// Output fileOneArray as a polynominal
	// Output next line to terminal for readability
	cout << endl;
	cout << "A = ";
	printArrayAsPolynomial(fileOneArray, arraySize);
	// Output fileTwoArray as a polynomial
	cout << "B = ";
	printArrayAsPolynomial(fileTwoArray, arraySize);
	// Call functions to add the elements of fileOneArray and fileTwoArray and save the results to resultArray
	addElementsOfArrays(fileOneArray, fileTwoArray, resultArray, arraySize);
	// Output resultArray as a polynomial
	cout << "C = ";
	printArrayAsPolynomial(resultArray, arraySize);
	// Deallocates fileOneArray, fileTwoArray, and resultArray
	delete[] fileOneArray;
	delete[] fileTwoArray;
	delete[] resultArray;

	return 0;
}


void addElementsOfArrays(int* arrayOne, int* arrayTwo, int* resultArray, int resultArraySize)
{
	// Loop through both arrayOne and arrayTwo
	for (int i = 0; i < resultArraySize; i++)
	{
		// Store the sum of the elements of arrayOne and arrayTwo 
		// at current index i into index i of resultArray
		resultArray[i] = arrayOne[i] + arrayTwo[i];
	}
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
				cout << "+";
				// Output coefficient to terminal
				cout << coefficient;
			}
			// If coefficient is the last element and is negative
			else if (i == 0 && coefficient < 0)
			{
				// Output coefficient to terminal
				cout << coefficient;
			}
			// If coefficient is the first coefficient seen
			else if (isFirstCoefficient || coefficient < 0)
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

			// If coefficent is positive
			else if (coefficient > 0)
			{
				// Output a plus symbol to terminal
				cout << "+";
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
	cout << endl;
}



void fillArrayFromFile(int* array, ifstream& inputFile)
{
	// Declare and initialize variables use in read data from given file
	int exponent = 0;
	int coefficient = 0;
	// Read entire file
	while (!inputFile.eof())
	{
		// Read and store the first and second integers from file
		inputFile >> coefficient >> exponent;
		// Assign the first integer from file to the index of 
		// second integer from file of given dynamic array
		array[exponent] = coefficient;
	}
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
