/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: main.cpp for Problem #3 of Lab #11
**/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Student.h"
using namespace std;

/**
	Output the name, mathScore, and englishSCore of each Student object in given Student dynamic array.
	Precondition: Given Student dynamic array has some elements.
	Postcondition: The name, mathScore, and englishScore of each 
				   Student object in given Student dynamic array is outputted to the terminal.
   array as dynamic array of Student objects
   arraySize as the number of elements in given Student dynamic array as int
**/
void outputStudentArray(Student* array, int arraySize);

/**
	Output the name, mathScore, and englishScore of each 
	Student object that has mathScore equal to given mathScore.
	Preconditon: Given Student dynamic array has some elements.
	Postcondtion: The name, mathScore, and englishScore of  Student objects 
	that has mathScore equal to given mathScore is outputed to the terminal.
		array as dynamic array of Student objects
		arraySize as number of elements in given Student dynamic array as int
		mathScore as the mathScore Student objects must have to be outputted to the terminal as int
**/
void outputStudentWithGivenMathScore(Student* array, int arraySize, int mathScore);

int main()
{
	// Declare and initialize variable for fileName
	string fileName = "";
	// Prompt user for fileName
	cout << "Enter filename : ";
	// Get fileName from user, getline to allow spaces
	getline(cin, fileName);
	// Declare ifstream objet
	ifstream inputFile;
	// Open given fileName
	inputFile.open(fileName);
	// If file fail to open
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open " << fileName << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable to store numberOfStudents
	int numberOfStudents = 0;
	// Read first line and store it into numberOfStudents
	inputFile >> numberOfStudents;
	// Declare and initialize dynamic array that will hold Student objects
	Student* array = new Student[numberOfStudents];
	// Declare and initialize variables that will be read in from file
	string name = "";
	int scoreOne = 0;
	int scoreTwo= 0;
	// Declare and initialize variable to insert instantiated Student objects into dynamic array
	int index = 0;
	// Keep looping while not end of file and index is less than numberOfStudents
	// The latter is to prevent warnings from compiler
	while (!inputFile.eof() && index < numberOfStudents)
	{
		// Read the name, score
		inputFile >> name >> scoreOne >> scoreTwo;
		// Instantiate Student object with variables read in
		Student student = {name,scoreOne,scoreTwo};
		// Copy Student object into dynamic array
		array[index] = student;
		// Increment index variable
		index++;
	}
	// Close inputFile object
	inputFile.close();
	// Output the Student objects in dynamic array
	outputStudentArray(array,numberOfStudents);
	// Declare and initialize math score to match
	int mathScore = 0;
	// Prompt user for mathScore
	cout << "Enter math score : ";
	// Store user input
	cin >> mathScore;
	// Output the student objects that have math score equal to given mathScore
	outputStudentWithGivenMathScore(array, numberOfStudents, mathScore);
	// Deallocate Student dynamic array
	delete[] array;

	return 0;
}

void outputStudentArray(Student* array, int arraySize)
{
	// Loop through given Student dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Save the current Student object in a variable
		 Student student = array[i];
		 // Output the name, mathScore, and englishScore of current object
		cout << setw(10) << student.getName() << "  " << student.getMathScore() << "  " << student.getEnglishScore() << endl;
	}
	// Skip a line in terminal for readability
	cout << endl;
}

void outputStudentWithGivenMathScore(Student* array, int arraySize, int mathScore)
{
	// Loop through given Student dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Save the curent Student object in a variable
		Student student = array[i];
		// If the mathScore of the current object is equal to given mathScore
		if (student.getMathScore() == mathScore)
		{
			// Output the name, mathScore, and englishScore of the current object
			cout << setw(10) << student.getName() << "  " << student.getMathScore() << "  " 
				<< student.getEnglishScore() << endl;
		}
	}
}
