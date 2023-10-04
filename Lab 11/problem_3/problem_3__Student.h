#pragma once
/**
	Date: 10/3/2023
	By: Justin Su
	Purpose: Student.h for Problem #3 of Lab #11
**/
#include <iostream>
using namespace std;
class Student
{
    public:
		/**
			Default constructor.
			Precondition: Student object is instantiated
			Postcondition: Private member variable name is set to empty string
						   Private member variable mathScore is set to 0
						   Private member variable englishScore is set to 0
		**/
		Student();

		/**
			Constructor with 3 arguments.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable name is set to given newName.
						   Private member variable mathScore is set to given newMathScore.
						   Private member variable englishScore is set to given newEnglishScore.
			newName as value for name as string
			newMathScore as value for mathScore as int
			newEnglishScore as value for englishScore as int
		**/
		Student(string newName, int newMathScore, int newEnglishScore);

		/**
			Setter function for private member variable name.
			Precondition: Student object is instantiated.
			Postcodntion Set private member variable name to given newName
				newName as value for name as string
		**/
		void setName(string newName);
		
		/**
			Setter function for private member variable mathScore.
			Precondition: Student object is instantiated.
			Postcodntion Set private member variable mathScore to given newMathScore
				newMathScore as value for mathScore as int
		**/
		void setMathScore(int newMathScore);

		/**
			Setter function for private member variable englishScore.
			Precondition: Student object is instantiated.
			Postcodntion Set private member variable englishScore to given newEnglishScore
				newEnglishScore as value for englishScore as int
		**/
		void setEnglishScore(int newEnglishScore);

		/**
			Constant getter function for private member variable name.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable name is returned.
		**/
		
		string getName() const;
		/**
			Constant getter function for private member variable mathScore.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable mathScore is returned.
		**/
		
		int getMathScore() const;
		
		/**
			Constant getter function for private member variable englishScore.
			Precondition: Student object is instantiated.
			Postcondition: Private member variable englishScore is returned.
		**/
		int getEnglishScore() const;
	
	private:
		string name;
		int mathScore;
		int englishScore;
};

