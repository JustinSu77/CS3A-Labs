/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: main.cpp for Problem #1 of Lab #20
**/
#include <iostream>
#include <fstream>
#include "Student.h"
#include "MS_Student.h"
#include "HS_Student.h"
using namespace std;

/**
	Purpose: Output values of the private member variables of each
			 elements in given Student* dynamic array.
	Input: - array as a dynamic array of dynamically allocated polymorphic Student objects
		   - number_of_students as number of elements in given array
	Input Requirement: - Given array should be an dynamic array of dynamically
						 allocated polymorphic Student objects
					   - Given number_of_students_ should be equal to the
						 number of elements in given array
					   - Given number_of_students is an integer
	Result: The values of the private member variables of each element
			in given array is outputted to terminal

**/
void print_array(Student** array, int number_of_students);

/**
	Purpose: Output the name and grade level of HS_Students objects with each
			 activity in given activitiesArray.
	Input: - array as dynamic array of dynamically allocated polymorphic Student objects
		   - number_of_students as number of elements in given array
		   - activitiesArray as an array of activites to count
		   - activities as number of elements in given activitiesArray
	Input Requirement: - Given array should be an dynamic array of dynamically
						 allocated polymorphic Student objects
					   - Given number_of_students should be equal to the
						 number of elements in given array
					   - Given number_of_students should be an integer
					   - Given activitiesArray should be array if type string
					   - Given activities should be equal to number of elements in
						 given activitiesArray
					   - Given activities should be an integer
   Result: For each activity in given activitesArray the name and grade level
		   of HS_Student object that has its private member variable activity equal to it
		   is outputted to terminal
**/
void output_students_in_each_activities(Student** array, int number_of_students,
	string activitiesArray[], int activities);

/**
	Purpose: Return the number of dynamically allocated polymorphic Student
			 objects with year equal to given year.
	Input: - array as dynamic array of dynamically allocated polymorphic Student objects
		   - number_of_students as number of elements in given array
		   - year as the year of Student objects to look for
	Input Requirement: - Given array should be an dynamic array of dynamically
						 allocated polymorphic student objects
					   - Given number_of_students should be equal to the number
						 of elements in given array
					   - Given number_of_students should be an integer
					   - Given year should be an integer
	Result: Return the number of Student objects that have private member
			variable year equal to given year as int
**/
int count_students_in_given_year(Student** array, int number_of_students, int year);

/**
	Purpose: Return the sum of the english scores of MS_Student objects with
			 given year in given array.
	Input: - array as dynamic array of dynamically allocated polymorhpic Student objects
		   - number_of_students as the number of elements in given array
		   - year as the year of MS_Student objects to look for
	Input Requirement: - Given array should be an dynamic array of
						 dynamically allocated polymorphic Student objects
					   - Given number_of_students should be equal to
						 number of elements in given array
					   - Given number_of_students should be an integer
   Result: The sum of the english scores of each MS_Student object
		   that has given year is returned as int
**/
double count_total_english_score_in_given_year(Student** array, int number_of_students, int year);

/**
	Purpose: Return the sum of the math scores of MS_Student objects with
			 given year in given array.
	Input: - array as dynamic array of dynamically allocated
			 polymorhpic Student objects
		   - number_of_students as the number of elements in given array
		   - year as the year of MS_Student objects to look for
	Input Requirement: - Given array should be an dynamic array of
						 dynamically allocated polymorphic Student objects
					   - Given number_of_students should be equal to
						 number of elements in given array
					   - Given number_of_students should be an integer
   Result: The sum of the math scores of each MS_Student object
		   that has given year is returned as int
**/
double count_total_math_score_in_given_year(Student** array, int number_of_students, int year);

/**
	Purpose: Return the average english score of MS_Student
			 objects with given year in given array.
	Input: - array as dynamic array of dynamically allocated
			 polymorhpic Student objects
		   - number_of_students as the number of elements in given array
		   - year as the year of MS_Student objects to look for
	Input Requirement: - Given array should be an dynamic array of
						 dynamically allocated polymorphic Student objects
					   - Given number_of_students should be equal to
						 number of elements in given array
					   - Given number_of_students should be an integer
   Result: The average of the english scores of each MS_Student
		   object in given array that has given year is returned as double
**/
double get_english_average_of_given_year(Student** array, int number_of_students, int year);

/**
	Purpose: Return the average math score of MS_Student
			 objects with given year in given array.
	Input: - array as dynamic array of dynamically allocated
			 polymorhpic Student objects
		   - number_of_students as the number of elements in given array
		   - year as the year of MS_Student objects to look for
	Input Requirement: - Given array should be an dynamic array of
						 dynamically allocated polymorphic Student objects
					   - Given number_of_students should be equal to
						 number of elements in given array
					   - Given number_of_students should be an integer
   Result: The average of the math scores of each MS_Student
		   object in given array that has given year is returned as double
**/
double get_math_average_of_given_year(Student** array, int number_of_students, int year);

