/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: Student.cpp for Problem #1 of Lab #20
**/
#include "Student.h"

// Set private member variable type to U
// Set private member variable name to empty string
// Set private member variable year to 0
Student::Student(): type('U'), name(""), year(0)
{

}

// Set private member variable type to newType
// Set private member variable name to newName
// Set private member variable year to newYear
Student::Student(char newType, string newName, int newYear): type(newType), name(newName), year(newYear)
{

}

void Student::setType(char newType)
{
	// Set private member type to given newType
	type = newType;
}

void Student::setName(string newName)
{
	// Set private member name to given newName
	name = newName;
}

void Student::setYear(int newYear)
{
	// Set private member year to given newYear
	year = newYear;
}

char Student::getType() const
{
	// Return value of private member variable type
	return type;
}

string Student::getName() const
{
	// Return value of private member variable name
	return name;
}

int Student::getYear() const
{
	// Return value of private member variable year
	return year;
}

