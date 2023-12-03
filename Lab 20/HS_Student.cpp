/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: HS_Student.cpp for Problem #1 of Lab #20
**/
#include "HS_Student.h"

// Calls parent constructor to initialize inherited private 
// member variables type, name, and year
// Sets private member variable activity to empty string
HS_Student::HS_Student(): Student(), activity("")
{

}

// Calls parent constructor with 3 arguments to set private 
// member variables type, name, and year to 
// given newType, newName, and newYear
// Sets private member variable activity to given activity
HS_Student::HS_Student(char newType, string newName, int newYear, string newActivity): 
	Student(newType, newName, newYear), activity(newActivity)
{

}

void HS_Student::setActivity(string newActivity)
{
	// Sets private member variable activity to given newActivity
	activity = newActivity;
}

string HS_Student::getActivity() const
{
	// Return value of private member variable activity
	return activity;
}

void HS_Student::displayInfo() const
{
	// Outputs private member variables name, 
	// year, and activity formatted to terminal
	cout << setw(10) << getName() << setw(2) <<  getYear() 
		<< setw(10) << getActivity() << endl;
}

int HS_Student::getEnglishScore() const
{
	// Return 0 for english score
	return 0;
}

int HS_Student::getMathScore() const
{
	// Return 0 for math score
	return 0;
}
