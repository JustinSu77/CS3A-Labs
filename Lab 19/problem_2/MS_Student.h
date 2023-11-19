/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: MS_Student.h for Problem #2 of Lab #19
**/
#pragma once
#include "Student.h"
// Middle School Student class inherits from Student class
class MS_Student: public Student
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: MS_Student object is constructed with no arguments
			Postcondition: - Calls Student default constructor to set inherited 
			                 private member variables name and year to empty string and 0
						   - Sets private member variable mathScore to 0
						   - Sets private member variable scienceScore to 0
		**/
		MS_Student();

		/**
			Purpose: Constructor with 4 arguments.
			Precondition: MS_Student object is constructed with 4 arguments
			Postcondition: - Calls Student constructor with 2 arguments to set inherited private member			           functions name and year to given newName and year
						   - Sets private member variable mathScore to given newMathScore
						   - Sets private member variable scienceScore to given newScienceScore
		**/
		MS_Student(std::string newName, int newYear, int newMathScore, int newScienceScore);
		
		/**
			Purpose: Setter function for private member variable mathScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Sets private member variable mathScore to given newMathScore
		**/
		void setMathScore(int newMathScore);

		/**
			Purpose: Setter function for private member variable scienceScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Sets private member variable scienceScore to given newScienceScore
		**/
		void setScienceScore(int newScienceScore);

		/**
			Purpose: Getter function for private member variable mathScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Value of private member variable mathScore is returned
		**/
		int getMathScore() const;

		/**
			Purpose: Getter function for privare member variable scienceScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Value of private member variable scienceScore is returned
		**/
		int getScienceScore() const;

	// Private member variable
	private:
		int mathScore;
		int scienceScore;
};

