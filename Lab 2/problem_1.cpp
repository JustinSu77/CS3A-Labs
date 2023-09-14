/**
	Date: 8/31/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #2
**/
#include <iostream>
using namespace std;
int main() 
{	
	// Declare char variable for user input as operators will be chars
	char userInput;
	// Declare variable for first integer user will enter
	int firstInteger;
	// Declare variable for second integer user will enter
	int secondInteger;
	// Prompt user for an operator to enter
	cout << "Enter an operator (+, -, *, /, %) : ";
	// Get user input for operator
	cin >> userInput;
	// If the user is a valid operator run the main code
	if (userInput == '+' || userInput == '-' || userInput == '*' || userInput == '/' || userInput == '%')
	{
		// Prompt user for two integers
		cout << "Enter two integers : ";
		// Get the 2 integers from user
		cin >> firstInteger >> secondInteger;
		// Decide what operations to do on the 2 integers based on user inputted operator
		switch (userInput)
		{
			// Case for when user input is -
			case '-':
				cout << "===> " << firstInteger << " " << userInput << " " << secondInteger << " = " << firstInteger - secondInteger << endl;
				break;
			// Case for when user input is *	
			case '*':
				cout << "===> " << firstInteger << " " << userInput << " " << secondInteger << " = " << firstInteger * secondInteger << endl;
				break;
			// Case for when user input is /
			case '/':
				cout << "===> " << firstInteger << " " << userInput << " " << secondInteger << " = " << firstInteger / secondInteger << endl;
				break;
			// Case for when user input is %
			case '%':
				cout << "===> " << firstInteger << " " << userInput << " " << secondInteger << " = " << firstInteger % secondInteger << endl;
				break;
			// Default case is +
			default:
				cout << "===> " << firstInteger << " " << userInput << " " << secondInteger << " = " << firstInteger + secondInteger << endl;
				break;
		}
	}
	// If user enters an invalid operator, output message below and exit program
	else
	{
		cout << "Wrong operator" << endl;
	}
	
	return 0;
}