/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Truck.h for Problem #1 of Lab #19
**/
#pragma once
#include <iostream>
#include "Vehicle.h"

// Truck class that inherits from Vehicle class
class Truck : public Vehicle
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: Truck is constructed with no arguments
			Postcondition: - Default constructor for Vehicle is called
						   - Private member variable model is set to empty string
						   - Private member variable load is set to 0
		**/
		Truck();
		
		/**
			Purpose: Constructor with 5 arguments.
			Precondition: Truck is constructed with 5 arguments.
			Postcondition: - Constructor for Vehicle class is called 
						     with given newMake, newCylinder, newOwner
						   - Private member variable model is set to given newModel
						   - Private member variable load is set to given newLoad
		**/
		Truck(std::string newMake, std::string newModel, int newCylinder, int newLoad, Person newOwner);
		
		/**
			Purpose: Setter function for private member variable model.
			Precondition: Truck is instantiated
			Postcondition: Private member variable model is set to given newModel
		**/
		void setModel(std::string newModel);

		/**
			Purpose: Setter function for private member variable load.
			Precondition: Truck is instantiated
			Postcondition: Private member variable load is set to given newLoad
		**/
		void setLoad(int newLoad);

		/**
			Purpose: Getter function for private member variable model.
			Precondition: Truck is instantiated
			Postcondition: Value of private member variable model is returned
		**/
		std::string getModel() const;

		/**
			Purpose: Getter function for private member variable load.
			Precondition: Truck is instantiated
			Postcondition: Value of private member variable load is returned
		**/
		int getLoad() const;

	// Private member variables
	private:
		std::string model;
		int load;
};

