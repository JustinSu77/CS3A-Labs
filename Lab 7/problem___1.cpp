/**
	Date: 9/19/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #7
**/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/**
	Structure to store id, name, and score of a student.
**/
struct Student
{
	int id;
	string name;
	int score;
};

/**
	Loops through the given struct student dynamic array and 
	print out the id, name, and score of the students that have the given highestScore.
	Precondition: Given data dynamic array has numberOfstudents students
	Postcondition: The students with a score equal to the given highestScore is printed to terminal
		data as dynamic array with data type of struct Student
		arraySize as the number of elements in given dynamic array
		highestScore as the highest score seen in file as int
**/
void printStudentsWithHighestScore(struct Student* data, int arraySize, int highestScore);

int main()
{
	// Declare and initialize variable that will store file name
	char fileName[20] = "";
	// Prompt user for filename
	cout << "Enter filename: ";
	// Get filename from user
	cin >> fileName;
	// Output new line to terminal for readability
	cout << endl;
	// Declare ifstream object
	ifstream infile;
	// Open given file
	infile.open(fileName);
	// If failed to open file
	if (infile.fail())
	{
		// Notify
		cout << "Input file opening failed." << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable to count numberOfStudents
	int numberOfStudents = 0;
	// Declare the variables to store the data from file
	int id = 0;
	string name = "";
	int score = 0;
	// Read entire file
	while (!infile.eof())
	{
		// Store the data in each line
		infile >> id >> name >> score;
		// Increment numberOfStudents by 1
		numberOfStudents++;
	}
	// Close ifstream object
	infile.close();
	/*cout << "number of students" << numberOfStudents << endl;*/
	// Declare dynamic array that will store struct Student
	struct Student* data = new struct Student[numberOfStudents];
	// Reopen given file
	infile.open(fileName);
	// If failed to open file
	if (infile.fail())
	{
		// notify
		cout << "Input file opening failed." << endl;
		// Exit program with error code of 1
		exit(1);
	}
 
	// Declare and initialize variable to store highestScore
	int highestScore = 0;
	// Declare and initialize variable to copy data into dynamic array
	int index = 0;
	// Output start of list of students in text file
	cout << "    Student List    " << endl;
	cout << "------------------------" << endl;
	// Read entire given file
	while (!infile.eof())
	{
		// Read each line and store the 3 data in each line into id, name, and score
		infile >> id >> name >> score;
		// If score from file is larger than curent highestScore
		if (score > highestScore)
		{
			// Make the score the new highestScore
			highestScore = score;
		}
		// Output the id, name, and score of each student
		cout << id << setw(10) << name << setw(4) << score << endl;
		// Create student with id, name, and score from file
		struct Student student = { id, name, score };
		// Copy student into dynamic array at current index
		data[index] = student;
		// Increment index 
		index++;
	}
	// Close ifstream object
	infile.close();
	// Output a new line for readability in terminal
	cout << endl;
	// Output the highstScore read from file
	cout << "*** Max score : " << highestScore << endl;
	// Output a new line for readability in terminal
	cout << endl;
	// Output the start of the students with score equal to the highestScore
	cout << "Students with max score" << endl;
	cout << "------------------------" << endl;
	// Call function to output students with highestScore
	printStudentsWithHighestScore(data, numberOfStudents, highestScore);
	// Deallocate dynamic array
	delete[] data;
	
	return 0;
}


 
void printStudentsWithHighestScore(struct Student* data, int arraySize, int highestScore)
{
	// Loop through given dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Store the struct at current index 
		struct Student currentStudent = data[i];
		// If the struct at current index has score equal to given highestScore
		if (currentStudent.score == highestScore)
		{
			// Output the id, name, and score with space in between
			cout << currentStudent.id << setw(10) << currentStudent.name << setw(4) << currentStudent.score << endl;
		}
	}
}