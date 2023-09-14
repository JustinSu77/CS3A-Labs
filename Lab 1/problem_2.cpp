/**
	Date: 8/29/2023
	Author: Justin Su
	Purpose: Problem #2 of Lab #1

**/
#include <iostream>
using namespace std;
int main()
{
	// Declare variable that will store user input
	int userInput;
	// Prompt user for number to loop up to
	cout << "Enter n : ";
	// Get input from user
	cin >> userInput;
	// Declare variable to store the final result as 0
	int result = 0;
	// Loop from 1 to user input
	for (int i = 1; i <= userInput; i++)
	{
		// Loop rhrough numbers in between
		for (int j = 1; j <= i; j++)
		{
			// Add numbers to result
			result += j;
		}
	}
	// Output the result
	cout << "Sum : " << result << endl;
	
	return 0;
}