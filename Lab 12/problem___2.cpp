/**
    Date: 10/10/2023
    By: Justin Su
    Purpose: Problem #2 of Lab #12
**/
#include <iostream>
using namespace std;

/**
    Purpose: Outputs the elements of given dynamic integer array to terminal.
    Input: array as dynamic integer array
           arraySize as number of elements in given dynamic integer array as int
    Input Requirement: Given array should be a dynamic integer array
                       Number of elements of given dynamic integer array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive

    Result: The elements of the given dynamic integer array is outputted to terminal
**/
void outputArray(int* array, int arraySize);

/**
    Purpose: Check if given targetElement exists in given dynamic integer array.
    Input: array as a dynamic integer array
           arraySize as number of elements in given array as int
           targetElement as integer to search for in array as int
    Input Requirement: Given array should be a dynamic integer array
                       Number of elements in given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
                       Given targetElement should be an integer
    Result: Return true if given targetElement exists in array
            Return false otherwise
**/
bool elementExistsInArray(int* array, int arraySize, int targetElement);

/**
    Purpose: Change given position to index where new element being inserted will be at in given dynamic integer array.
    Input: array as dynamic integer array
           arraySize as number of elements in given array
           elementsToAdd as the integer that will be inserted into given array
           position as int reference to be change to the index that elementsToAdd 
           will be in given dynamic integer array
    Input Requirement: Given array integer should be a dynamic integer array
                       Number of elements in given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
                       Given elementToAdd should be an integer
                       Given elementsToAdd should be positive
                       Given position should an integer
    Result: Given position integer reference will be set to the index
            that given elementToAdd will be at in given array
**/
void getPositionToBeInSortedOrder(int* array, int arraySize, int elementToAdd, int& position);

/**
    Purpose: Shifts the elements in given array to the right of the given startIndex one position to the right.
    Input: array as dynamic integer array
           arraySize as number of elements in given array as int
           startIndex as the index which the elements to the right will be shifted as int
    Input Requirement: Given array should be a dynamic integer array
                       Given Number of elements in given dynamic integer array should be equal to arraySize
                       Given arraySize should be an integer
                       Given arraySize should be a postive
                       Given startIndex should be an integer
                       Given startIndex should be be 0-arraySize-2
    Result: Elements in given dynamic integer array to the right of the given 
            startIndex wil be shifted one position to the right

**/
void shiftRight(int* array, int arraySize, int startIndex);


/**
    Purpose: Fill given integer array with zeroes.
    Input: array as dynamic integer array
           arraySize as number of elements in given array as int
    Input Requirement: Given array should be a dynamic integer array
                       Number of elements in given array should be equal to given arraySize
                       Given arraySize should be an integer
                       Given arraySize should be positive
    Result: Given array will be entirely filled with zeroes
**/
void fillArrayWithZeroes(int* array, int arraySize);

/**
    Purpose: Return new dynamic integer array that is double the size of given dynamic integer array with its elements.
    Input: array as dynamic integer array
           arraySize as the number of elements in given dynamic integer array as int reference
    Input Requirement: array should be an integer dynamic array
                       Number of elements in array should be equal to arraySize
                       arraySize should be postive
                       arraySize should be an integer
    Result: Dynamic integer array with double the size of given dynamic integer array but has its elements is returned
**/
int* doubleArraySize(int* array, int& arraySize);

int main()
{
    // Declare and initialize varaible to store initial array size
    int n;
    // Prompt user for initial size of array
    cout << "Enter initial size of an array : ";
    // Store user input in n
    cin >> n;
    // Declare and store the old size of array
    int initialSize = n;
    // Declare and initialize dynamic integer array with initialize size of n
    int* A = new int[n];
    // Fill array with 0s
    fillArrayWithZeroes(A, n);
    // Declare and initialize counter to keep track of elements in array
    int elementsInArray = 0;
    // Declare and intialize counter that keeps track of how many numbers have been entered by user
    int counter = 1;
    // Flag to ensure loop runs only once
    bool arrayHasDoubled = false;
    // Keep looping while elementsInArray is less than the initialize array sized doubled
    while (elementsInArray < initialSize)
    {
        // Declare and initialize variable to store user input
        int elementToAdd = 0;
        // Promot user for number to be added into array
        cout << "Enter " << counter << "th number : ";
        // Store user input
        cin >> elementToAdd;

        // If given number from user does not exist in array
        if (!elementExistsInArray(A, n, elementToAdd))
        {
            // Declare and initialize variable for position the element to be added will be at in array
            int position = 0;
            // Call function to get the position
            getPositionToBeInSortedOrder(A, n, elementToAdd, position);
            // If the element of array at position is not zero
            if (A[position] != 0)
            {
                // Shift the elements of the array
                shiftRight(A, n, position);
            }
            // Set the element of array at position index to be the number from user
            A[position] = elementToAdd;
            // Increment counter that keeps track of how many elements are in array by 1
            elementsInArray++;
        }
        // If array is full and has already doubled its size once already
        if (elementsInArray == initialSize && arrayHasDoubled)
        {
            // Output the elements
            outputArray(A, n);
            // Get out of loop
            break;
        }
        // If array is full
        if (elementsInArray == initialSize)
        {
            // Create new dynamic integer array with double the size but has elements of the old array
            int* temp = doubleArraySize(A, n);
            // Deallocate the old array
            delete[] A;
            // Set array pointer to new dynamic integer array
            A = temp;
            // Double the initialsize
            initialSize = initialSize * 2;
            // Set flag to loop only once to true
            arrayHasDoubled = true;
        }
        // Output array
        outputArray(A, n);
        // Increment counter that keeps track of how many numbers have been entered by user by 1
        counter++;
    }
    // Deallocate array
    delete[] A;
    
    return 0;
}

void outputArray(int* array, int arraySize)
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

bool elementExistsInArray(int* array, int arraySize, int targetElement)
{
    // Loop through given dynamic integer array
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

void getPositionToBeInSortedOrder(int* array, int arraySize, int elementToAdd, int& position)
{
    // Loop through given dynamic integer array to second to last element
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

void shiftRight(int* array, int arraySize, int startIndex)
{
    // Loop through given dynamic integer array backwards starting from 
    // last element of array and stopping at given startIndex
    for (int i = arraySize - 1; i >= startIndex; i--)
    {
        // Shift elements to be right
        array[i] = array[i - 1];
    }
}

void fillArrayWithZeroes(int* array, int arraySize)
{
    // Loop through dynamic integer array 
    for (int i = 0; i < arraySize; i++)
    {
        // Set elements to 0
        array[i] = 0;
    }
}

int* doubleArraySize(int* array, int& arraySize)
{
    // Save the old arraySize
    int oldSize = arraySize;
    // Double arraySize
    arraySize = arraySize * 2;
    // Create new integer dynamic array with size of arraySize
    int* newArray = new int[arraySize];
    // Fill newArray with 0s
    fillArrayWithZeroes(newArray, arraySize);
    // Copy the elements from old array to newArray
    for (int i = 0; i < oldSize; i++)
    {
        // Copy elements
        newArray[i] = array[i];
    }
    // Return newArray
    return newArray;
}