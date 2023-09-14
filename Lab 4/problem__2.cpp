/**
	Date: 9/7/2023
	By: Justin Su
	Purpose: Problem #2 for Lab #4
**/
#include <iostream>
using namespace std;

/**
	Print elements in given array to terminal.
	Precondtion: Given array has some elements
	Postcondition: Elements of given array is printed to terminal
		array as array with data type of int
		size as number of elements in array as int
**/
void printArray(int array[], int size);

/**
	Output the elements that are in all 3 given arrays.
	Precondition: The 3 given array has some elements
	Postcondition: The elements that are in all 3 arrays are printed to terminal
		A as array with data type int
		ASize as number of elements in array A as int
		B as array with data type int
		BSize as number of elements in array B as int
		C as array with data type int
		CSize as number of elements in array C as int
**/
void outputCommonElements(int A[], int ASize, int B[], int BSize, int C[], int CSize);
int main()
{
	// Declare and initialize the 3 arrays
	int A[] = { 1,2,3,4,5,6,7,8,9,10,11};
	int B[] = {3,6,10,11,13,15,16,17};
	int C[] = {1,2,3,5,6,11,15};
	// Declare and initialize the sizes of each of the 3 arrays
	int ASize = (sizeof(A) / sizeof(A[0])); 
	int BSize = (sizeof(B) / sizeof(B[0]));
	int CSize = (sizeof(C) / sizeof(C[0]));
	// Output elements in the array
	cout << "  < Original arrays > " << endl;
	cout << "-----------------------" << endl;
	cout << "A: ";
	printArray(A, ASize);
	cout << "B: ";
	printArray(B, BSize);
	cout << "C: ";
	printArray(C, CSize);
	cout << endl;
	// Output the element(s) that are in all 3 arrays
	cout << "Common elements : ";
	outputCommonElements(A, ASize, B, BSize, C, CSize);
	// Newline after printing the common elements
	cout << endl;;
	
	return 0;
}

void printArray(int array[], int size)
{
	// Loop through given array
	for (int i = 0; i < size; i++)
	{
		// Output the elements with spaces in between
		cout << array[i] << " ";
	}
	// Print a newline after printing elements
	cout << endl;
}

void outputCommonElements(int A[], int ASize, int B[], int BSize, int C[], int CSize)
{
	// Loop through array A
	for (int i = 0; i < ASize; i++)
	{
		// Loop through array B
		for (int j = 0; j < BSize; j++)
		{
			// Loop through array C
			for (int k = 0; k < CSize; k++)
			{
				// If a element present in all 3 arrays is found
				if (A[i] == B[j] && A[i] == C[k])
				{
					// Output the element with a space in front
					cout << C[k] << " ";
				}
			}
		}
	}
}