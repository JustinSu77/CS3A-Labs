/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: MS_Student.cpp for Problem #1 of Lab #20
**/
#include "MS_Student.h"

// Calls default parent constructor to initialize inherited 
// private member variables name type, name, and year  
// Sets private member variable englishScore to 0
// Sets private member variable mathScore to 0
MS_Student::MS_Student(): Student(), englishScore(0), mathScore(0)
{

}

// Calls parent Student constructor to initialize 
// inherited private member variables type, name, and year 
// to given newType, newName, and newYear
// Sets private member variable englishScore to given newEnglishScore
// Sets private member variable mathScore to given newMathScore
MS_Student::MS_Student(char newType, string newName, int newYear, int newEnglishScore, int newMathScore): 
	Student(newType,newName, newYear), englishScore(newEnglishScore), mathScore(newMathScore)
{

}

void MS_Student::setEnglishScore(int newEnglishScore)
{
	/// Sets private member englishScore to given newEnglish score
	englishScore = newEnglishScore;
}

void MS_Student::setMathScore(int newMathScore)
{
	// Sets private member mathScore to given newMathScore
	mathScore = newMathScore;
}

int MS_Student::getEnglishScore() const
{
	// Return value of private member variable englishScore
	return englishScore;
}

int MS_Student::getMathScore() const
{
	// Return value of private member variable mathScore
	return mathScore;
}

void MS_Student::displayInfo() const
{
	// Output private member variables name, year, englishScore, 
	// and mathScore to terminal formatted
	cout << setw(10) <<  getName() << setw(2)  << getYear() << " " 
		<< getEnglishScore() << " " << getMathScore() << endl;
}

string MS_Student::getActivity() const
{
	// Return empty string for activity
	return "";
}

