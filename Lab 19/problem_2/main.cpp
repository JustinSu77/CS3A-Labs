/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: main.cpp for Problem #2 of Lab #19
**/
#include <iostream>
#include <fstream>
#include "MS_Student.h"
#include "HS_Student.h"
using namespace std;

/**
	Purpose: Output the number of high school students in given array that does
			 each of the activities in given activitiesArray to terminal.
	Input: - array as dynamic array of HS_Student objects
		   - students as number of elements in given array
		   - gradeLevel as the year of students to search for 
		     and display as integer
		   - activitiesArray as an array of strings
		   - activities as the number of elements in given activitiesArray
	Input Requirements: - Given array should be of type HS_Student
					    - Given students should be equal to the number 
						  of elements in given array
						- Given gradeLevel should be an integer
						- Given activitiesArray should of type string
						- Given activities should be an integer
						- Given activities should be equal to the number of elements 
						  in given activitiesArray
						- Given activites should be greater than 0
	Result: Display the number of HS_Student objects that have private 
	        member variable equal to each of the activities in given activitiesArray.
**/
void display_students_with_given_activities(HS_Student* array, int students, int gradeLevel, string activitiesArray[], int activities);

/**
	Purpose: Returns the number of HS_Student objects that are in given 
			 array that are in given gradeLevel and does given activity as integer.
	Input: - array as dynamic array of type HS_Student
		   - students as number of elements in given array
		   - gradeLevel as the year of HS_Students to look for as int
		   - activity as the activity of HS_Students to look for as string
	Input Requirement: - Given array should be of type HS_Student
	                   - Given students should be equal to the number of 
					     elements in given array
					   - Given gradeLevel should be an integer
					   - Given activity should be a string
	Result: Returns the number of HS_Students objects in given array that 
	        have private member variables year and activity equal to  
			the given gradeLevel and given activity.
**/
int count_students_with_given_grade_level_and_activity(HS_Student* array, int students, int gradeLevel, string activity);

/**
	Purpose: Return the number of MS_Student objects in given array 
	         that are in the given gradeLevel as int.
	Input: - array as dynamic array of type MS_Student
	       - students as number of elements in given array as int
		   - gradeLevel as the year of MS_Student object to search for as int
	Input Requirements: - Given array should be of type MS_Student
					    - Given students should be equal to number of elements in given array
						- Given gradeLevel should an integer
	Result: The number of MS_Student object that has private member variable 
	        year equal to given gradeLevel is returned.
**/
int count_students_in_given_grade_level(MS_Student* array, int students, int gradeLevel);

/**
	Purpose: Return the math scores of all the MS_Student objects in 
	         given array that are in given gradeLevel.
	Input: - array as dynamic array of MS_Stuent objects
		   - students as number of elements in given array
		   - gradeLevel as the year of MS_Students objects to look for
	Input Requirement: - Given array should be of type MS_Student
	                   - Given students should be equal to number of elements in given array
					   - Given gradeLevel should be an integer
	Result: The total sum of the mathScore of all the MS_Student objects in given array 
			that have private member variable year equal to given gradeLevel is returned.
**/
double count_total_math_score_of_students_in_given_grade_level(MS_Student* array, int students, int gradeLevel);


/**
	Purpose: Return the sum of the science scores of all the MS_Student objects in
			 given array that are in given gradeLevel.
	Input: - array as dynamic array of MS_Stuent objects
		   - students as number of elements in given array
		   - gradeLevel as the year of MS_Students objects to look for
	Input Requirement: - Given array should be of type MS_Student
					   - Given students should be equal to number of elements in given array
					   - Given gradeLevel should be an integer
	Result: The total sum of the science scores of all the MS_Student objects in given array
			that have private member variable year equal to given gradeLevel is returned.
**/
double count_total_science_score_of_students_in_given_grade_level(MS_Student* array, int students, int gradeLevel);

/**
	Purpose: Return the average of math scores of the MS_Student object 
	         that are in the given gradeLevel.
	Input: - array as dynamic array of MS_Student objects
		   - students as number of elements in given array as int
		   - gradeLevel as the year of MS_Students objects to search for as int
	Input Requirement: - Given array should be of type MS_Student
					   - Given students should be equal to number of elements in given array
					   - Given gradeLevel should be an integer
	Result: The average of the math scores of all MS_Student objects in given array that have 
	        private member variable year equal to given gradelevel is returned.
**/
double calculate_math_average(MS_Student* array, int students, int gradeLevel);

/**
	Purpose: Return the average of science scores of the MS_Student object
			 that are in the given gradeLevel.
	Input: - array as dynamic array of MS_Student objects
		   - students as number of elements in given array as int
		   - gradeLevel as the year of MS_Students objects to search for as int
	Input Requirement: - Given array should be of type MS_Student
					   - Given students should be equal to number of elements in given array
					   - Given gradeLevel should be an integer
	Result: The average of the science scores of all MS_Student objects in given array that have
			private member variable year equal to given gradelevel is returned.
**/
double calculate_science_average(MS_Student* array, int students, int gradeLevel);

