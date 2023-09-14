/**
    Date: 8/29/2023
    Arthor: Justin Su
    Purpose: Problem #3 for Lab #1
**/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // Declare variable for user input
    int userInput;
    // Prompt user for input
    cout << "Enter n : ";
    // Get input from user
    cin >> userInput;
    // Set number that will be displayed to start at 1
    int counter = 1;
    // Nested for loop
    // Outer loop up to userInput value
    for (int i = 1; i <= userInput; i++)
    {
        // Inner loop up to current outer loop value
        for (int j = 1; j <= i; j++)
        {
            // Output numbers with space between them
            cout <<  setw(3) << counter;
            // Increment the number to be printed
            counter++;
        }
        // Go to next line after printing numbers
        cout << endl;
    }

    return 0;
}

