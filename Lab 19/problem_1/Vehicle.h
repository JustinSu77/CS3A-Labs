/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Vehicle.h for Problem #1 of Lab #19
**/
#pragma once
#include <iostream>
#include "Person.h"

// Vehicle Class
class Vehicle
{
	// Public member functions
	public:
		/**
			Purpose: Default Constructor.
			Precondition: Vehicle object is constructed with no arguments
			Postcondition: - Private member variable make is set to empty string
						   - Private member variable cylinder is set to 0
						   - Private member variable owner is set to default Person object
		**/
		Vehicle();
		
		/**
			Purpose: Constructor with 3 arguments.
			Precondition: Vehicle object is constructed with 3 arguments
			Postcondition: - Private member variable make is set to given newName
						   - Private member variable cylinder is set to given newCylinder
						   - Private member variable owner is to set to given newOwner
		**/
		Vehicle(std::string newMake, int newCylinder, Person newOwner);

		/**
			Purpose: Setter function for private member variable make.
			Precondition: Vehicle object is instantiated
			Postcondition: Private member variable make is set to given newMake
		**/
		void setMake(std::string newMake);

		/**
			Purpose: Setter function for private member variable cylinder.
			Precondition: Vehicle object is instantiated
			Postcondition: Private member variable cylinder is set to given newCylinder
		**/
		void setCylinder(int newCylinder);

		/**
			Purpose: Setter function for private member variable owner.
			Precondition: Vehicle object is instantiated
			Postcondition: Private member variable owner is set to newOwner
		**/
		void setOwner(Person newOwner);
		
		/**
			Purpose: Getter function for private member variable make.
			Precondition: Vehicle object is instantiated
			Postcondition: Value of private member variable make is returned 
		**/
		std::string getMake() const;

		/**
			Purpose: Getter function for private member variable cylinder.
			Precondition: Vehicle object is instantiated
			Postcondition: Value of private member variable cylinder is returned
		**/
		int getCylinder() const;

		/**
			Purpose: Getter function for private member variable owner.
			Precondition: Vehicle object is instantiated
			Postcondition: Value of private member variable owner is returned.
		**/
		Person getOwner() const;
	
	// Private member variables
	private:
		std::string make;
		int cylinder;
		Person owner;
};

