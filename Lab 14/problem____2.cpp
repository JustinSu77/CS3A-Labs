/**
	Date: 10/24/2023
	By: Justin Su
	Purpose: Problem #2 of Lab #14
**/
#include <iostream>
#include <cctype>
using namespace std;

/**
	Purpose: Count the characters in given c-string and return it.
	Input: word as a c-string
	Input Requirement: Given word is a c-string
	Result: The number of characters in c-string is returned
**/
int getCStringLength(char* word);

/**
	Purpose: Count how many times given c-string targetWord
			 is in c-string given sentence.
	Input: sentence as a c-string
		   targetWord as a c-string
	Input Requirement: Given sentence is a c-string
					   Given targetWord is a c-string
	Result: The number of times given targetWord appears
			in given sentence is returned
**/
int timesTargetWordAppearsInSentence(char* sentence, char* targetWord);

/**
	Purpose: Check if given wordOne is equal to wordTwo.
	Input: wordOne as a c-string
		   wordTwo as a c-string
	Input Requirement: Given wordOne is a c-string
					   Given wordTwo is a c-string
	Result: Return true if given wordOne and wordTwo are equal
			Return false otherwise
**/
bool wordsAreEqual(char* wordOne, char* wordTwo);

/**
	Purpose: Check if given word has a space.
	Input: word as a c-string
	Input Requirement: Given word is a c-string
	Result: Return true if given word has a space
			Return false otherwise
**/
bool hasSpace(char* word);

/**
	Purpose: Check if all characters in given sentence is just spaces
	Input: sentence as cstring
	Input Requirement: Given sentence as c-string
	Result: Return true if given word only has spaces
			Return false otherwise
**/
bool allSpaces(char* sentence);


/**
	Purpose: Return whether or not given
	c-string sentence only has any symbols
	Input: sentence as c-string
	Input Requirement: Given sentence is a c-string
	Result: Return true ifsentence has characters other
			than alphas, digits, and spaces
			Return false otherwise
**/
bool hasSymbols(char* sentence);

