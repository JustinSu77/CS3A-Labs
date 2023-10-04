/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: Student.cpp for Problem #3 of Lab #11
**/
#include "Student.h"

// Use constructor initialization list to initialize private member variables to 0
Student::Student():name(""),mathScore(0),englishScore(0)
{
}

// Use constructor initialization list to initialize private member variables to their corresponding argument
Student::Student(string newName, int newMathScore, int newEnglishScore):name(newName), 
mathScore(newMathScore),englishScore(newEnglishScore)
{

}

void Student::setName(string newName)
{
	// Set private member variable name to given newName
	name = newName;
}

void Student::setMathScore(int newMathScore)
{
	// Set private member variable mathScore to given newMathScore
	mathScore = newMathScore;
}

void Student::setEnglishScore(int newEnglishScore)
{
	// Set private member variable englishScore to given newEnglishScore
	englishScore = newEnglishScore;
}

string Student::getName() const
{
	// Return private member variable name
	return name;
}

int Student::getMathScore() const
{
	// Return private member variable mathScore
	return mathScore;
}

int Student::getEnglishScore() const
{
	// Return private member variable englishScore
	return englishScore;
}


