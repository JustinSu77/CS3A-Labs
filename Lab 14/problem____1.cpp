/**
	Date: 10/24/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #14
**/
#include <iostream>
using namespace std;

/**
	Purpose: Returns the number of characters in given word c-string.
	Input: word as c-string
	Input Requirements: Given word should be a c-string
	Result: The number of characters in given word c-string is returned.
**/
int getCStringLength(char* word);

int main()
{
	// Declare and initialize size of c-string as const int
	const int MAX = 100;
	// Declare and initialize sentence c-string 
	char sentence[MAX] = "";
	// Prompt user for sentence
	cout << "Enter a string : ";
	// Save user input into sentence c-string 
	cin.getline(sentence, MAX);
	// Print out what user entered
	cout << "You entered : " << sentence << endl;
	// Output newline to terminal for readability
	cout << endl;
	// Declare and initialize variable to store length of sentence c-string
	int length = getCStringLength(sentence);
	// Declare and initialize variable that tracks when a word starts
	int startingIndex = 0;
	// Loop through sentence c-string including null character terminator
	// so all words are printed out
	for (int i = 0; i <= length; i++)
	{
		// If a space is reached or the last character is read
		if (isspace(sentence[i]) || i == length)
		{
			// Declare and initialize size for space dynamic array
			// OutputSize is the length of a segment of characters 
			// from first letter of a word to current index
			int outputSize = i - startingIndex;
			
			// Create space for to save one word
			// Create char dynamic array with 1 more space needed
			// for null character terminator
			char* output = new char[outputSize + 1];
			
			// Declare and initialize copyIndex used to copy elements from 
			// sentence cstring to output dynamic array
			int copyIndex = startingIndex;
			// Loop through dynamic array
			for (int j = 0; j < outputSize; j++)
			{
				// Copy characters from sentence to output
				output[j] = sentence[copyIndex];
				// Increment copyIndex by 1
				copyIndex++;
			}
			// Set last character of dynamic array to null character terminator
			output[outputSize] = '\0';
			
			// Output char dynamic array
			 cout << output << endl;
			
			 // Deallocate char dynamic array
			delete[] output;
			// Set startingIndex to first letter of next word
			startingIndex = i + 1;
		}
	}

	return 0;
}

int getCStringLength(char* word)
{
	// Declare and initialize variable to 
	// access characters of given 
	// word c-string
	int index = 0;
	// Loop through characters 
	// of given word
	while (word[index] != '\0')
	{
		// Increment index;
		index++;
	}
	// Return index
	return index;
}


