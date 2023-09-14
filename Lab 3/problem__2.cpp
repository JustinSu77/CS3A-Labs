/**
	Date: 9/5/2023
	By: Justin Su
	Purpose: Problem #2 for Lab #3
**/
#include <iostream>
#include <random>
using namespace std;

/**
	Fill given array with random numbers from 1 to 15.
	Precondition: Given array has size number of elements
	Postcondition: Given is filled with numbers between 1 to 15
		array as array with int data type
		size as number of elements array will have as int
**/
void fillArrayWithRandomNumbers(int array[], int size);

/**
	Output the elements of given array to the terminal.
	Precondition: Given array has size number of elements
	Postcondition: Elements of given array has been outputted to the terminal.
		array as array with int data type
		size of number of elemenrs array will have as int
**/
void printArray(int array[], int size);
/**
	Sort the array in ascending order using insertion sort.
	Precondition: Given array has size number of elements
	Postcondition: The elements of given array is sorted in ascending order
		array as array with int data type
		size as number of elements array will have as int
	
**/
void insertionSort(int array[], int size);

/**
	Remove duplicates of each element from given array by shifting elements to the left and appending zeroes at the end.
	Precondition: Given array has size number of elements
	Postcondition: The duplicate values of given array is removed by shifting existing elements to the right
				   Zeroes are added at the end based on how many numbers have duplicates
	array as array with int data type
	size as number of elements array will have as int
**/
void removeDuplicates(int array[], int size);

int main()
{
	// Seed random number generator
	srand(time(0));
	// Declare array with size 10
	int A[10];
	// Fill array with random numbers from 1 to 15
	fillArrayWithRandomNumbers(A, 10);
	// Output the elemenrs of the array to terminal before any operations
	cout << "     Original Data     " << endl;
	cout << "------------------------" << endl;
	printArray(A, 10);
	cout << endl;
	// Sort array 
	insertionSort(A, 10);
	// Output element of array to terminal
	cout << "     After Sorting    " << endl;
	cout << "------------------------" << endl;
	printArray(A, 10);
	cout << endl;
	// Remove the duplicate values for each 
	removeDuplicates(A, 10);
	// Output elements of array to terminal
	cout << "   After Removing Duplication    " << endl;
	cout << "--------------------------------" << endl;
	printArray(A, 10);
	 
	return 0;
}

void fillArrayWithRandomNumbers(int array[], int size)
{
	// Loop through given array
	for (int i = 0; i < size; i++)
	{
		// Get random number from 1 to 15
		int randomNumber = 1 + (rand() % 15);
		// Assign randomNumber to current index of the given array
		array[i] = randomNumber;
	}
}

void printArray(int array[], int size)
{
	// Loop through array
	for (int i = 0; i < size; i++)
	{
		// Output the elements with a space in between
		cout << array[i] << " ";
	}
	// Output new line
	cout << endl;
}

void insertionSort(int array[], int size)
{
	// Declare variables used
	int i, j, key;
	// Loop through array
	for (i = 1; i < size; i++)
	{
		// Set key to current element
		key = array[i];
		// Set j to element before current element
		j = i - 1;
		// Compare the key element to the element before it
		// If key element is smaller keep comparing with each of the elements before it
		// Swap the key element with the its previous element if it is smaller
		while (j >= 0 && array[j] > key)
		{
			// Swap element
			array[j + 1] = array[j];
			// Go to element before
			j--;
		}
		// Insert key element into position where it is greater than the element before it
		array[j + 1] = key;
	}
}

void removeDuplicates(int array[], int size)
{
	// Declare variable use for copying unique element to new spot in array
	int copyIndex = 0;
	// Loop through array stopping before the last element
	for (int i = 0; i < size - 1; i++)
	{
		// If next element is not equal to current element
		if (array[i] != array[i + 1])
		{
			// Copy current element to new index of array
			array[copyIndex] = array[i];
			// Increment copyIndex for next unique element
			copyIndex++;
		}
			
	}
	// The last element of array after duplicates are removed will still be the original last element
	array[copyIndex] = array[size - 1];
	
	// Fill the remaining spaces with zeroes
	for (int i = copyIndex + 1; i < size; i++)
	{
		// Set current index to 0
		array[i] = 0;
	}
}