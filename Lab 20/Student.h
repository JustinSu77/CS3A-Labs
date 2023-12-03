/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: Student.h for Problem #1 of Lab #20
**/
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

// Abstract Student class
class Student
{
	// Privae member variables
	private:
		char type;
		string name;
		int year;
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: Student object is constructed with no arguments
			Postcondition: - Private member variable type is set to U
						   - Private member variable name is set to empty string
						   - Private member variable year is set to 0
		**/
		Student();
		
		/**
			Purpose: Constructor with 3 arguments.
			Precondition: Student object is constructed with 3 arguments
			Postcondition: - Private member variable type is set to given type
						   - Private member variable name is set to empty string
						   - Private member variable year is set to year
		**/
		Student(char newType, string newName, int newYear);
		
		/**
			Purpose: Setter for private member variable type.
			Precondition: Student object is instantiated
			Postconditon: Private member variable type is set to given newType
		**/
		void setType(char newType);

		/**
			Purpose: Setter for private member variable name.
			Precondition: Student object is instantiated
			Postcondition: Private member variable name is set to given newName 
		**/
		void setName(string newName);
		
		/**
			Purpose: Setter for private member variable year.
			Precondition: Student object is instantiated
			Postcondition: Private member variable year is set to given newYear
		**/
		void setYear(int newYear);

		/**
			Purpose: Getter for private member variable type.
			Precondition: Student object is instantiated
			Postcondition: Value of private member variable type is returned
		**/
		char getType() const ;

		/**
			Purpose: Getter for private member variable name.
			Precondition: Student object is instantiated
			Postcondition: Value of private member variable name is returned
		**/
		string getName() const;
		
		/**
			Purpose: Getter for private member variable year.
			Precondition: Student object is instantiated
			Postconditon: Value of private member variable year is returned
		**/
		int getYear() const;

		/**
			Purpose: Pure virtual function to allow derived class to display their 
			         own private member variables formatted to the terminal
		**/
		virtual void displayInfo() const = 0;
		/**
			Purpose: Pure virtual function to allow accessing private member variable 
			         mathScore of MS_Student object with out downcasting.
		**/
		virtual int getMathScore()  const = 0;
		
		/**
			Purpose: Pure virtual function to allow accessing english 
			         score of MS_Student object with out downcasting.
		**/
		virtual int getEnglishScore() const = 0;

		/**
			Purpose: Pure virtual function to allow accessing activity 
			         of HS_Student object withour downcasting.
		**/
		virtual string getActivity() const = 0;
};

