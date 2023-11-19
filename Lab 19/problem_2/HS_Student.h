/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: HS_Student.h for Problem #2 of Lab #19
**/
#pragma once
#include "Student.h"

// High school student class inherits from Student class
class HS_Student : public Student
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: HS_Student is constructed with no arguments
			Postcondition: - Calls Student default constructor
						   - Sets private member variable activity to empty string 	
		**/
		HS_Student();

		/**
			Purpose: Constructor with 3 arguments.
			Precondition: HS_Student is constructed with 3 arguments
			Postcondition: - Calls constructor with 2 arguments of Student 
							 class to set inherited private member variables name 
							 and year to given newName and newYear
						   - Sets private member variable activity to newActivity
		**/
		HS_Student(std::string newName, int newYear, std::string newActivity);
		
		/**
			Purpose: Setter function for private member variable activity.
			Precondition: HS_Student object is instantiated
			Postcondition: Sets private member variable activity to given newActivity
		**/
		void setActivity(std::string newActivity);

		/**
			Purpose: Getter function for private member activity.
			Precondition: HS_Student object is instantiated
			Postcondition: Value of private member variable activity is returned
		**/
		std::string getActivity() const;

	// Private member variable
	private:
		std::string activity;
};

