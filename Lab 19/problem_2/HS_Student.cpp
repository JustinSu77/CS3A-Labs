/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: HS_Student.cpp Problem #2 of Lab #19
**/
#include "HS_Student.h"

// Calls Student default Student constructors 
// to set inherited private member variables name and year
// Sets private member variable activity to empty string
HS_Student::HS_Student(): Student(), activity("")
{

}

// Calls Student default Student constructor to set inherited private member 
// variable name and year to given newName and newyear 
// Sets private member variable activity to given newActivity
HS_Student::HS_Student(std::string newName, int newYear, std::string newActivity):
	Student(newName, newYear), activity(newActivity)
{
}

void HS_Student::setActivity(std::string newActivity)
{
	// Sets private member variable activity to given newActivity
	activity = newActivity;
}

// 
std::string HS_Student::getActivity() const
{
	// Return the value of private member variable activity
	return activity;
}
 

