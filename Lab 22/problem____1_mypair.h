/**
	Date: 11/28/2023
	By: Justin Su
	Purpose: mypair.h for Problem #1 of Lab #22
**/
#ifndef MYPAIR_H
#define MYPAIR_H
#include <iostream>

// Templated key-value pair class
// Set T and S as templated data type names
template<class T, class S>
class mypair
{
	// Public member functions
public:
	/**
		Purpose: Default constructor.
		Precondition: Object of this class is constructed with no arguments
		Postcondition: - Private member variable key is set to its default constructor value
					   - Private member variable value is set to its default constructor value
	**/
	mypair();

	/**
		Purpose: Constructor with 2 arguments.
		Precondition: Object of this class is constructed with 2 arguments
		Postcondition: - Private member variable key is set to given newKey
					   - Private member variable value is set to given newValue
	**/
	mypair(T newKey, S newValue);

	/**
		Purpose: Setter function for private member variable key.
		Precondition: Object of this class is instantiated
		Postcondition: Private member variable key is set to given newKey
	**/
	void setKey(T newKey);

	/**
		Purpose: Setter function for private member variable value.
		Precondition: Object of this class is instantiated
		Postcondition: Private member variable value is set to given newValue
	**/
	void setValue(S newValue);

	/**
		Purpose: Getter function for private member variable key.
		Precondition: Object of this class is instantiated
		Postcondition: Value of private member variable key is returned
	**/
	T getKey() const;

	/**
		Purpose: Getter function for private member variable value.
		Precondition: Object of this class is instantiated
		Postcondition: Value of private member variable value is returned
	**/
	S getValue() const;

	/**
		Purpose: Output the values of private member variables key and value
	**/
	void show();
	// Private member variables
private:
	T key;
	S value;
};

template<class T, class S>
mypair<T, S>::mypair()
{
	// Set key to the default constructor of data type T
	key = T();
	// Set value to the default constructor of data type S
	value = S();
}

template<class T, class S>
mypair<T, S>::mypair(T newKey, S newValue) :key(newKey), value(newValue)
{

}

template<class T, class S>
void mypair<T, S>::setKey(T newKey)
{
	// Set value of private member variable 
	// key to given newKey
	key = newKey;
}

template<class T, class S>
void mypair<T, S>::setValue(S newValue)
{
	// Set value of private member variable 
	// value to given newValue
	value = newValue;
}

template<class T, class S>
T mypair<T, S>::getKey() const
{
	// Return the value of private 
	// member variable key
	return key;
}

template<class T, class S>
S mypair<T, S>::getValue() const
{
	// Return the value of private member 
	// variable value
	return value;
}

template<class T, class S>
void mypair<T, S>::show()
{
	// Output values of private member 
	// variables key and value formatted to 
	// terminal
	std::cout << "Key : " << key
		<< ", Value : " << value << std::endl;
}
#endif