/**
	Date: 11/28/2023
	By: Justin Su
	Purpose: Data.h for Problem #2 of Lab #22
**/
#ifndef DATA_H
#define DATA_H
// Templated Data class
// Set T as templated data type name
template <class T>
class Data
{
	// Public member functions
public:
	/**
		Purpose: Default constructor.
		Precondition: Object of this class is instantiated with no arguments
		Postcondition: - Private member variable number is set to nullptr
					   - Private member variable count is set to 0
	**/
	Data();

	/**
		Purpose: Constructor with 2 arguments.
		Precondition: Object of this class is instantiated with 2 arguments
		Postcondition: - Private member variable number points to
						 dynamic array of data type T with size of given newCount
					   - Elements of given newNumber dynamic array is copied into dynamic
					     array pointed to by pointer number
					   - Private member variable count is set to given newCount
	**/
	Data(T* newNumber, int newCount);
	/**
		Purpose: Copy constructor.
		Precondition: Object of this class is instantiated with another
					  existing object of this class
		Postcondition: - Private member variable count is set to
						 count of given obj
					   - Private member variable number points to dynamic
						 array with data type T
					   - Elements of the private member variable number of
						 given obj is copied into dynamic array pointed to by
						 private member variable number
	**/
	Data(const Data<T>& obj);

	/**
		Purpose: Destructor
		Precondition: Object of this class is instantiated
		Postcondition: Dynamic array pointed to by private member
					   variable number is deallocated
	**/
	~Data();

	/**
		Purpose: Setter function for private member variable number.
		Precondition: Object of this class is instantiated
		Postcondition: Elements of dynamic array of type T pointed to by newNumber is
					   copied into dynamic array of type T pointed to by private
					   member variable number
	**/
	void setNumber(T* newNumber);

	/**
		Purpose: Setter function for private member variable count.
		Precondition: Object of this class is instantiated
		Postcondition: Private member variable count is set to given count
	**/
	void setCount(int newCount);

	/**
		Purpose: Getter function for private member variable number.
		Precondition: Object of this class is instantiated
		Postcondition: Dynamic array pointed to by private
					   member variable number is returned
	**/
	T* getNumber() const;

	/**
		Purpose: Setter function for private member variable count.
		Precondition: Object of this class is instantiated
		Postcondition: Value of private member variable count is returned
	**/
	int getCount() const;

	/**
		Purpose: Overloaded = operator.
		Precondition: Object of this class is instantiated
		Postcondition: - Private member variable count is set to count of given object
					   - Private member variable number points to dynamic
						 array of type T with size of count
					   - Elements of the dynamic array of given object is
						 copied into dynamic array of type T pointed to by
						 private member variable number
	**/
	Data<T>& operator=(const Data<T>& obj);
	// Public member variables
private:
	T* number;
	int count;
};

// Sets private member variable number to nullptr
// Sets private member variable count to 0
template<class T>
Data<T>::Data() : number(nullptr), count(0)
{

}

// Set private member variable count to given newCount
template<class T>
Data<T>::Data(T* newNumber, int newCount) : count(newCount)
{
	// Set private member variable number to dynamic 
	// array of type T with size of count
	this->number = new T[count];
	// Copy elements from given newNumber dynamic array to dynamic 
	// array pointed to by private member variable number
	for (int i = 0; i < count; i++)
	{
		this->number[i] = newNumber[i];
	}
}

// Sets private member variable count to the count of 
// given object of this class
template<class T>
Data<T>::Data(const Data& obj) : count(obj.count)
{
	// Sets private member variable number to dynamic 
	// array of type T with size of count
	this->number = new T[count];
	// Copy elements from the private member variable number of given 
	// object of this class into the dynamic array pointed 
	// to by private member variable number
	for (int i = 0; i < count; i++)
	{
		this->number[i] = obj.number[i];
	}
}

template<class T>
Data<T>::~Data()
{
	// Deallocate dynamic array pointed to by private 
	// member variable number
	delete[] number;
}

template<class T>
void Data<T>::setNumber(T* newArray)
{
	// Set private member variable number to dynamic array of 
	// type T with size of private member variable count
	number = new T[count];
	// Copy elements from the given dynamic array to dynamic array 
	// pointed to by private member variable number
	for (int i = 0; i < count; i++)
	{
		this->number[i] = newArray[i];
	}
}

template<class T>
void Data<T>::setCount(int newCount)
{
	// Sets private member variable count to given newCount
	this->count = newCount;
}

template<class T>
T* Data<T>::getNumber() const
{
	// Return dynamic array pointed to by 
	// private member variable number
	return number;
}

template<class T>
int Data<T>::getCount() const
{
	// Return value of private member variable count
	return count;
}

template<class T>
Data<T>& Data<T>::operator=(const Data<T>& obj)
{
	// Set privare member variable count to the value of 
	// the private member variable count of given obj
	count = obj.count;
	// Set private member variable number to point to dynamic 
	// array of type T with size of private member variable count
	number = new T[count]{};
	// Copy elements from dynamic array of obj to dynamic array 
	// pointed to by private member variable number
	for (int i = 0; i < count; i++)
	{
		number[i] = obj.number[i];
	}
	// Return instance of this class
	return *this;
}
#endif