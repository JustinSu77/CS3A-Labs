/**
	Date: 11/16/2023
	By: Justin Su
	Purpose: HS_Student.h for Problem #1 of Lab #20
**/
#include "Student.h"

// HS_Student class inherits from Student class
class HS_Student : public Student
{
	// Private member variable
	private:
		string activity;
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: HS_Student object is instantiated
			Postcondition: Private member variable activity is set to empty string
		**/
		HS_Student();

		/**
			Purpose: Constructor with 4 arguments.
			Precondition: HS_Student object is instantiated
			Postcondition: - Calls Student constructor to set inherited private member variables type, name, and year to given newType, newName, and newYear
						   - Sets private member variable activity to given newActivity
		**/
		HS_Student(char newType, string newName, int newYear, string newActivity);
		
		/**
			Purpose: Setter function for private member variable activity.
			Precondition: HS_Student object is instantiated
			Postcondition: Sets private member variable activity to given newActivity
		**/
		void setActivity(string newActivity);

		/**
			Purpose: Getter function for private member variable activity.
			Precondition: HS_Student object is instantiated
			Postcondition:  The value of private member variable activity is returned
		**/
		virtual string getActivity() const;

		/**
			Purpose: Implements the pure virtual function displayInfo
					 from base Student class.
			Precondition: MS_Student object is instantiated
			Postconditon: - Values of inherited private member variables
							name and year are outputted to terminal formatted
						  - Value of private member variable activity is also 
						    outputted to terminal  
		**/
		virtual void displayInfo() const;

		/**
			Purpose: Implements getEnglishScore function from base Student 
			         class so HS_Student will not become abstract class.
			Precondition: HS_Student object is instantiated polymorphpically 
						  with Student base class
			Postcondition: 0 is returned
		**/
		virtual int getEnglishScore() const;

		/**
			Purpose: Implements getMathScore function from base Student
					 class so HS_Student will not become abstract class.
			Precondition: HS_Student object is instantiated polymorphpically
					      with Student base class
			Postcondition: 0 is returned
		**/
		virtual int getMathScore() const;
};