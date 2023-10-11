/**
    Date: 10/10/2023
    By: Justin Su
    Purpose: Problem #1 of Lab #12
**/
#include <iostream>
using namespace std;

/**
    Purpose: Outputs the elements of given array to terminal.
    Input: array as integer array
           arraySize as number of elements in given array as int
    Input Requirement: Given array should be an integer array
                       Number of elements of given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
                      
    Result: The elements of the given array is outputted to terminal
**/
void outputArray(int array[], int arraySize);

/**
    Purpose: Check if given targetElement exists in given array.
    Input: array as an integer array
           arraySize as number of elements in given array as int
           targetElement as integer to search for in array as int
    Input Requirement: Given array should be integer array
                       Number of elements in given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
                       Given targetElement should be an integer
    Result: Return true if given targetElement exists in array
            Return false otherwise
**/
bool elementExistsInArray(int array[], int arraySize, int targetElement);

/**
    Purpose: Change given position to index where new element being inserted will be at in given array.
    Input: array as integer array
           arraySize as number of elements in given array
           elementsToAdd as the integer that will be inserted into given array
           position as int reference to be change to the index that elementsToAdd will be in given array
    Input Requirement: Given array integer should be an array
                       Number of elements in given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
                       Given elementToAdd should be an integer
                       Given elementsToAdd should be positive
                       Given position should an integer
    Result: Given position integer reference will be set to the index 
            that given elementToAdd will be at in given array
**/
void getPositionToBeInSortedOrder(int array[], int arraySize, int elementToAdd, int& position);

/**
    Purpose: Shifts the elements to the right of the given startIndex one position to the right.
    Input: array as integer array
           arraySize as number of elements in given array as int
           startIndex as the index which the elements to the right will be shifted as int
    Input Requirement: Given array should be an integer array
                       Given Number of elements in given array should be equal to arraySize
                       Given arraySize should be an integer
                       Given arraySize should be a postive
                       Given startIndex should be an integer
                       Given startIndex should be be 0-arraySize-2
    Result: Elements in given array to the right of the given startIndex wil be shifted one position to the right

**/
void shiftRight(int array[], int arraySize, int startIndex);


/**
    Purpose: Fill given integer array with zeroes.
    Input: array as integer array
           arraySize as number of elements in given array as int
    Input Requirement: Given array should be an integer array
                       Number of elements in given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
    Result: Given array will be entirely filled with zeroes
**/
void fillArrayWithZeroes(int array[], int arraySize);

int main()
{
    // Declare and initialize static array with 5 elements 
    int array[5];
    // Declare and initialize size of array
    int arraySize = sizeof(array) / sizeof(int);
    // Fill array entirely of zeroes
    fillArrayWithZeroes(array, arraySize);
    // Declare and initialize variable to keep track of how many elements are in the array
    int elementsInArray = 0;
    // Declare and initialize variable to keep track of number of elements entered
    int counter = 1;
    // Keep looping while elementsInArray is less than arraySize
    while (elementsInArray < arraySize)
    {
        // Declare and initialize variable to store user input
        int elementToAdd = 0;
        // Prompt user for number
        cout << "Enter " << counter << "th number : ";
        // Store user input to variable
        cin >> elementToAdd;
        // If element is not in array
        if(!elementExistsInArray(array, arraySize, elementToAdd))
        {
          // Declare and initialize variable to store what index new element will be at in array  
          int position = 0;
          // Call function to get the position index
          getPositionToBeInSortedOrder(array, arraySize, elementToAdd, position);
          // If the element of the array at position index is not zero
          if (array[position] != 0)
          {
              // Shift the elements to the right of the position index
              shiftRight(array, arraySize, position);
          }
          // Set the elementToAdd to be at the position index of array
          array[position] = elementToAdd;
          // Increment elements in array counter
          elementsInArray++;
        }
        // Output the array
        outputArray(array, arraySize);
        // Increment counter that keeps tracks of numbers entered
        counter++;
    }
    
    return 0;
}

void outputArray(int array[], int arraySize)
{
    cout << "  ";
    // Loop through given  array 
    for (int i = 0; i < arraySize; i++)
    {
        // Output the elements with spaces in on either side
        cout << array[i] << "  ";
    }
    // Output newline to move terminal cursor to next line after outputting elements
    cout << endl;
}

bool elementExistsInArray(int array[], int arraySize, int targetElement)
{
    // Loop through given array
    for (int i = 0; i < arraySize; i++)
    {
        // If current element equal to given targetElement
        if (array[i] == targetElement)
        {
            // Return true
            return true;
        }
    }
    // Otherwise return false
    return false;
}

void getPositionToBeInSortedOrder(int array[], int arraySize, int elementToAdd, int& position)
{
   // Loop through array to second to last element
    for (int i = 0; i < arraySize - 1; i++)
    {
        // Declare and initialize variable to store the current element
        int current = array[i];
        // Declare and initialize variable to store element to the right of current element
        int next = array[i + 1];
        // If the current element is 0 or given elementToAdd is less than current element
        if (current == 0 || elementToAdd < current)
        {
            // Set given position to current index
            position = i;
            // Break out of function
            return;
        }
        // If next element is 0 or elementToAdd is larger than current element but smaller than next element
        if (next == 0 || (elementToAdd > current && elementToAdd < next))
        {
            // Set position to next index
            position = i + 1;
            // Break out of function
            return;
        }
    }

}

void shiftRight(int array[], int arraySize, int startIndex)
{
    // Loop through array backwards starting from 
    // last element of array and stopping at given startIndex
    for (int i = arraySize - 1; i >= startIndex; i--)
    {
        // Shift elements to be right
        array[i] = array[i - 1];
    }
}
 
void fillArrayWithZeroes(int array[], int arraySize)
{
    // Loop through array 
    for (int i = 0; i < arraySize; i++)
    {
        // Set elements to 0
        array[i] = 0;
    }
}