int main()
{
	// Get middle school students
	// Declare ifstream objext
	ifstream inputFile;
	// Open MS.txt 
	inputFile.open("MS.txt");
	// If failed to open MS.txt
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open MS.txt" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize varaible to count number 
	// of middle school students in MS.txt
	int midSchoolStudentsCount = 0;
	// Declare and initialize variable to store name from file
	string name = "";
	// Declare and initialize variable to store gradeLevel from file
	int gradeLevel = 0;
	// Declare and initialize variable to store mathScore from file
	int mathScore = 0;
	// Declare and initialize variable to store scienceScore from file
	int scienceScore = 0;
	// Read entire file of MS.tt
	while (!inputFile.eof())
	{
		// Read each line of MS.txt
		inputFile >> name >> gradeLevel >> mathScore >> scienceScore;
		// Increment midSchoolStudentCount by 1
		midSchoolStudentsCount++;
	}
	// Close inout file object
	inputFile.close();
	// Declare and initialize MS_Student dynamic array with size of midSchoolStudentCount
	MS_Student* ms_array = new MS_Student[midSchoolStudentsCount];
	// Reopen MS.txt to read in data from file into dynamic array
	inputFile.open("MS.txt");
	// If failed to open MS.txt
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open MS.txt" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variale to keep track of lines read from file
	int studentsSeen = 0;
	// Read entire file and as long as studentsSeen is less than midSchoolStudentsCount
	while (!inputFile.eof() && studentsSeen < midSchoolStudentsCount)
	{
		// Read in line of MS.txt
		inputFile >> name >> gradeLevel >> mathScore >> scienceScore;
		// Construct MS_Student object with data from file
		MS_Student student(name, gradeLevel, mathScore, scienceScore);
		// Insert MS_Student object into dynamic array at index of studentsSeen
		ms_array[studentsSeen] = student;
		// Increment studentsSeen
		studentsSeen++;
	}
	// Close inputFile
	inputFile.close();
	// Open HS.txt
	inputFile.open("HS.txt");
	if (inputFile.fail())
	{
		cout << "Failed to open file HS.txt" << endl;
		exit(1);
	}
	// Declare and initialize variable to count number of high school students in HS.txt
	int highSchoolStudentsCount = 0;
	// Declare and initialize variable to store activity from HS.txt
	string activity = "";
	// Read entire HS.txt file
	while (!inputFile.eof())
	{
		// Read in each line
		inputFile >> name >> gradeLevel >> activity;
		// Increment highSchoolStudentsCount by 1
		highSchoolStudentsCount++;
	}
	// Close input file 
	inputFile.close();
	// Declare and initialize HS_Student dynamic array with size highSchoolStudentCount
	HS_Student* hs_array = new HS_Student[highSchoolStudentsCount];
	//
	inputFile.open("HS.txt");
	// If failed to open HS.txt
	if (inputFile.fail())
	{
		// Notify
		cout << "Failed to open file HS.txt" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Reset studentsSeen to 0
	studentsSeen = 0;
	// Read entire HS.txt file and as long as studentsSeen is 
	// less than highschoolStudentsCount
	while (!inputFile.eof() && studentsSeen < highSchoolStudentsCount)
	{
		// Read line of HS.txt
		inputFile >> name >> gradeLevel >> activity;
		// Construct HS_Student object with data from file 
		HS_Student student(name,gradeLevel,activity);
		// Insert HS_Student object into hs_array at index of studentsSeen
		hs_array[studentsSeen] = student;
		// Increment studentsSeen
		studentsSeen++;
	}
	// Close input file
	inputFile.close();
	// Declare and initialize string array of activities
	string activities[] = { "swimming", "band", "polo", "wrestling", "soccer" };
	// Declare and initialize variable to store number of elements in activities array
	int numberOfActivities = sizeof(activities) / sizeof(string);
	// Display the number of HS_Student objects at each grade level that do each activity in activities array
	cout << "  High School Students  " << endl;
	cout << "------------------------" << endl;
	// Display the number of HS_Student objects in year 9 that do each of the activities in activities array
	cout << "Grade 9" << endl;
	display_students_with_given_activities(hs_array, highSchoolStudentsCount, 9, activities, numberOfActivities);
	cout << endl;
	// Display the number of HS_Student objects in year 10 that do each of the activities in activities array
	cout << "Grade 10" << endl;
	display_students_with_given_activities(hs_array, highSchoolStudentsCount, 10, activities, numberOfActivities);
	cout << endl;
	// Display the number of HS_Student objects in year 11 that do each of the activities in activities array
	cout << "Grade 11" << endl;
	display_students_with_given_activities(hs_array, highSchoolStudentsCount, 11, activities, numberOfActivities);
	cout << endl;
	// Display the number of HS_Student objects in year 12 that do each of the activities in activities array
	cout << "Grade 12" << endl;
	display_students_with_given_activities(hs_array, highSchoolStudentsCount, 12, activities, numberOfActivities);
	// output newline to terminal for readability
	cout << endl;
	// output newline to terminal for readability
	cout << endl;
	// Display the average math and science score for each middle school grade
	cout << "   Middle School Students   " << endl;
	cout << "----------------------------" << endl;
	// Round averages to 2 decimal plaes
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	// Display the math and science average for MS_Student objects in year 6
	cout << " 6th grade:   " << calculate_math_average(ms_array, midSchoolStudentsCount, 6) 
		<< "  " << calculate_science_average(ms_array, midSchoolStudentsCount, 6) << endl;
	// Display the math and science average for MS_Student objects in year 7
	cout << " 7th grade:   " << calculate_math_average(ms_array, midSchoolStudentsCount, 7) 
		<< "  " << calculate_science_average(ms_array, midSchoolStudentsCount, 7) << endl;
	// Display the math and science average for MS_Student objects in year 8
	cout << " 8th grade:   " << calculate_math_average(ms_array, midSchoolStudentsCount, 8) 
		<< "  " << calculate_science_average(ms_array, midSchoolStudentsCount, 8) << endl;
	// Deallocate ms_array
	delete[] ms_array;
	// Deallocate hs_array
	delete[] hs_array;

	return 0;
}

void display_students_with_given_activities(HS_Student* array, int students, int gradeLevel, 
	string activitiesArray[], int activities)
{
	// Loop through given activitiesArray
	for (int i = 0; i < activities; i++)
	{
		// Store activity at current index
		string activity = activitiesArray[i];
		// Declare and initialize total variable to return value of function that counts 
		// number of students at given grade level and does given activity
		int total = count_students_with_given_grade_level_and_activity(array, students, gradeLevel, activity);
		// If the total is greater than 0
		if (total > 0)
		{
			// Display name of activity and number of HS_Student objects who does it
			cout << "   " << activity << " : " << total << endl;
		}
	}
}

int count_students_with_given_grade_level_and_activity(HS_Student* array, int students,
	int gradeLevel, string activity)
{
	// Declare and initialize counter to be returned
	int result = 0;
	// Loop through given array
	for (int i = 0; i < students; i++)
	{
		// Save HS_Student object at current index
		HS_Student s = array[i];
		// If the year and activity of current HS_Student object is equal to given gradeLevel and activity
		if (s.getYear() == gradeLevel && s.getActivity() == activity)
		{
			// Increment result counter
			result++;
		}
	}
	// Return result counter
	return result;
}

int count_students_in_given_grade_level(MS_Student* array, int students, int gradeLevel)
{
	// Declare and initialize result counter to be returned
	int result = 0;
	// Loop through given array
	for (int i = 0; i < students; i++)
	{
		// Store MS_Student object at current index
		MS_Student s = array[i];
		// If the year of current MS_Student object is equal to gradeLevel
		if (s.getYear() == gradeLevel)
		{
			// Increment result counter
			result++;
		}
	}
	// Return result counter
	return result;
}

double count_total_math_score_of_students_in_given_grade_level(MS_Student* array, int students, int gradeLevel)
{
	// Declare and initialize sum variable to be returned
	int sum = 0;
	// Loop through given array
	for (int i = 0; i < students; i++)
	{
		// Store MS_Student object at current index
		MS_Student s = array[i];
		// If the year of current MS_Student object is equal to gradeLevel
		if (s.getYear() == gradeLevel)
		{
			// Add the mathScore of current MS_Student object to sum
			sum += s.getMathScore();
		}
	}
	// Return sum variable
	return sum;
}

double count_total_science_score_of_students_in_given_grade_level(MS_Student* array, int students, int gradeLevel)
{
	// Declare and initialize sum variable to be returned
	int sum = 0;
	// Loop through given array
	for (int i = 0; i < students; i++)
	{
		// Store MS_Student object at current index
		MS_Student s = array[i];
		// If the year of current MS_Student object is equal to gradeLevel
		if (s.getYear() == gradeLevel)
		{
			// Add the mathScore of current MS_Student object to sum
			sum += s.getScienceScore();
		}
	}
	// Return sum variable
	return sum;
}

double calculate_math_average(MS_Student* array, int students, int gradeLevel)
{
	// Declare and initialize average as the total math score of all 
	// the MS_Student objects in given array divided by number of MS_Student 
	// objects that have year equal to given gradeLevel
	double average = count_total_math_score_of_students_in_given_grade_level(array, students, gradeLevel) / 
		count_students_in_given_grade_level(array, students, gradeLevel);
	// Return average
	return average;
}

double calculate_science_average(MS_Student* array, int students, int gradeLevel)
{
	// Declare and initialize average as the total science score of all 
	// the MS_Student objects in given array divided by number of MS_Student 
	// objects that have year equal to given gradeLevel
	double average = count_total_science_score_of_students_in_given_grade_level(array, students, gradeLevel) / 
		count_students_in_given_grade_level(array, students, gradeLevel);
	// Return average
	return average;
}
 

 
