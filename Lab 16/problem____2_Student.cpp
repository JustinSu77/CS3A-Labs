/**
	Date: 10/31/2023
	By: Justin Su
	Purpose: Student.cpp for Problem #2 of Lab #16
**/
#include "Student.h"

// Default constructor
// Set private member variable id to 0
// Set private member variable name to ""
// Set private member variable score to 0
Student::Student():id(0), name(""), score(0)
{

}

// Constructor with 3 arguments
// Set private member variable id to given newId
// Set private member variable name to given newName
// Set private member variable score to given newScore
Student::Student(int newId, std::string newName, int newScore): 
	id(newId), name(newName),score(newScore)
{

}


void Student::setId(int newId)
{
	// Set private member variable id to given newId
	id = newId;
}

void Student::setName(std::string newName)
{
	// Set private member variable name to given newName
	name = newName;
}

void Student::setScore(int newScore)
{
	// Set private member variable 
	// score to given newScore
	score = newScore;
}

int Student::getId() const
{
	// Return private member 
	// variable id
	return id;
}

std::string Student::getName() const
{
	// Return private member 
	// variable name
	return name;
}

int Student::getScore() const
{
	// Return private member 
	// variable score
	return score;
}
