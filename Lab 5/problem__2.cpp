/**
	Date: 9/12/2023
	By: Justin Su
	Purpose: Problem #2 for Lab #5
**/
#include <iostream>
#include <iomanip>
using namespace std;

/**
	Reverses given array M.
	Precondition: Given array M has some elements
	Postcondition: Given array M elements are in reverse order
		M as array with data type int
		size as size of array M as int
**/
void reverseArray(int M[], int size);

/**
	Output the elements in given array M.
	Precondition: Given array M has some elements.
	Postcondition: Given array M elements are printed to the terminal
		M as array with data type int
		size as size of array M as int
**/
void printArray(int M[], int size);

int main()
{
	// Declare and initialize arrays
	int A[] = { 2,1,4,3,8,7 };
	int B[] = { 3,2,1,9,8,7,5,6,4 };
	int C[] = { 1,2,3 };

	// Get size of each array by dividing their total bytes by the size of int
	int sizeA = sizeof(A) / sizeof(int);
	int sizeB = sizeof(B) / sizeof(int);
	int sizeC = sizeof(C) / sizeof(int);
	
	// Reverse each of the 3 arrays
	reverseArray(A, sizeA);
	reverseArray(B, sizeB);
	reverseArray(C, sizeC);

	// Print the elements of the array
	printArray(A, sizeA);
	printArray(B, sizeB);
	printArray(C, sizeC);

	return 0;
}


void reverseArray(int M[], int size)
{
	// Store the index of first element
	int start = 0;
	// Store the index of last element
	int end = size - 1;
	// While the indices stored are at seperate ends, have not crossed
	while (start < end)
	{
		// Store element at start index
		int temp = M[start];
		// Set the element at start index to the element at end index
		M[start] = M[end];
		// Set the element at end index to the elemet stored in temp
		M[end] = temp;
		// Move start index to the right
		start++;
		// Move left index to the left
		end--;
	}
}

void printArray(int M[], int size)
{
	// Loop through array
	for (int i = 0; i < size; i++)
	{
		// Print element with space in front
		cout << setw(3) << M[i];
	}
	// Output newline to terminal
	cout << endl;
}