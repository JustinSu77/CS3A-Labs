/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: MS_Student.h for Problem #2 of Lab #19
**/
#include "MS_Student.h"

// Calls Student default constructorto set inherited 
// private member variable name and year
// Set private member variable mathScore to 0
// Set privare member variable scienceScore to 0
MS_Student::MS_Student(): Student(), mathScore(0), scienceScore(0)
{
}

// Calls Student constructor with 2 argument to set inherited private 
// member variables name and year to given newName and newYear
// Set private member variable mathScore to given newMathScore
// Set private member variable scienceScore to given newScienceScore
MS_Student::MS_Student(std::string newName, int newYear, int newMathScore, int newScienceScore): 
	Student(newName, newYear), mathScore(newMathScore), scienceScore(newScienceScore)
{

}

void MS_Student::setMathScore(int newMathScore)
{
	// Sets private member variable mathScore to given newMathScore
	mathScore = newMathScore;
}

void MS_Student::setScienceScore(int newScienceScore)
{
	// Sets private member variale scienceScore to given newScienceScore 
	scienceScore = newScienceScore;
}

int MS_Student::getMathScore() const
{
	// Return the value of private member variable mathScore
	return mathScore;
}

int MS_Student::getScienceScore() const
{
	// Return the value of private member variable scienceScore
	return scienceScore;
}

