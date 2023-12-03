/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: MS_Student.h for Problem #1 of Lab #20
**/
#pragma once
#include "Student.h"

// MS_Student class inherits from Student class
class MS_Student : public Student
{
	// Private member variable
	private:
		int englishScore;
		int mathScore;
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: MS_Student object is constructed with no arguments
			Postcondition: - Private member variable englishScore is set to 0
						   - Private member variable mathScore is set to 0
		**/
		MS_Student();
		
		/**
			Purpose: Constructor with 5 arguments.
			Precondition: MS_Student object is constructed with 5 arguments
			Postcondition: - Calls Student constructor with given newType, newName, and newYear
						   - Private member variable englishScore is set to given newEnglishScore
						   - Private member variable mathScore is set to given newMathScore
		**/
		MS_Student(char newType, string newName, int newYear, int newEnglishScore, int newMathScore);
		
		/**
			Purpose: Setter function for private member variable englishScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Private member variable englishScore is set to given newEnglishScore
		**/
		void setEnglishScore(int newEnglishScore);

		/**
			Purpose: Setter function for private member variable mathScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Private member variable mathScore is set to to given newMathScore
		**/
		void setMathScore(int newMathScore);

		/**
			Purpose: Getter function for privare member variable englishScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Private member variable englishScore is set to given newEnglishScore
		**/
		virtual int getEnglishScore() const;

		/**
			Purpose: Getter function for privare member variable mathScore.
			Precondition: MS_Student object is instantiated
			Postcondition: Private member variable mathScore 
						   is set to given newMathScore
		**/
		virtual int getMathScore() const;

		/**
			Purpose: Implements the pure virtual function displayInfo 
					 from base Student class.
			Precondition: MS_Student object is instantiated
			Postconditon: - Values of inherited private member variables 
							name and year are outputed to terminal formatted
						  - Values of  private member variables englishScore 
						    and mathScore are also outputted to terminal
		**/
		virtual void displayInfo() const;
		
		/**
			Purpose: Implement pure virtual function getActivity from parent Student clas 
			         so MS_Student class will not become an abstract class
			Precondition: MS_Student object is instantiated polymorphpically 
						  with Student base class
			Postcondition: Empty string is returned
		**/
		virtual string getActivity() const;
};

