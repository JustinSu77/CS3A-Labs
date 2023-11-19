/**
	Date: 11/14/2023
	By: Justin Su
	Purpose: Person.cpp for Problem #1 of Lab #19
**/
#include "Person.h"

// Sets private member variable name to empty string
// Sets private member variable age to 0
Person::Person(): name(""), age(0)
{

}

// Sets private member variable name to given newName
// Sets private member variable age to given newAge
Person::Person(std::string newName, int newAge): 
	name(newName), age(newAge)
{

}

void Person::setName(std::string newName)
{
	// Sets private member variable name to given newName
	name = newName;
}

void Person::setAge(int newAge)
{
	// Sets private member variable age to given newAge
	age = newAge;
}

std::string Person::getName() const
{
	// Return value of private member variable name
	return name;
}

int Person::getAge() const
{
	// Return value of private member variable age
	return age;
}


