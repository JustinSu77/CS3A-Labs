/**
	Date: 9/12/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #5
**/
#include <iostream>
using namespace std;

/**
	Outputs the elements that are in both given arrayOne and arrayTwo but are not in given arrayThree.
	Precondition: Given arrayOne, arrayTwo, arrayThree have some elements
	Postcondition: The elements that are in both arrayOne and arrayTwo but not in arrayThree are outputted to terminal.
		arrayOne as array with data type of int
		arrayOneSize as size of arrayOne as int
		arrayTwo as array with data type of int
		arrayTwoSize as size of arrayTwo as int
		arrayThree as array with data type of int
		arrayThreeSize as size of arrayThree as int
**/
void outputCommonElementsInTwoArraysNotInThirdArray(int arrayOne[],int arrayOneSize,int arrayTwo[],int arrayTwoSize, int arrayThree[], int arrayThreeSize);

int main()
{
	// Declare and initialize 3 arrays
	int A[] = {1,2,3,4,5,6,7,8,9,10,11};
	int B[] = {3,6,10,11,13,15,16,17};
	int C[] = {1,2,3,5,7,11,15};

	// Get size of each array by dividing their total bytes by the size of int
	int ASize = sizeof(A) / sizeof(int);
	int BSize = sizeof(B) / sizeof(int);
	int CSize = sizeof(C) / sizeof(int);

	//Output the elements that are in both array A and B but not in array C
	cout << "< Numbers in A and B, not C >" << endl;
	outputCommonElementsInTwoArraysNotInThirdArray(A,ASize, B, BSize, C, CSize);
	cout << endl;
	//Output the elements that are in both array B and C but not in array A
	cout << "< Numbers in B and C, not A >" << endl;
	outputCommonElementsInTwoArraysNotInThirdArray(B, BSize, C, CSize, A, ASize);
	cout << endl;
	//Output the elements that are in both array A and C but not in array B
	cout << "< Numbers in A and C, not B >" << endl;
	outputCommonElementsInTwoArraysNotInThirdArray(A, ASize, C, CSize, B, BSize);
	 
	
	return 0;
}

void outputCommonElementsInTwoArraysNotInThirdArray(int arrayOne[], int arrayOneSize, int arrayTwo[], int arrayTwoSize, int arrayThree[], int arrayThreeSize)
{
	// Loop through arrayOne
	for (int i = 0; i < arrayOneSize; i++)
	{
		// Loop through arrayTwo
		for (int j = 0; j < arrayTwoSize; j++)
		{
			// If element that are in both arrayOne and arrayTwo is found
			if (arrayOne[i] == arrayTwo[j])
			{
				// Check if the element exists in arrayThree
				// set boolean flag to true, assume element is not in arrayThree
				bool notInArrayThree = true;
				// Loop through arrayThree
				for (int k = 0; k < arrayThreeSize; k++)
				{
					// If the element is found
					if (arrayThree[k] == arrayOne[i])
					{
						// Set flag to false
						notInArrayThree = false;
						// No need to check array entirely anymore
						break;
					}
				}
				// If after searching arrayThree the flag is still true
				if (notInArrayThree)
				{
					// Output the current element
					cout << arrayOne[i] << " ";
				}
			}
		}
	}
	// Output newline to terminal so next output to terminal will be on next line
	cout << endl;
}
