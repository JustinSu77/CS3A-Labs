/**
	Date: 9/12/2023
	By: Justin Su
	Purpose: Problem #3 for Lab #5
**/
#include <iostream>
#include <iomanip>
using namespace std;
/**
	Output the elements in given array.
	Precondition: Given array has some elements
	Postcondition: Elements of given array is printed to terminal
		array as array with data type of int
		arraySize as size of array as int
**/
void printArray(int array[], int arraySize);

/**
	Reverse parts of array by treating every n elements as an array to be reversed.
	Precondition: Given array has some elements
	Postcondition: Parts of array are reversed
		array as array with data type of int
		arraySize as size of array as int
		n as number of elements to be treated as a array as int

**/
void reversePartArray(int array[], int arraySize, int n);

int main()
{
	// Declare and initialize arrays
	int A[] = {2,1,4,3,8,7};
	int B[] = { 3,2,1,9,8,7,5,6 };
	int C[] = { 4,3,6,8,7,5,2,1,9,0,1,2,3 };
	int D[] = { 1,2,3,4,5 };
	
	// Get the size for each array by dividing the size of each array by the size of int
	int sizeA = sizeof(A) / sizeof(int);
	int sizeB = sizeof(B) / sizeof(int);
	int sizeC = sizeof(C) / sizeof(int);
	int sizeD = sizeof(D) / sizeof(int);
	
	// Output the elements in each array
	cout << " < Original Array >" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "A : ";
	printArray(A, sizeA);
	cout << "B : ";
	printArray(B, sizeB);
	cout << "C : ";
	printArray(C, sizeC);
	cout << "D : ";
	printArray(D, sizeD);
	cout << endl;

	// Call function to reverse part of each array
	reversePartArray(A, sizeA, 2);
	reversePartArray(B, sizeB, 3);
	reversePartArray(C, sizeC, 5);
	reversePartArray(D, sizeD, 7);
	
	// Output each array
	cout << " < Reversed Array >" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "A : ";
	printArray(A, sizeA);
	cout << "B : ";
	printArray(B, sizeB);
	cout << "C : ";
	printArray(C, sizeC);
	cout << "D : ";
	printArray(D, sizeD);

	return 0;
}


void printArray(int array[], int arraySize)
{
	// Loop through array 
	for (int i = 0; i < arraySize; i++)
	{
		// Print element of arraya with space before it
		cout << setw(3) << array[i];
	}
	cout << endl;
}

void reversePartArray(int array[], int arraySize, int n)
{
	// Set counter to track how many elements have been traversed
	int elementsSeen = 0;
	for (int i = 0; i < arraySize; i++)
	{
		// Increment elementsSeen by 1
		// Increment first to prevent off by 1
		elementsSeen++;
		// If elementsSeen is equal to given n
		if (elementsSeen == n)
		{
			// Set start index to be n elements before current index
			int start = i - (n - 1);
			// Set current index as end
			int end = i;
			// Reverse part of array
			// Keep looping while start and end do not cross 
			while (start < end)
			{
				// Store element at start index of array
				int temp = array[start];
				// Set element at start index of array to be the element at start index
				array[start] = array[end];
				// Set element at end to element stored at temp
				array[end] = temp;
				// Move start index to the right
				start++;
				// Move end index to the left
				end--;
			}
			// Set elementsSeen to 0
			elementsSeen = 0;
		}
	}
}
