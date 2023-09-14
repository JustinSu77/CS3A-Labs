/**
    Date: 8/31/2023
    By: Justin Su
    Purpose: Problem #3 for Lab #2

    No Sets or Maps
**/
#include <iostream>
#include <random>
using namespace std;

/**
    Fills given array with random numbers from 1 t0 20.
    Pre-condition: Array has some values or garbage values
    Post-condition: Array is filled with random numbers from 1 to 20
        array as array with data type int
        size as size of given array
**/
void fillArray(int array[], int size);
/**
    Outputs the elements of the given array.
    Pre-condition: Array has elements in it
    Post-condition: The elements of the array is printed to the terminal
        array as array with data type int
        size as size of given array

**/

void displayArray(int array[], int size);

/**
    Sorts array using Insertion Sort.
    Pre-condition: Array has integer elements in it
    Postcondition: Array elements is sorted in asecending order
        array as array with data type int
        size as size of given array
**/
void insertionSort(int array[], int size);

/**
    Display the elements that occur an odd number of times along with how many times they occur.
    Pre-condition: Array has integer elements in it
    Post-condition: The elements and how many times they occured are printed to console
        array as array with data type int
        size as size of given array
**/
void displayOddOccurences(int array[], int size);

int main()
{
    // Seed random number generator
    srand(time(0));
    // Declare integer array with 20 elements
    int array[20];
    // Fill array with random numbers from 1 to 20
    fillArray(array, 20);
    // Output the elements of the array
    cout << "< Original Data >" << endl;
    displayArray(array, 20);
    // Sort the array
    insertionSort(array, 20);
    // Output the elements that occur odd number of times and how many times
    cout << "< Result >" << endl;
    displayOddOccurences(array, 20);

    return 0;
}

void fillArray(int array[], int size)
{
    // Loop through array
    for (int i = 0; i < size; i++)
    {
        // Get random number from 1 to 20
        int randomNumber = (rand() % 20) + 1;
        // assign current array element to random number
        array[i] = randomNumber;
    }
}

void displayArray(int array[], int size)
{
    // Loop through array
    for (int i = 0; i < size; i++)
    {
        // Output each element with a space in between
        cout << array[i] << " ";
    }
    // Output new line
    cout << endl;
}
void insertionSort(int array[], int size)
{
    // Declare variables used
    int i, j, key;
    // Loop through array
    for (i = 1; i < size; i++)
    {
        // Set key to current element
        key = array[i];
        // Set j to element before current element
        j = i - 1;
        // Compare the key element to the element before it
        // If key element is smaller keep comparing with each of the elements before it
        // Swap the key element with the its previous element if it is smaller
        while (j >= 0 && array[j] > key)
        {
            // Swap element
            array[j + 1] = array[j];
            // Go to element before
            j--;
        }
        // Insert key element into position where it is greater than the element before it
        array[j + 1] = key;
    }
}

void displayOddOccurences(int array[], int size)
{

    // Variable to count occcurences of each element

    int occurences = 1;
    /* int i;*/
     // Loop through the array
    for (int i = 0; i < size; i++)
    {
        // Declare variable to store index of next element
        int next = i + 1;
        // Keep scanning as long the elements after the current element is equal
        while (array[i] == array[next])
        {
            // Increment occurences
            occurences++;
            // Go to next element
            next++;
        }
        // If the current element occurences once or an odd numbered of times
        if (occurences == 1 || occurences % 2 == 1)
        {
            // Outout the current element and its occurences
            cout << array[i] << " (" << occurences << ") " << endl;
        }
        // Reset occurences
        occurences = 1;
        // Ensures current index starts after the sequence of same elements that was checked
        i = next - 1;
    }
}
