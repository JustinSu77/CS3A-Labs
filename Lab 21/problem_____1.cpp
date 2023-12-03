/**
	Date: 11/21/2023
	By: Justin Su
	Purpose: Problem #1 for Lab #21
**/
#include <iostream>
#include <string>
using namespace std;

/**
	Purpose: Get hour portion of time in 24-hour notation represented by string.
	Input: time as time in 24-hour notation as string
	Input Requirement: - Given time should represent time
					     written in 24-hour notation with a semi-colon
					   - Given time should be a string
	Result: The hour portion of given time in 
			24-hour notation is returned as integer
*/
int get_hour_from_string(string time);

/**
	Purpose: Get minute portion of time in 24-hour notation represented by string.
	Input: time as time in 24-hour notation as string 
	Input Requirement: - Given time should represent time written in 
					    24-hour notation with a semi-colon
					   - Given time should a string
	Result: The minute portion of given time in 
			24-hour notation is returned as integer
**/
int get_minute_from_string(string time);

int main()
{
	// Declare and initialize variable to store string given time
	string time = "";
	// Declare and initialize variable for do-while loop continuation
	char userInput = ' ';
	// Keep looping unless user enters N or n
	do 
	{	 
		// Ask user for time in 24-hour notation
		cout << "Enter time in 24-hour notation : ";
		// Store user input in time variable
		cin >> time;
		// Declare and initailize variable to store hour
		int hour = 0;
		// Declare and initialize variable to store minute
		int minute = 0;
		// try-catch to ensure hour and time are valid
		try
		{
			// Get hour part of given time string
			hour = get_hour_from_string(time);
			// Get minute part of given time string
			minute = get_minute_from_string(time);
			// If given hour is greater than 24
			if (hour > 24)
			{
				// Throw 
				throw "Hour should be less than 24";
			}
			// If given minute is greater than 60 
			if (minute > 60)
			{
				// Throw
				throw "Minute should be less than 60";
			}
			// If given hour is 0 and minute is 0
			if (hour == 0 && minute == 0)
			{
				// Output 12 AM
				cout << "12 AM" << endl;
			}
			// Otherwise
			else
			{
				// Declare and initialize variable to store meridiem of time
				string meridiem = "AM";
				// If hour is 12
				if (hour == 12)
				{
					// Set meridme to PM
					meridiem = "PM";
				}
				// If hour is greater than 12
				if (hour > 12)
				{
					// Subtract 12 from hour
					hour -= 12;
					// Set meridiem to 
					meridiem = "PM";
				}
				// Output time in 24-hour notation
				cout << hour << ":" << minute << " " << meridiem << endl;
			}
		}
		// If exception is thrown, catch it
		catch (const char* message)
		{
			// Output the exception message
			cout << message << endl;
		}
		// Ask user if they want to go again
		cout << "Again? (y/n) : ";
		// Store user input into userInput variable
		cin >> userInput;
		// Output new line to terminal for readability
		cout << endl;
	// Keep looping until user enters N or n
	} while (userInput != 'N' && userInput != 'n');
	
	return 0;
}

int get_hour_from_string(string time)
{
	// Declare and initialize variable to store 
	// index of semi-colon in given string
	int semi_colon_index = time.find(':');
	// Declare and initialize variable to store hour portion of string
	string hour = time.substr(0, semi_colon_index);
	// Return the hour portion as integer
	return stoi(hour);

}

int get_minute_from_string(string time)
{
	// Declare and initialize variable to store 
	// index of semi-colon in given string
	int semi_colon_index = time.find(':');
	// Declare and initialize variable to store minute portion of string
	string minute = time.substr(semi_colon_index + 1);
	// Return the minute portion as integer
	return stoi(minute);
}
