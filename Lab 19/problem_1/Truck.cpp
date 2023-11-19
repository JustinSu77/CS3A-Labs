/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Truck.cpp for Problem #1 of Lab #19
**/
#include "Truck.h"

// Calls default Vehicle constructor first to set inheried 
// private member variables to their default values
// Sets private member variable model to empty string
// Sets private member variable load to 0
Truck::Truck(): Vehicle(), model(""), load(0)
{

}

// Calls Vehicle constructor to set inherited private member variables 
// make, cylinder, and owner to given newMake, newCylinder, and newOwner
// Sets private member variable model to given newModel
// Sets private mmeber variable load to given newLoad
Truck::Truck(std::string newMake, std::string newModel, int newCylinder, int newLoad, Person newOwner): 
	Vehicle(newMake, newCylinder, newOwner), model(newModel), load(newLoad)
{

}

void Truck::setModel(std::string newModel)
{
	// Sets private member variable model to given newModel
	model = newModel;
}

void Truck::setLoad(int newLoad)
{
	// Sets private member variable model to given newLoad
	load = newLoad;
}

std::string Truck::getModel() const
{
	// Returns value of  private member variable model
	return model;
}

int Truck::getLoad() const
{
	// Returns value of private member variable load
	return load;
}

