/**
	Date: 11/7/2023
	By: Justin Su
	Purpose: Problem #1 for Lab #18
**/
#include <iostream>
using namespace std;
/**
	Purpose: Return the result of given base raised to
			 given power using recursion as integer.
	Input: - base as integer to be raised as integer
		   - exponent as power to raise base to as integer
	Input Requirement: - Given base is an integer
					   - Given exponent is an integer
					   - Given exponent should be greater
						 than or equal to 0
	Result: - If given base is 0 and given
			  exponent is <= 0, notify and
			  exit program with error code 1
			- If given exponent is < 0, notify and
			  exit program with error code 1
			- If given base is 0, return 0
			- If given exponent is 0, return 1
			- Given base raised to given exponent is returned

**/
int power(int base, int exponent);

int main()
{

	// Declare and initialize variable to store base from user
	int base = 0;
	// Get the base number from user
	cout << "Enter a base number : ";
	// Save user input to base
	cin >> base;
	// Declare and initialize variable to store exponent from user
	int exponent = 0;
	// Get the exponent number from user
	cout << "Enter an exponent : ";
	// Save user input to exponent
	cin >> exponent;
	// Output the result
	cout << base << "^" << exponent << " = " << power(base, exponent);
	// Output newline to terminal for readability 
	cout << endl;

	return 0;
}

int power(int base, int exponent)
{
	// If given base is 0 and exponent is <= 0
	if (base == 0 && exponent <= 0)
	{
		// Notify
		cout << "power: When given base is 0,"
			<< " given exponent should be > 0" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// If given exponent is negative
	if (exponent < 0)
	{
		// Notify
		cout << "power: This version only allows exponent " <<
			"that is greater than or equal to 0" << endl;
		// Exit program with error code 1
		exit(1);
	}

	// If given base is 0
	if (base == 0)
	{
		// Return 0
		return 0;
	}

	// If given exponent is or becomes 0
	if (exponent == 0)
	{
		// Return 1
		return 1;
	}
	// Otherwise recursively call this function by 
	// decreaseing given exponent by 1 and mutiplying 
	// the result of the function by the given base
	return power(base, exponent - 1) * base;
}
