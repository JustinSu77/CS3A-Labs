/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Student.h for Problem #2 of Lab #19
**/
#pragma once
#include <iostream>

// Student class
class Student
{
	// Public functions
	public:
		/**
			Purpose: Default constructor
			Precondition: Student object is constructed with no arguments
			Postcondition: - Private member variable name is set to empty string
						   - Private member variable year is set to 0
		**/
		Student();

		/**
			Purpose: Constructor with 2 arguments
			Precondition: Student object is constructed with 2 arguments
			Postcondition: - Private member variable name is set to given newName
						   - Private member variable year is set to given newYear
		**/
		Student(std::string newName, int newYear);

		/**
			Purpose: Setter function for private member variable name.
			Precondition: Student object is instantiated
			Postcondition: Private member variable name is set to given newName
		**/
		void setName(std::string newName);

		/**
			Purpose: Setter function for private member variable year.
			Precondition: Student object is instantiated
			Postcondition: Private member variable year is set to given newYear
		**/
		void setYear(int newYear);

		/**
			Purpose: Getter function for private member variable name.
			Precondition: Student object is instantiated
			Postcondition: Value of private member variable name is returned
		**/
		std::string getName() const;

		/**
			Purpose: Getter function for private member variable.
			Precondition: Student object is instantiated
			Postcondition: Value of private member variable year is returned
		**/
		int getYear() const;

	// Public member variables
	private:
		std::string name;
		int year;
};

