/**
	Date: 9/14/2023
	By: Justin Su
	Purpose: Problem #2 of Lab #6
**/
#include <iostream>
using namespace std;
/**
	Fills given with random numbers from 1 to 15 and ensuring no repeats.
	Precondition: Array has some elements
	Postcondition: Array is filled with numbers ranging from 1 to 15 with no repeats
		array as array with data type of int
		arraySize as number of elements array will have as int
**/
void fillArrayWithNoDuplicates(int array[], int arraySize);

/**
	Fill given result array with unique elements from arrayOne and arrayTwo and sets the size of the result array.
	Precondition: Given arrayOne and ArrayTwo have some elements
	Postcondition: The elements that are unqiue in arrayOne and arrayTwo are copied to result array and its size is set
		arrayOne as array with data type of int
		arrayTwo as array with data type of int
		arraySize as the size of the arrayOne and ArrayTwo as int
		result as array with data type of int
		resultSize as the size of result array as a reference to an int
**/
void fillArrayWithUniqueIntegersFromTwoArrays(int arrayOne[], int arrayTwo[], int arraySize, int result[], int& resultSize);

/**
	Output elements of given array with comma after each element that is not the last element.
	Precondition: Given array has some elements
	Postcondition: The elements besides the last element of the array have been outputted with a comma after it to the terminal
		array as array with data type of int
		arraySize as size of given array as int
**/
void printArrayWithCommas(int array[], int arraySize);


/**
	Check if given targetElement is in given array.
	Precondition: Given array has some elements
	Postcondition: The index of the first occurences of targetElement is returned
				   If targetElement is not in array, -1 is returned
**/
int linearSearch(int array[], int arraySize, int targetElement);

/**
	Sort the array in ascending order using insertion sort.
	Precondition: Given array has size number of elements
	Postcondition: The elements of given array is sorted in ascending order
		array as array with int data type
		arraySize as number of elements array will have as int

**/
void insertionSort(int array[], int arraySize);

int main()
{
	// Random number generator 
	srand(time(0));
	// Declare and initialize arrays
	int A[10] = {};
	int B[10] = {};
	int C[10] = {};
	// Get size of array A and B
	int ASize = sizeof(A) / sizeof(int);
	int BSize = sizeof(B) / sizeof(int);

	// Fill arrays A and B with integers from 1 to 15 with no repears
	fillArrayWithNoDuplicates(A, ASize);
	fillArrayWithNoDuplicates(B, ASize);
	// Use pass by reference to change cSize so I do not have to deal with 0s being sorted if array C is not
	// filled all the way
	//Declare and initialize size of array C
	int CSize = 0;
	// Call function to for main task
	fillArrayWithUniqueIntegersFromTwoArrays(A, B, BSize, C, CSize);
	// Sort array C
	insertionSort(C, CSize);
	// Output the elements in array C with commas
	printArrayWithCommas(C, CSize);
	// Output how many elements in array C
	cout << "(" << CSize << " numbers)" << endl;

	return 0;
}

 
void fillArrayWithNoDuplicates(int array[], int size)
{
	// Keep track of integers has been seen, initialize all elements as false
	bool track[15] = {};
	// Loop through array
	for (int i = 0; i < size; i++)
	{
		// Get random integer
		int randomNumber = 1 + (rand() % 15);
		// If random integer already been seen
		if (track[randomNumber - 1])
		{
			// Keep getting a new random integer until it is one that has not been seen
			randomNumber = 1 + (rand() % 15);
			while (track[randomNumber - 1])
			{
				randomNumber = 1 + (rand() % 15);
			}
		}
		// Mark current random integer as seen
		track[randomNumber - 1] = true;
		// Set current array index to random integer
		array[i] = randomNumber;
	}
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

void fillArrayWithUniqueIntegersFromTwoArrays(int arrayOne[], int arrayTwo[], int arraySize, int result[], int& resultSize)
{
	// Index counter used to copy elements into result array
	int resultIndex = 0;
	// Loop through array one
	for (int i = 0; i < arraySize; i++)
	{
		// Set current element to variable
		int currentElement = arrayOne[i];
		// If currentElement does not exist in arrayTwo
		if (linearSearch(arrayTwo, arraySize, currentElement) == -1)
		{
			// Copy currentElement to result array
			result[resultIndex] = currentElement;
			// Increment resultIndex
			resultIndex++;
		}
	}

	// Loop through arrayTwo
	for (int i = 0; i < arraySize; i++)
	{
		// Set current element to variable
		int currentElement = arrayTwo[i];
		// If current element not in arrayOne
		if (linearSearch(arrayOne, arraySize, currentElement) == -1)
		{
			// Copy currentElement to result array
			result[resultIndex] = currentElement;
			// Increment resultIndex
			resultIndex++;
		}
	}
	// Set size of result array to how many elements have been copied
	resultSize = resultIndex;
}


int linearSearch(int array[], int arraySize, int targetElement)
{
	// Loop through array
	for (int i = 0; i < arraySize; i++)
	{
		// If current element is targetElement
		if (array[i] == targetElement)
		{
			// Return the current index
			return i;
		}
	}
	// Otherwise return -1
	return -1;
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