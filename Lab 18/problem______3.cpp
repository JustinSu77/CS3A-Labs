/**
	Date: 11/7/2023
	By: Justin Su
	Purpose: Problem #3 of Lab #18
**/
#include <iostream>
#include <iomanip>
using namespace std;
/**
	Purpose: Fill array with unique elements from 1 to 50 inclusive.
	Input: - array as integer array
		   - arraySize as number of elements in array
	Input Requirement: - Given array is an integer array
					   - Given arraySize is an integer
					   - Given arraySize is equal to number of
						 elements in given array array
	Result: Given integer array A is filled with unique
			elements from 1 to 50 inclusive
**/
void fillArrayWithoutDuplicates(int array[], int arraySize);


/**
	Purpose: Output the elements in given integer array.
	Input: - array as integer array
		   - arraySize as number of elements in array
	Input Requirement: - Given array is an integer array
					   - Given arraySize is an integer
					   - Given arraySize is equal to number of
						 elements in given integer array
	Result: Elements in given integer array is outputted to terminal
**/
void printArray(int array[], int arraySize);


/**
	Purpose: Reverse given integer  recursively.
	Input: - array as integer array
		   - arraySize as number of elements in array
	Input Requirement: - Given array is an integer array
					   - Given arraySize is an integer
					   - Given arraySize is equal to number of elements in
						 given integer array
	Result: - If given array is empty or only has one element return
			- Given integer array A is reversed
**/
void reverseArrayRecursively(int array[], int arraySize, int start, int end);


int main()
{
	// Seed random number generator
	srand(time(NULL));
	// Declare and initialize array with 10 elements
	int array[10] = {};
	// Declare and initialize the number of elements in A
	int arraySize = sizeof(array) / sizeof(int);
	// Fill array with unqiue elements from 1 to 50
	fillArrayWithoutDuplicates(array, arraySize);
	// Output the array
	printArray(array, arraySize);
	// Recursively reverse the array
	reverseArrayRecursively(array, arraySize, 0, arraySize - 1);
	// Output array 
	printArray(array, arraySize);
	cout << endl;

	return 0;
}

void fillArrayWithoutDuplicates(int array[], int arraySize)
{
	// Boolean array to keep track of seen generated number
	bool occur[50] = { false };
	// Loop through given array
	for (int i = 0; i < arraySize; i++)
	{
		// Generate a number from 1 to 50 inclusive
		int randomNumber = rand() % 50 + 1;
		// If generated number is already seen
		while (occur[randomNumber - 1] == true)
		{
			// Generate another number
			randomNumber = rand() % 50 + 1;
		}
		// Set current index of array to generated integer
		array[i] = randomNumber;
		// Mark generated integer as int
		occur[randomNumber - 1] = true;
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

void reverseArrayRecursively(int array[], int arraySize, int start, int end)
{
	// If given array is empty, 
	// only has 1 element, or arraySize is negative 
	if (arraySize <= 1)
	{
		// Get out of function
		return;
	}
	// Base case
	// When start and index is equal or cross paths
	if (start >= end)
	{
		// Get out of function
		return;
	}
	// Swap the elements
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;
	// Move start to right
	// Move end to left
	return reverseArrayRecursively(array, arraySize, start + 1, end - 1);
}
