/**
	Dare: 11/14/2023
	By: Justin Su
	Purpose: Student.cpp for Problem #2 of Lab #19
**/
#include "Student.h"

Student::Student(): name(""), year(0)
{

}

Student::Student(std::string newName, int newYear): name(newName), year(newYear)
{

}

void Student::setName(std::string newName)
{
	name = newName;
}

void Student::setYear(int newYear)
{
	year = newYear;
}

std::string Student::getName() const
{
	return name;
}

int Student::getYear() const
{
	return year;
}
