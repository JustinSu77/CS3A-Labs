/**
	Date: 11/7/2023
	By: Justin Su
	Purpose: Problem #2 of Lab #18
**/
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

/**
	Purpose: Fills given array with numbers from 1 to
			 15 inclusively with no repeats.
	Input: - array as array of type integer
		   - arraySize as number of elements in given array
	Input Requirement: - Given array is an integer array
					   - Given arraySize should be an integer
					   - Given arraySize should be the same as the
						 number of elements in given array
	Result: Given integer array array is filled with unique elements
			from 1 to 15 inclusive.
**/
void fillArrayWithoutDuplicates(int array[], int arraySize);

/**
	Purpose: Output the elements of the array to terminal.
	Input: - array as array with type int
		   - arraySize as number of elements in given array
	Input Requirement: - Given array is an integer array
					   - Given arraySize should be an integer
					   - Given arraySize should be equal to number of
						 elements in array
	Result: The elements of the array is outputted to the screen
**/
void printArray(int array[], int arraySize);

/**
	Purpose: Return the result of recursively adding
			 all the elements in given integer array
	Input: - array as an integer array
		   - arraySize is the number of elements in given array
	Input Requirement: - Given array is an integer array
					   - Given arraySize should be an integer
					   - Given arraySize is the same as number of
						 elements in array
	Result: The sum of the elements in given array is
			returned after being added up recursively
**/
int recursiveSumOfElementsInArray(int array[], int arraySize);

int main()
{
	// Seed random 
	srand(time(NULL));
	// Declare and initialize array with 10 elements
	int array[10] = {};
	// Declare and initialize variable for 
	// number of elements in array
	int arraySize = sizeof(array) / sizeof(int);
	// Fill the array with unique numbers from 1 to 15 inclusive 
	fillArrayWithoutDuplicates(array, arraySize);
	// Output the elements of array to terminal
	printArray(array, arraySize);
	// Output the sum of the elements 
	cout << "sum : " << recursiveSumOfElementsInArray(array, arraySize);
	// Output a newline to terimal for readability
	cout << endl;

	return 0;
}

void fillArrayWithoutDuplicates(int array[], int arraySize)
{
	// Boolean array to keep track of numbers that 
	// have already been in array
	bool seenIntegers[15] = {};
	// Loop through array
	for (int i = 0; i < arraySize; i++)
	{
		// Generate random number from 1 to 15 inclusive
		int randomNumber = rand() % 15 + 1;
		// While generated integer is already seen

		while (seenIntegers[randomNumber - 1] == true)
		{
			// Generate another integer
			randomNumber = rand() % 15 + 1;
		}
		// Put generated number into array
		array[i] = randomNumber;
		// Mark current element as seen
		seenIntegers[randomNumber - 1] = true;
	}
}

void printArray(int array[], int arraySize)
{
	// Loop through array
	for (int i = 0; i < arraySize; i++)
	{
		// Output element at current index with space 
		// before single digit numbers 
		// Output space after each number
		cout << setw(2) << array[i] << " ";
	}
	// Output newline to terminal for readability 
	cout << endl;
}

int recursiveSumOfElementsInArray(int array[], int arraySize)
{
	// If there is only 1 element in array
	if (arraySize == 1)
	{
		// Return it
		return array[0];
	}
	// Add the current element with the result of 
	// recursive call while decrementin arraySize
	return recursiveSumOfElementsInArray(array, arraySize - 1) + array[arraySize - 1];
}
