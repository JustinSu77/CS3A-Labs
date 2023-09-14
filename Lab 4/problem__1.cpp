/**
	Date: 9/7/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #4
**/
#include <iostream>
#include <random>
using namespace std;

void printArray(int array[], int size);
/**
	Fill given with random numbers from 0 to 99 and ensuring no repeats.
	Precondition: Array has some elements
	Postcondition: Array is filled with numbers ranging from 0 to 99
		array as array with data type of int
		size as number of elements array will have as int
**/
void fillArrayWithNoDuplicates(int array[], int size);

/**
	Fill given target array with elements from given array where the current largest and
	second largest elements are at the first and last available indices in each copying iteration.
	Precondition: Given array and target array has some elements.
	Postcondition: Target array has the largest and second largest elements
				   copied to the first and last available indices at each copying iteration
		array as array with data type of int
		target as array to copy elements to as int
		size as the number if elements in both array and target
**/
void fillArrayWithLargestsAtEnds(int array[], int target[], int size);

int main()
{
	// Seed random number generator
	srand(time(0));
	// Declare and initialize array A
	int A[10] = {};
	// Declare and initialize array B
	int B[10] = {};
	// Calculate number of elements in array A
	int size = (sizeof(A) / sizeof(A[0]));
	// Fill array A with random unique numbers from 0 to 99 
	fillArrayWithNoDuplicates(A, size);
	// Output the elements in array A
	cout << "A  :  ";
	printArray(A, 10);
	// Call function that will perform main task
	fillArrayWithLargestsAtEnds(A, B, size);
	// Output elements in array B
	cout << "B  :  ";
	printArray(B, 10);

	return 0;
}

void printArray(int array[], int size)
{
	// Loop through array  
	for (int i = 0; i < size; i++)
	{
		// Output elements with space in between
		cout << array[i] << " ";
	}
	// New line
	cout << endl;
}

void fillArrayWithNoDuplicates(int array[], int size)
{
	// Keep track of integers that has been seen, initialize all elements as false
	bool track[100] = {};
	// Loop through array
	for (int i = 0; i < size; i++)
	{
		// Get random integer from 0 to 99
		int randomNumber = rand() % 99;
		// If random integer already been seen
		if (track[randomNumber])
		{
			// Keep getting a new random integer until it is one that has not been seen
			randomNumber = rand() % 99;
			while (track[randomNumber])
			{
				randomNumber = rand() % 99;
			}
		}
		// Mark current random integer as seen
		track[randomNumber] = true;
		// Set current array index to random integer
		array[i] = randomNumber;
	}
}

void fillArrayWithLargestsAtEnds(int array[], int target[], int size)
{
	// Initialize start index that will copy elements to given target array starting from the left
	int start = 0;
	// Initialize end index that will copy elements to given target array starting from the right
	int end = size - 1;
	// While start and end have not cross paths
	while (start < end)
	{
		// Declare and initialize variable that will store largest value from given array
		int largest = -1;
		// Declare and initialize variable that will store second largest value from array
		int secondLargest = -1;
		// Declare and initialize variable that will store the index of the current largest element
		int largestIndex = -1;
		// Declare and initialize variable that will store the index of the second largest element
		int secondLargestIndex = -1;
		// Loop through given array
		for (int i = 0; i < size; i++)
		{
			// If current element larger than current largest
			if (array[i] > largest)
			{
				// Change the second largest to the current largest
				secondLargest = largest;
				// Set the currnet secondLargestIndex to be the index of the current largest
				secondLargestIndex = largestIndex;
				// Store currenet value as new largest
				largest = array[i];
				// Save current index as current largestIndex
				largestIndex = i;

			}
			// If the the current index is larger than current secondLargest but smaller than current largest
			else if (array[i] > secondLargest && array[i] < largest)
			{
				// Set current element as new second largest
				secondLargest = array[i];
				// Store current index as new secondLargestIndex
				secondLargestIndex = i;
			}

		}
		// Copy the current largest element to current start index in given target array
		target[start] = largest;
		// Copy the current secondLargest eleemnt to current end index in given target array
		target[end] = secondLargest;
		//Mark element at current largestIndex in given array to be -1 
		array[largestIndex] = -1;
		//Mark element at current secondLargestIndex in given array to be -1 
		array[secondLargestIndex] = -1;
		// Increment start variable to copy more elements to target array
		start++;
		// Increment end index to copy more elements to target array
		end--;
	}
}