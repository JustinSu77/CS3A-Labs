/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Person.h for Problem #1 of Lab #19
**/
#pragma once
#include <iostream>

// Person class
class Person
{
	// Public member functions
	public:
		/**
			Purpose: Default Constructor.
			Precondition: Person object is constructed with no arguments
			Postcondition: - Private member variable name is set to empty string
						   - Private member variable age is set to 0
		**/
		Person();
		
		/**
			Purpose: Constructor with 2 arguments.
			Precondition: Person object is constructed with 2 arguments
			Postcondition: - Private member variable name is set to given newName
						   - Private member variable age is to set to given newAge
		**/
		Person(std::string newName, int newAge);
		
		/**
			Purpose: Setter function for private member variable name.
			Precondition: Person object is instantiated
			Postcondition: Private member variable name is set to given newName
		**/
		void setName(std::string newName);

		/**
			Purpose: Setter function for private member variable age.
			Precondition: Person object is instantiated
			Postcondition: Private member variable age is set to given newAge
		**/
		void setAge(int newAge);


		/**
			Purpose: Getter function for private member variable name.
			Precondition: Person object is instantiated
			Postcondition: Value of private member variable name is returned
		**/
		std::string getName() const;

		/**
			Purpose: Getter function for private member variable age.
			Precondition: Person object is instantiated
			Postcondition: Value of private member variable age is returned
		**/
		int getAge() const;

	// Private member variables
	private:
		std::string name;
		int age;
};