/**
	Purpose: Deallocate given dynamic array of dynamically
			 allocated polymorphic Student objects.
	Input: - array as dynamic array of dynamically allocated
			 polymorphic Student objects
		   - number_of_students as number of elements in given array
	Input Requirement: - Given array should be a dynamic array of
						 dynamically allocated polymorphic Student objects
					   - Given number_of_students should be equal to number of
						 elements in given array
					   - Given  number_of_students should be an integer
	Result: The elements in given array is deallocated and the array itself is deallocated
**/
void deallocateArray(Student**& array, int number_of_students);

int main()
{
	// Declare ifstream object
	ifstream inputFile;
	// Open student.txt
	inputFile.open("student.txt");
	// If failed to open student.txt
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open file student.txt" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable store number 
	// of students in dynamic array
	int number_of_students = 0;
	// Declare and initialize variables to store data from file
	char type = ' ';
	string name = "";
	int gradeLevel = 0;
	string activity = "";
	int englishScore = 0;
	int mathScore = 0;
	// Read entire student.txt file
	while (!inputFile.eof())
	{
		// Read in type
		inputFile >> type;
		// If type is not M or H
		if (type != 'M' && type != 'H')
		{
			cout << "student.txt has invalid student type " << type << endl;
			exit(1);
		}
		// If type is M
		if (type == 'M')
		{
			// Read in the data for MS_Students
			// Need to read in entire data otherwise number_of_students will be wrong
			inputFile >> name >> gradeLevel >> englishScore >> mathScore;
			// Increment number_of_students by 1
			number_of_students++;
		}
		// If type is H
		else if (type == 'H')
		{
			// Read in data of HS_Students
			// Need to read in entire data otherwise number_of_students will be wrong
			inputFile >> name >> gradeLevel >> activity;
			// Increment number_of_students by 1
			number_of_students++;
		}
	}
	// Close ifstreak object
	inputFile.close();
	// Declare and initialize dynamic array of dynamically 
	// allocated polymorphic Student objects
	Student** array = new Student * [number_of_students];
	// Open student.txt again
	inputFile.open("student.txt");
	// If failed to open student.txt
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open file student.txt" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize to index variable for 
	// adding Student objects to dynamic array
	int index = 0;
	// Read entire student.txt and index is less than number_of_students
	while (!inputFile.eof() && index < number_of_students)
	{
		// Read in type
		inputFile >> type;
		// If type is not M or H
		if (type != 'M' && type != 'H')
		{
			cout << "student.txt has invalid student type " << type << endl;
			exit(1);
		}
		// If type is M
		if (type == 'M')
		{
			// Read in data for MS_Student
			inputFile >> name >> gradeLevel >> englishScore >> mathScore;
			// Instantiate dynamic polymorphic MS_Student object with data read
			Student* student = new MS_Student(type, name, gradeLevel, englishScore, mathScore);
			// Put object in array at current index
			array[index] = student;
			// Increment index by 1
			index++;
		}
		// If type is H
		else if (type == 'H')
		{
			// Read in data for HS_Student
			inputFile >> name >> gradeLevel >> activity;
			// Instantiate dynamic polymorphic HS_Student object with data read
			Student* student = new HS_Student(type, name, gradeLevel, activity);
			array[index] = student;
			// Increment index by 1
			index++;
		}

	}
	// Close ifstream object
	inputFile.close();
	// Output Student dynamic array
	cout << "<<<   Original Array   >>>" << endl;
	print_array(array, number_of_students);
	// Output newline for terminal for readability
	cout << endl;
	// Declare and initialize string array of activities
	string activities[] = { "swimming", "band", "polo", "wrestling", "soccer" };
	// Declare and initialize the number of elements in activities array
	int number_of_activities = sizeof(activities) / sizeof(string);
	// Output the number of high school student in each activity
	cout << "<<<  High School Students  >>>" << endl;
	output_students_in_each_activities(array, number_of_students, activities, number_of_activities);
	// Output newline to terminal for readability
	cout << endl;
	// Round averages to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	// Output average english and math score for each middle school grade
	cout << "<<<  Middle School Students >>>" << endl;
	// Output average english and math score for 6th graders
	cout << "<< Averages for 6 th graders >>" << endl;
	cout << "English : " << get_english_average_of_given_year(array, number_of_students, 6) << endl;
	cout << "Math    : " << get_math_average_of_given_year(array, number_of_students, 6) << endl;
	// Output newline to terminal for readability
	cout << endl;
	// Output average english and math score for 7th graders
	cout << "<< Averages for 7 th graders >>" << endl;
	cout << "English : " << get_english_average_of_given_year(array, number_of_students, 7) << endl;
	cout << "Math    : " << get_math_average_of_given_year(array, number_of_students, 7) << endl;
	// Output newline to terminal for readability
	cout << endl;
	// Output average english and math score for 8th graders
	cout << "<< Averages for 8 th graders >>" << endl;
	cout << "English : " << get_english_average_of_given_year(array, number_of_students, 8) << endl;
	cout << "Math    : " << get_math_average_of_given_year(array, number_of_students, 8) << endl;
	// Output newline to terminal for readability
	cout << endl;

	// Deallocate Student dynamic array
	deallocateArray(array, number_of_students);

	return 0;
}

