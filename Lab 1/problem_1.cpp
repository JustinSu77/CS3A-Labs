/**
	Date: 8/29/2023
	Author: Justin Su
	Purpose: Problem #1 for Lab #1

**/
#include <iostream>
using namespace std;
int main()
{
	// Declare user input variable
	int numberOfTimes;
	// Declare largestNumber variable
	int largestNumber;
	// Ask user for number of inputs to enter
	cout << "Enter the number of inputs : ";
	// Get user input
	cin >> numberOfTimes;
	// Run loop if given numberOfTimes is greater than 0
	if (numberOfTimes > 0)
	{
		// Counter for loop
		int counter = 1;
		// Variable to store user input
		int userInput;
		// Run loop while the current counter is less than or equal to numberOfTimes
		while (counter <= numberOfTimes)
		{
			// Prompt user for number
			cout << "Enter an integer #" << counter << " : ";
			// Get number from user
			cin >> userInput;
			// The first number user enters will be the largest number so far
			if (counter == 1)
			{
				largestNumber = userInput;
			}
			// If entered number is larger than current largestNumber, make it the new largestNumber
			if (userInput > largestNumber)
			{
				largestNumber = userInput;
			}
			// Increment counter variable
			counter++;
		}
		// Output new line for space
		cout << endl;
		// Output the largest entered number by user
		cout << "Max number : " << largestNumber << endl;
	}
	// If given numberOfTimes is 0 or negative, output message
	else
	{
		cout << "There will be no input " << endl;
	}
	
	return 0;
}