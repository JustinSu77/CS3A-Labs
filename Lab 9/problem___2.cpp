/**
	Date: 9/26/2023
	By: Justin Su
	Purpose: Problem #2 for Lab #9
**/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Student class
class Student
{  
	// Private member variables
	private:
		int id;
		string name;
	// Public member functions
	public:
		/**
			Default constructor.
			Precondition: Student object is instantiated with no arguments.
			Postcondition: id is set to 0.
						   name is set to empty string.
		**/
		Student();

		/**
			Constructor with 3 arguments.
			Precondition: Student object is instantiated with 3 arguments.
			Postcondition: id is set to given newId
						   name is set to newName.
		**/
		
		Student(int newId, string newName);
		
		/**
			Setter function for private variable id.
			Precondition: id is 0 or has an integer value.
			Postcondition: id is set to given newId.
		**/
		void setId(int newId);

		/**
			Setter function for private variable name.
			Precondition: name is empty or already has a string value.
			Postcondition: name is set to given newName.
		**/
		void setName(string newName);
		
		/**
			Getter funciton for private variable id.
			Precondition: id has been set to 0 or an integer value
			Postcondition: id is returned.
		**/
		int getId();
		
		/**
		Getter funciton for private variable name.
		Precondition: name has been set to empty string or a string value
		Postcondition: name is returned.
		**/
		string getName();
};

/**
	Display Student object id and name in given Student dynamic array.
	Precondition: Given Student dynamic array has some elements
	Postcondition: The id and name of each Student object in array is outputed to terminal.
		array as Student dynamic array
		arraySize as size of given Student dynamic array as int
**/
void displayArray(Student* array, int arraySize);

/**
	Sort the given Student dynamic array in ascending order based on id using insertion sort.
	Precondition: Given Student dynamic array has some elements
	Postcondition: The elements of given array is sorted in ascending order based on id
		array as Student dynamic array
		size as number of elements array will have as int
**/
void insertionSortById(Student* array, int arraySize);

int main()
{
	// Declare and initialize fileName
	string fileName = "";
	// Prompt user for fileName
	cout << "Enter filename : ";
	// Get fileName from user allowing spaces
	getline(cin, fileName);
	// Declare ifstream object
	ifstream inputFile;
	// Open given fileName
	inputFile.open(fileName);
	// If fail to open file
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open file " << fileName << endl;
		// Exit program
		exit(1);
	}
	// Declare and initialize numberOfStudents that will be in dynamic array
	int numberOfStudents = 0;
	// Read first line from file
	inputFile >> numberOfStudents;
	// Declare and initialize Student dynamic array with size numberOfStudents
	Student* studentArray= new Student[numberOfStudents];
	// Declare and initialize variables to store the rest of the data from file
	int id = 0;
	string name = "";
	// Declare and initialize indez variable used to set elements of dynamic array
	int index = 0;
	// Keeping read from until end of file
	// index < numberOfStudents to prevent "Reading invalid data" from compiler
	while (!inputFile.eof() && (index < numberOfStudents))
	{
		inputFile >> id >> name;
		Student newStudent(id, name);
		studentArray[index] = newStudent;
		index++;
	}
	// Output elements in Student dynamic array before sorting by id
	cout << "< Original Data >" << endl;
	cout << "----------------" << endl;
	displayArray(studentArray, numberOfStudents);
	// Outout newline for readability
	cout << endl;
	// Sort the Student dynamic array by id
	insertionSortById(studentArray, numberOfStudents);
	// Output elements elements in Student dynamic array after sorting by id
	cout << "< Sorted Data >" << endl;
	cout << "----------------" << endl;
	displayArray(studentArray, numberOfStudents);
	// Close inputFile
	inputFile.close();
	// Deallocate studentArray
	delete[] studentArray;
	
	return 0;
}

Student::Student()
{
	// Set privare variable id to 0
	id = 0;
	// Set private variable name to empty string
	name = "";
}

Student::Student(int newId, string newName)
{
	// Set private variable id to given newId
	id = newId;
	// Set private variable name to given newName
	name = newName;
}

void Student::setId(int newId)
{
	// Set private variable id to given newId
	id = newId;
}

void Student::setName(string newName)
{
	// Set private variable name to given newName
	name = newName;
}

int Student::getId()
{
	// Return private variable id
	return id;
}

string Student::getName()
{
	// Return private variable name
	return name;
}

void displayArray(Student* array, int arraySize)
{
	// Loop through given dynamic array
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and initialize Student variable to store current element 
		Student currentStudent = array[i];
		// Output the id and name of currentStudent neatly formatted
		cout << setw(3) << currentStudent.getId() << setw(10) << currentStudent.getName() << endl;
	}
	
}

void insertionSortById(Student* array, int arraySize)
{
	// Declare variables used
	int j;
	// Loop through array
	for (int i = 1; i < arraySize; i++)
	{
		// Set key to current element
		Student key = array[i];
		// Set j to element before current element
		j = i - 1;
		// Compare the id of the key element to the id of the element before it
		// If id of key element is smaller keep comparing with each of the elements before it
		// Swap the key element with the its previous element if its id is smaller
		while (j >= 0 && array[j].getId() > key.getId())
		{
			// Swap element
			array[j + 1] = array[j];
			// Go to element before
			j--;
		}
		// Insert key element into position where its id is greater than the element before it
		array[j + 1] = key;
	}
}