void print_array(Student** array, int number_of_students)
{
	// Loop through given array
	for (int i = 0; i < number_of_students; i++)
	{
		// Store current Student object at current inde
		Student* s = array[i];
		// Call virtual function of Student object to 
		// display the value of its private member variable
		s->displayInfo();
	}
	// Output newline to terminal for readability
	cout << endl;
}

void output_students_in_each_activities(Student** array, int number_of_students, string activitiesArray[], int activities)
{
	// Loop through given activitiesArray
	for (int i = 0; i < activities; i++)
	{
		// Store the current activity at current index
		string activity = activitiesArray[i];
		// Output current activity
		cout << "=== " << activity << " ===" << endl;
		// Loop through given dynamic array
		for (int i = 0; i < number_of_students; i++)
		{
			// Store Student object at current index
			Student* s = array[i];
			// If the type of current Student object is H
			if (s->getType() == 'H')
			{
				if (s->getActivity() == activity)
				{
					// Output the name and year of current HS_Student
					cout << setw(7) << s->getName() << setw(3)
						<< "(" << s->getYear() << ")" << endl;
				}
				 
			}
		}
		// Output newline to terminal for readability
		cout << endl;
	}
}

int count_students_in_given_year(Student** array, int number_of_students, int year)
{
	// Declare and initialize total variable to be returned
	int total = 0;
	// Loop through given dynamic array
	for (int i = 0; i < number_of_students; i++)
	{
		// Store Student object at current index
		Student* s = array[i];
		// If the year of object equal to given year
		if (s->getYear() == year)
		{
			/// Increment total
			total++;
		}
	}
	// Return total
	return total;
}

double count_total_english_score_in_given_year(Student** array, int number_of_students, int year)
{
	// Declare and initialize score variable to be returned
	double score = 0.0;
	// Loop through given dynamic array
	for (int i = 0; i < number_of_students; i++)
	{
		// Store Student object at current index
		Student* s = array[i];
		// If type of current styudent is M
		if (s->getType() == 'M')
		{
			// If the year of current Student object is equal to given year
			if (s->getYear() == year)
			{
				// Add the english score of current Student object to score 
				score += s->getEnglishScore();
			}
			 
		}
	}
	// Return score 
	return score;
}

double count_total_math_score_in_given_year(Student** array, int number_of_students, int year)
{
	// Declare and initialize score variable to be returned
	double score = 0.0;
	// Loop through given dynamic array
	for (int i = 0; i < number_of_students; i++)
	{
		// Store Student object at current index
		Student* s = array[i];
		// If type of current styudent is M
		if (s->getType() == 'M')
		{
			// If the year of current Student object is equal to year
			if (s->getYear() == year)
			{
				// Add the math score of current Student object to score
				score += s->getMathScore();
			}
		}
	}
	// Return score 
	return score;
}

double get_english_average_of_given_year(Student** array, int number_of_students, int year)
{
	// Declare and initialize average variable as the total english score 
	// of all MS_Student objects with given year divided by number 
	// of MS_Student objects with given year
	double average = count_total_english_score_in_given_year(array, number_of_students, year) / count_students_in_given_year(array, number_of_students, year);
	// Return average
	return average;
}

double get_math_average_of_given_year(Student** array, int number_of_students, int year)
{
	// Declare and initialize average variable as the total math score 
	// of all MS_Student objects with given year divided by number 
	// of MS_Student objects with given year
	double average = count_total_math_score_in_given_year(array, number_of_students, year) /
		count_students_in_given_year(array, number_of_students, year);
	// Return average
	return average;
}

void deallocateArray(Student**& array, int number_of_students)
{
	// Loop through given dynamic array
	for (int i = 0; i < number_of_students; i++)
	{
		// Delete dynamic object at current index
		delete array[i];
	}
	// Delete given array itself
	delete[] array;
	// Set array pointer to nullptr
	array = nullptr;
}