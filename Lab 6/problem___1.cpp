/**
	Date: 9/14/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #6
**/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/**
	Print the id, name, and score of the student with the highest score in given arrays.
	Precondition: Given idArray, nameArray, scoreArray are not empty
	Postcondition: The id, name, and score of the student with highest score is printed to terminal
		idArray as a array with data type of int
		nameArray as a array with data type of string
		arraySize as size of all the arrays as int
		highestScore as the score to check as int
**/
void printStudentsWithTheHighestScore(int idArray[], string nameArray[], int scoreArray[], int arraySize, int highestScore);
 
int main()
{
	// Declare and initialize cstring to store file name
	char fileName[20] = "";
	// Prompt user to enter file name
	cout << "Enter filename : ";
	// Get file name from user
	cin >> fileName;
	
	// Declare file input object
	ifstream infile;
	// Open file given by user
	infile.open(fileName);
	// If fail to open file, notify
	if (infile.fail())
	{
		cout << "Failed to open file " << endl;
	}
	// Declare and initialize constant variable for size of arrays
	const int SIZE_OF_ARRAY = 16;
	
	// Declare  and initialize arrays that will store ids, names, and scores
	int idArray[SIZE_OF_ARRAY] = {};
	string nameArray[SIZE_OF_ARRAY] = {};
	int scoreArray[SIZE_OF_ARRAY] = {};
	
	// Declare and initialize variables that will be used to store the data read from text file
	int id = 0;
	string name = "";
	int score = 0;
	// Declare and initialize variable use to store data from file into the 3 arrays
	int index = 0;
	// Declare and initialize variable to store highest score seen in text file
	int highestScore = -1;
	
	cout << endl;
	// Output student id, name, and score to the terminal
	cout << "    Student List    " << endl;
	cout << "------------------------" << endl;
	// While not at end of file
	while (!infile.eof())
	{
		// Read in the id, name, and score from text file
		infile >> id >> name >> score;
		// If the current score is larger than the current highestScore
		if (score > highestScore)
		{
			// Set the current score to be the highest score
			highestScore = score;
		}
		// Assign id, name, and score to their respective arrays
		idArray[index] = id;
		nameArray[index] = name;
		scoreArray[index] = score;
		index++;
		// Output the id, name, score of each student to the terminal
		cout << id << setw(10) << name << setw(4) << score << endl;
	}
	// Close the input file
	infile.close();
	// Skip a line for better readability in terminal
	cout << endl;
	// Output the highest score seen in file
	cout << "*** Max Score : " << highestScore << endl;
	cout << endl;
	
	cout << "Students with max score " << endl;
	cout << "------------------------" << endl;
	 
	// Output the id, name, and score of the students with highest score
	printStudentsWithTheHighestScore(idArray, nameArray, scoreArray, SIZE_OF_ARRAY, highestScore);
	
	return 0;
}


void printStudentsWithTheHighestScore(int idArray[], string nameArray[], int scoreArray[], int arraySize, int highestScore)
{
	// Loop through the score array
	for (int i = 0; i < arraySize; i++)
	{
		// If there is a score equal to given highestScore
		if (scoreArray[i] == highestScore)
		{
			// Output the element at the current index of given idArray, nameArray, and scoreArray
			cout << idArray[i] << setw(10) << nameArray[i] << setw(4) << scoreArray[i] << endl;
		}
	}
}