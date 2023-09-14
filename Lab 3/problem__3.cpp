/**
	Date: 9/5/2023
	By: Justin Su
	Purpose: Problem #3 for Lab #3
**/
#include <iostream>
#include <random>
using namespace std;

/**
	Fills given with random numbers from 1 to 15 and ensuring no repeats
	Precondition: Array has some elements
	Postcondition: Array is filled with numbers ranging from 1 to 15
		array as array with data type of int
		size as number of elements array will have as int
		low as the lower bound of rand as int
		hight as the upper bound of rand as int 
**/
void fillArrayWithNoDuplicates(int array[], int size, int low, int high);

/**
	Outputs the elements of the given array to terminal.
	Precondition: Array has some elements
	Postcondition: The elements of the array are outputted to the terminal
		array as array with data type of int
		size as number of elements array will have as int
**/
void displayArray(int array[], int size);
int main()
{
	// Seed random number generator
	srand(time(0));
	// Declare array of size 10
	int A[10];
	// Store userinput as char to repeat program
	char userInput;
	// Do loop to run program once then prompt user to repeat
	do
	{
		// Fill declared array with integers from 1 to 15
		fillArrayWithNoDuplicates(A, 10, 1, 15);
		// Display the integers to terminal
		displayArray(A, 10);
		// Prompt user to repeat progrma again
		cout << "More (y/n)? ";
		// Get user input
		cin >> userInput;
	// Repeat while char input is not N or n
	} while (userInput != 'N' && userInput != 'n');
	return 0;
}

void fillArrayWithNoDuplicates(int array[], int size, int low, int high)
{
	// Keep track of integers has been seen, initialize all elements as false
	bool track[15] = {};
	// Loop through array
	for (int i = 0; i < size; i++)
	{
		// Get random integer
		int randomNumber = low + (rand() % high);
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

void displayArray(int array[], int size)
{
	// Loop through array
	for (int i = 0; i < size; i++)
	{
		// Output the elements with space in between
		cout << array[i] << " ";
	}
	// Newline after outputting elements
	cout << endl;
}