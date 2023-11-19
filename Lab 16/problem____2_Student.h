/**
	Date: 10/31/2023
	By: Justin Su
	Purpose: Student.h for Problem #2 of Lab #16
**/
#pragma once
#include <iostream>

// Student class
class Student
{
	// Public member functions
public:
	/**
		Purpose: Default contructor.
		Precondition: Student object is instantiated with no arguments
		Postcondition: - Sets private member variable id to 0
					   - Sets private member variable name 
					     to empty string
					   - Sets private member variable score to 0
	**/
	Student();
	/**
		Purpose: Constructor with 3 arguments.
		Precondition: Student object is instantiated with 3 arguments
		Postcondition: - Sets private member variable 
		                 id to given newId
					   - Sets private member variable 
					     name to given newName
					   - Sets private member variable 
					     score to given newScore
	**/
	Student(int newId, std::string newName, int newScore);

	/**
		Purpose: Setter function for private member variable id.
		Precondition: Student object is instantiated
		Postcondition: Private member variable id to given newId
	**/
	void setId(int newId);

	/**
		Purpose: Setter function for private member variable name.
		Precondition: Student object is instantiated
		Postcondition: Private member variable name to given newName
	**/
	void setName(std::string newName);

	/**
		Purpose: Setter function for private member variable score.
		Precondition: Student object is instantiated
		Postcondition: Private member variable score to given newScore
	**/
	void setScore(int newScore);

	/**
		Purpose: Getter function for private member variable id.
		Precondition: Student object is instantiated
		Postcondition: Private member variable id is returned
	**/
	int getId() const;

	/**
		Purpose: Getter function for private member variable name.
		Precondition: Student object is instantiated
		Postcondition: Private member variable name is returned
	**/
	std::string getName() const;

	/**
		Purpose: Getter function for private member variable score.
		Precondition: Student object is instantiated
		Postcondition: Private member variable score is returned
	**/
	int getScore() const;
	// Private member variables
private:
	// Private member variable id
	int id;
	// Private member variable name
	std::string name;
	// Private member variable score
	int score;
};

