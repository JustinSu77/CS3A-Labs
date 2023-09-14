/**
	Date: 9/5/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #3
 **/
#include <iostream>
using namespace std;

/**
	Outputs elements of given array to terminal.
	Precondition: Given array has size number of elements
	Postcondition: Elements of array are printed to the screen
		array is the array being printed with data type int
		size is the size of the array as int
 **/
void printArray(int array[], int size);

/**
	Copies positive elements first then negative elements from given array to a given result array in stable order.
	Precondition: Array has some size number of elements
	Postcondition: The given result array has positive numbers then negative numbers in order
**/
void negativesToEnd(int array[], int result[], int size);
int main()
{
	// Initialize array that need negatives to be at the end
	int A[10] = {8,-5,-4,2,9,10,-1,-7,1,6};
	// Initialize result array
	int result[10] = {};
	// Show elements of original array
	cout << "     Original Data     " << endl;
	cout << "------------------------" << endl;
	printArray(A, 10);
	// Call function that will perform the required task
	negativesToEnd(A, result, 10);
	// Make space on terminal
	cout << endl;
	// Output the elements from result array
	cout << "     Result Data     " << endl;
	cout << "------------------------" << endl;
	printArray(result, 10);
	return 0;
}

void printArray(int array[], int size)
{
	// Loop through array 
	for (int i = 0; i < size; i++)
	{
		// Print out each element with a space in between
		cout << array[i] << " ";
	}
	// Go to next line after outputing elemnts
	cout << endl;
}

void negativesToEnd(int array[], int result[], int size)
{
	// Index used to copy elements to result array
	int resultCounter = 0;
	// Loop through array to get copy positve numbers first into result
	for (int i = 0; i < size; i++)
	{
		// If current element is positive 
		if (array[i] > 0)
		{
			// Copy it to result array
			result[resultCounter] = array[i];
			// Increment resultCounter by 1
			resultCounter++;
		}
	}
	// Loop through array again to copy the negative numbers into result array
	for (int j = 0; j < size; j++)
	{
		// If current number is negativce
		if (array[j] < 0)
		{
			// Copy it to result array
			result[resultCounter] = array[j];
			// Increment resultCounter by 1
			resultCounter++;
		}
	}
}