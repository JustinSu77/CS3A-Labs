/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Vehicle.cpp for Problem #1 of Lab #19
**/
#include "Vehicle.h"

// Sets private member make to empty string
// Sets private mmeber cylinder to 0
// Sets private member owner to Person object by default constructor
Vehicle::Vehicle(): 
	make(""), cylinder(0), owner(Person())
{

}

// Sets private member variable make to given newMake
// Sets private member variable cylinder to given newCylinder
// Sets private member variable owner to given newOwner
Vehicle::Vehicle(std::string newMake, int newCylinder, Person newOwner): 
	make(newMake), cylinder(newCylinder),owner(newOwner)
{

}

void Vehicle::setMake(std::string newMake)
{
	// Sets privare member variable make to given newMake
	make = newMake;
}

void Vehicle::setCylinder(int newCylinder)
{
	// Sets privare member variable cylinder to given newCylinder
	cylinder = newCylinder;
}

void Vehicle::setOwner(Person newOwner)
{
	// Sets private member variable owner to given newOwner
	owner = newOwner;
}

std::string Vehicle::getMake() const
{
	// Return private member variable make
	return make;
}

int Vehicle::getCylinder() const
{
	// Return value of private member variable cylinder
	return cylinder;
}

Person Vehicle::getOwner() const
{
	// Return value of private member variable owner
	return owner;
}
