/**
	Date: 8/31/2023
	By: Justin Su
	Purpose: Problem #2 for Lab #2
**/
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
	// Seed random to ensure different random numbers each time
	srand(time(0));
	// Declare variable for user input
	char userInput;
	// Do loop as program always runs first before prompting repeat
	do
	{
		// Generate random numbers from 0-9 for each number
		int firstRandomNumber = rand() % 10;
		int secondRandomNumber = rand() % 10;
		int thirdRandomNumber = rand() % 10;
		    
		// Output the 3 random numbers with spaces between
		cout << firstRandomNumber << setw(4) << secondRandomNumber << setw(4) << thirdRandomNumber << endl;
		// If all 3 random numbers match, output jackpot
		if (firstRandomNumber == secondRandomNumber && firstRandomNumber == thirdRandomNumber)
		{
			cout << "Jackpot!!!" << endl;
		}
		// There is only 3 possible arrangements to check for match 2 for 3 numbers
		// 1 1 0
		// 1 0 1
		// 0 1 1
		// If statement is based on the above relation
		else if ((firstRandomNumber == secondRandomNumber) ||
			(firstRandomNumber == thirdRandomNumber) ||
			(secondRandomNumber == thirdRandomNumber))
		{
			cout << "Matched 2!!" << endl;
		}
		// If none of the 3 numbers match, output message
		else
		{
			cout << "No match" << endl;
			

		}
		// Output a line to seperate result from prompt
		cout << "--------------------" << endl;
		// Skip a line in terminal
		cout << endl;
		// Prompt user if they want to play again
		cout << "Play again (y/n)?: ";
		// Get input from user
		cin >> userInput;
		// Loop will keep running as long as user does not enter N or n
	} while (userInput != 'N' && userInput != 'n');
	
	return 0;
}

