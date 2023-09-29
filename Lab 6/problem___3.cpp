/**
	Date: 9/14/2023
	By: Justin Su
	Purpose: Problem #3 of Lab #6
**/
#include <iostream>
#include <random>
using namespace std;

/**
	Output elements of given array with comma after each element that is not the last element.
	Precondition: Given array has some elements
	Postcondition: The elements besides the last element of the array have been outputted with a comma after it to the terminal
		array as array with data type of int
		arraySize as size of given array as int
**/
void printArrayWithCommas(int array[], int arraySize);

/**
	Fill given array with random integers from 1 to 15.
	Precondition: Given array has some elements
	Postcondition: Given array is filled with random integers from 1 to 15
		array as array with data type int
		arraySize as number of elements of array as int
**/
void fillArrayWithRandomIntegers(int array[], int arraySize);

/**
	Copy elements that exists in both given arrayOne and arrayTwo to result array.
	Precondition: arrayOne and arrayTwo have some elements
	Postcondition: Elements that are both in arrayOne and arrayTwo are copied to result array and resultSize is set to the number of				 elements in result array
		arrayOne as array with data type of int
		arrayOneSize as number of elements in arrayOne as int
		arrayTwo as array with data type of int
		result as array with data type of int
		resultSize as the number of elements in result array as int
**/
void fillArrayWithIntegersThatExistInBothGivenArrays(int arrayOne[], int arrayOneSize, int arrayTwo[], int arrayTwoSize, int result[], int& resultSize);

/**
	Sort the array in ascending order using insertion sort.
	Precondition: Given array has size number of elements
	Postcondition: The elements of given array is sorted in ascending order
		array as array with int data type
		arraySize as number of elements array will have as int

**/
void insertionSort(int array[], int arraySize);

/**
	Copy elements from given array to given target array.
	Precondition: Given array has some elements
	Postcondition: Given target array now has same elements as given array
		array as array with data type of int
		arraySize as number of elements of array as int
		result as array with data type of int

**/
void copyElementsFromOneSameSizeArrayToAnother(int array[], int arraySize, int result[]);

int main()
{
	srand(time(0));
	// Declare and initialize arrays
	int A[10] = {};
	int B[10] = {};
	int C[10] = {};
	// Get size of arrays A and B
	int ASize = sizeof(A) / sizeof(int);
	int BSize = sizeof(B) / sizeof(int);
	// Set size of array C to 0, change it with pass by reference
	int CSize = 0;
	// Fill arrays A and B with random integer with 1 to 15
	fillArrayWithRandomIntegers(A, ASize);
	fillArrayWithRandomIntegers(B, BSize);
	// Call function to complete main task
	fillArrayWithIntegersThatExistInBothGivenArrays(A, ASize, B, BSize, C, CSize);
	// Sort the array C
	insertionSort(C, CSize);
	// Output the elements in array C
	printArrayWithCommas(C, CSize);
	// Output the number of elements of array C
	cout << "(" << CSize << " numbers)" << endl;

	return 0;
}

void printArrayWithCommas(int array[], int arraySize)
{
	// Loop through arary
	for (int i = 0; i < arraySize; i++)
	{
		// If current element is the last element
		if (i == arraySize - 1)
		{
			// Output element without comma after it
			cout << array[i] << " ";
		}
		// If current element is not the last element
		else
		{
			// Output element with a comma after it
			cout << array[i] << ", ";
		}
	}
}


void fillArrayWithRandomIntegers(int array[], int arraySize)
{
	// Loop through array
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and initialize randomNumber from 1 to 15
		int randomNumber = (rand() % 15) + 1;
		// Set current element in array to randomNumber
		array[i] = randomNumber;
	}
}

void fillArrayWithIntegersThatExistInBothGivenArrays(int arrayOne[], int arrayOneSize, int arrayTwo[], int arrayTwoSize, int result[], int& resultSize)
{
	// Create a temporary array
	int temp[10] = {};
	// Copy the elements from arrayTwo to temporary array
	copyElementsFromOneSameSizeArrayToAnother(arrayTwo, arrayTwoSize, temp);
	// Declare and initialize index used to copy elements to result
	int resultIndex = 0;
	// Loop through arrayOne
	for (int i = 0; i < arrayOneSize; i++)
	{
		// Loop through temp array
		for (int j = 0; j < arrayTwoSize; j++)
		{
			// If same element is found
			if (arrayOne[i] == temp[j])
			{
				// Copy the current element to result array
				result[resultIndex] = arrayOne[i];
				// Increment resultIndex
				resultIndex++;
				// Set the element that was equal to current index of temp to -1
				temp[j] = -1;
				// Get out of loop once a element in both arrays are found
				break;
			}
		}
	}
	// Set number of elements to result array to be number of elements copied
	resultSize = resultIndex;
}

void insertionSort(int array[], int arraySize)
{	
	// Declare variables used
	int i, j, key;
	// Loop through array
	for (i = 1; i < arraySize; i++)
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

void copyElementsFromOneSameSizeArrayToAnother(int array[], int arraySize, int result[])
{
	// Loop through array
	for (int i = 0; i < arraySize; i++)
	{
		// Copy the elements from given array to given result array
		result[i] = array[i];
	}
}