int main()
{
	// Declare and initialize const int 
	// for max size of c-string
	const int MAX = 100;
	// Declare and initialize  c-string 
	// to store sentence
	char sentence[MAX] = "";
	// Prompt user for sentence
	cout << "Enter a sentence : ";
	// Get user input and store in sentrence
	cin.getline(sentence, MAX);
	// If sentence only has spaces
	if (allSpaces(sentence))
	{
		// Output newline to terminal 
		// for readability
		cout << endl;
		// Notify
		cout << "Sentence only has spaces! Exiting!" << endl;
		// Exit progam with error code 1
		exit(1);
	}
	// If sentence has symbols
	if (hasSymbols(sentence))
	{
		// Output newline to terminal 
		// for readability
		cout << endl;
		// Notify
		cout << "Sentence has symbols! Exiting!" << endl;
		// Exit progam with error code 1
		exit(1);
	}
	// Output sentence that was entered 
	cout << "You entered : " << sentence << endl;
	// Output new line to terminal
	cout << endl;
	// Declare and initialize c-string to store the wordToReplace
	char wordToReplace[MAX] = "";
	// Prompt user for wordToReplace
	cout << "Enter a word to replace : ";
	// Get user input and save to wordToReplace
	cin.getline(wordToReplace, MAX);
	// Keep it simple by only allowing single word to be replaced
	// If wordToReplace has a space
	if (hasSpace(wordToReplace))
	{
		// Output newline to 
		cout << endl;
		// Notify
		cout << "Please only enter a single word to replace" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize c-string to store new word
	char newWord[MAX] = "";
	// Prompt user for word
	cout << "Enter a new word : ";
	// Get user input and save to newWord
	cin.getline(newWord, MAX);
	// Keep it simple by only allowing single word to be replaced
	// If newWord has a space
	if (hasSpace(newWord))
	{
		// Output newline to 
		cout << endl;
		// Notify
		cout << "Please only enter a single word for new word" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable to store length of wordToReplace
	int wordToReplaceLength = getCStringLength(wordToReplace);
	// Declare and initialize variable to store length of newWord
	int newWordLength = getCStringLength(newWord);
	// Declare and initialize variable to store number of 
	// times wordToReplace occurs in sentence
	int times = timesTargetWordAppearsInSentence(sentence, wordToReplace);
	// If wordToReplace is not in sentence
	if (times == 0)
	{
		// Output new line to terminal
		cout << endl;
		// Notify
		cout << wordToReplace << " does not exist in given sentence" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable to store sentence
	int sentenceLength = getCStringLength(sentence);
	// Declare and initialize variable to store 
	// the value to change sentenceLength by
	int changeValue = (newWordLength - wordToReplaceLength) * times;
	// Declare and initialize variable for the length 
	// of dynamic array as sum of sentenceLength and changeValue
	int outputLength = sentenceLength + changeValue;

	// Create dynamic char array output
	// Declare and initialize char dynamic array output
	char* output = new char[outputLength + 1];

	// Declare and initialize index variable 
	// to traverse output dynamic array
	int outputIndex = 0;
	// Declare and initialize inde variable to store index 
	// of first letter of a word
	int startingIndex = 0;
	// Loop through sentence c-string including null character terminator
	// so all words are printed out
	for (int i = 0; i <= sentenceLength; i++)
	{
		// If current character is a space or is the last character
		if (isspace(sentence[i]) || i == sentenceLength)
		{
			// Declare and initialize size for space dynamic array
			// OutputSize is the length of a segment of characters 
			// from first letter of a word to current index
			int outputSize = i - startingIndex;
			// Declare and initialize dynamic array to store word
			char* space = new char[outputSize + 1];
			// Declare and initialize index variable to copy 
			// characters from sentnece to space
			int copyIndex = startingIndex;
			// Loop through segment of characters
			for (int j = 0; j < outputSize; j++)
			{
				// Copy the characters from sentence to space dynamic array
				space[j] = sentence[copyIndex];
				// Increment copyIndex
				copyIndex++;
			}
			// Add null terimnator character to 
			// end to denote a word
			space[outputSize] = '\0';
			// Declare and initialize variable to copy characters from
			// newWord or space 
			int placementIndex = 0;
			// If word in space is equal to wordToReplace
			if (wordsAreEqual(space, wordToReplace))
			{
				// Copy newWord into output
				// While placementIndex is less than the length of newWord
				while (placementIndex < getCStringLength(newWord))
				{
					// Copy the character from newWord to output
					output[outputIndex] = newWord[placementIndex];
					// Increment outputIndex by 1
					outputIndex++;
					// Increment placementIndex by 1
					placementIndex++;
				}
			}
			// If word is not equal to wordToReplace
			else
			{
				// Copy word in space to output
				// While placementIndex is less than the length of space
				while (placementIndex < getCStringLength(space))
				{
					// Copy the characters from space to output			
					output[outputIndex] = space[placementIndex];
					// Increment outputIndex by 1
					outputIndex++;
					// Increment placementIndex by 1
					placementIndex++;

				}
			}
			// Add space to end of word in output
			// If there is still characters to copy
			if (outputIndex < outputLength)
			{
				// Add a space
				output[outputIndex] = ' ';
				// Increment outputIndex
				outputIndex++;
			}
			// Deallocate space dynamic array
			delete[] space;
			// Go to next character
			startingIndex = i + 1;
		}
	}
	// Add null terminator character at the end of output
	output[outputLength] = '\0';
	// Output newline to terminal for readability
	cout << endl;

	// Print out output to terminal
	cout << output << endl;

	// Deallcoate output dynamic array
	delete[] output;

	return 0;
}

int getCStringLength(char* word)
{
	// Declare and initialize 
	// index to traverse given 
	// word c-string
	int index = 0;
	// While character at current 
	// index is not null terminator character
	while (word[index] != '\0')
	{
		// Increment index
		index++;
	}
	// Return index
	return index;
}

int timesTargetWordAppearsInSentence(char* sentence, char* targetWord)
{
	// Declare and initialize variable to store length of sentence c-string
	int length = getCStringLength(sentence);
	// Declare and initialize variable that tracks when a word starts
	int startingIndex = 0;
	// Declare and initialize variable to track how many times 
	// given c-string targetWord occurs in given sentence
	int count = 0;
	// Loop through sentence c-string including null character terminator
	// so all words are printed out
	for (int i = 0; i <= length; i++)
	{
		// If a space is reached or the last character is read
		if (isspace(sentence[i]) || i == length)
		{
			// Store length of word
			int outputSize = i - startingIndex;
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
			// If output is equal to given c-string targetWord
			if (wordsAreEqual(output, targetWord))
			{
				// Increment count
				count++;
			}
			// Deallocate char dynamic array
			delete[] output;
			// Set startingIndex to first letter of next word
			startingIndex = i + 1;
		}
	}
	// Return count
	return count;
}

bool wordsAreEqual(char* wordOne, char* wordTwo)
{
	// Get length of given c-strings wordOne and wordTwo
	int wordOneLength = getCStringLength(wordOne);
	int wordTwoLength = getCStringLength(wordTwo);
	// If lengths are not equal, given c-strings
	// wordOne and wordTwo are not equal
	if (wordOneLength != wordTwoLength)
	{
		// Return false
		return false;
	}
	// Declare and initialize max number 
	// of characters, use wordOneLength since 
	// as this point the length of given c-strings are equal
	int compareTimes = wordOneLength;
	// Declare and initalize index to traverse 
	int index = 0;
	// While there are characters to check
	while (index < compareTimes)
	{
		// If the current character of given 
		// wordOne and wordTwo is not equal
		if (wordOne[index] != wordTwo[index])
		{
			// Return false
			return false;
		}
		// Increment index
		index++;
	}
	// Return true at end 
	return true;
}

bool hasSpace(char* word)
{
	// Declare and initialize 
	// variable to store length 
	// of given word c-string
	int length = getCStringLength(word);
	// Loop through the given 
	// word c-string
	for (int i = 0; i < length; i++)
	{
		// If current character is a space
		if (isspace(word[i]))
		{
			// Return true
			return true;
		}
	}
	// Otherwise return false
	return false;
}

bool allSpaces(char* sentence)
{
	// Declare and initialize 
	// variable to store the length 
	// of given sentence c-string
	int length = getCStringLength(sentence);
	// Loop through characters of given 
	// sentence c-string
	for (int i = 0; i < length; i++)
	{
		// If current character is not a space
		if (!isspace(sentence[i]))
		{
			// Return false
			return false;
		}
	}
	// Return true
	return true;
}

bool hasSymbols(char* sentence)
{
	// Declare and initialize variable 
	// to store length of given sentence c-string
	int length = getCStringLength(sentence);
	// Loop through all characters 
	// of given sentence c-string
	for (int i = 0; i < length; i++)
	{
		// If current character 
		// is not a letter, space, or digit
		if (!isalpha(sentence[i]) && !isspace(sentence[i])
			&& !isdigit(sentence[i]))
		{
			// Return true
			return true;
		}
	}
	// Otherwise return false
	return false;
}

