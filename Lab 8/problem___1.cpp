/**
	Date: 9/21/2023
	By: Justin Su
	Purpose: Problem #1 of Lab #8
**/
#include <iostream>
using namespace std;

// Student class
class Student
{
// Private fields
 private:
	int id;
    string name;
	int score;
// Public fields
 public:
	 //Default constructor
	 Student();
	 // Constructor to set all private fields to given values
	Student(int newId, string newName, int newScore);
	// Setter function for id
	void setId(int newId);
	// Getter function for id
	int getId();
	// Setter function for name
	void setName(string newName);
	// Getter function for name
	string getName();
	// Setter function for score
	void setScore(int newScore);
	// Getter function for score
	int getScore();
};

int main()
{
	// Construct 3 Student objects
	Student alice(203, "Alice Bauer", 88);
	Student bob(300, "Bob Hahn", 85);
	Student cindy(123, "Cindy Potter", 93);
	
	// If alice has the highest score
	if ((alice.getScore() >= bob.getScore()) && (alice.getScore() >= cindy.getScore()))
	{
		// if bob's score is larger than cindy's score
		if (bob.getScore() > cindy.getScore())
		{
			// Output alice as first
			cout << "1. " << alice.getName() << " (" << alice.getId() << ", " << alice.getScore() << ") " << endl;
			// Output bob as second
			cout << "2. " << bob.getName() << " (" << bob.getId() << ", " << bob.getScore() << ") " << endl;
			// Output cindy as third
			cout << "3. " << cindy.getName() << " (" << cindy.getId() << ", " << cindy.getScore() << ") " << endl;
		}
		// if cindy's score is larger than bob's score
		else
		{
			// Output alice as first
			cout << "1. " << alice.getName() << " (" << alice.getId() << ", " << alice.getScore() << ") " << endl;
			// Output cindy as second
			cout << "2. " << cindy.getName() << " (" << cindy.getId() << ", " << cindy.getScore() << ") " << endl;
			// Output bob as third
			cout << "3. " << bob.getName() << " (" << bob.getId() << ", " << bob.getScore() << ") " << endl;

		}
	}
	// If bob has the highest score
	else if ((bob.getScore() >= alice.getScore()) && (bob.getScore() >= cindy.getScore()))
	{
		// If alice's score is higher than cindy's score
		if (alice.getScore() > cindy.getScore())
		{
			// Output bob as first
			cout << "1. " << bob.getName() << " (" << bob.getId() << ", " << bob.getScore() << ") " << endl;
			// Output alice as second
			cout << "2. " << alice.getName() << " (" << alice.getId() << ", " << alice.getScore() << ") " << endl;
			// Output cindy as third
			cout << "3. " << cindy.getName() << " (" << cindy.getId() << ", " << cindy.getScore() << ") " << endl;
		}
		// If cindy's score is higher than alice's score
		else
		{
			// Output bob as first
			cout << "1. " << bob.getName() << " (" << bob.getId() << ", " << bob.getScore() << ") " << endl;
			// Output cindy as second
			cout << "2. " << cindy.getName() << " (" << cindy.getId() << ", " << cindy.getScore() << ") " << endl;
			// Output alice as third
			cout << "3. " << alice.getName() << " (" << alice.getId() << ", " << alice.getScore() << ") " << endl;
		}
	}
	// If cindy has highest score
	else if ((cindy.getScore() >= alice.getScore()) && (cindy.getScore() >= bob.getScore()))
	{
		// If alice's score is higher than bob's score
		if (alice.getScore() > bob.getScore())
		{
			// Output cindy as first
			cout << "1. " << cindy.getName() << " (" << cindy.getId() << ", " << cindy.getScore() << ") " << endl;
			// Output alice as second
			cout << "2. " << alice.getName() << " (" << alice.getId() << ", " << alice.getScore() << ") " << endl;
			// Output bob as third
			cout << "3. " << bob.getName() << " (" << bob.getId() << ", " << bob.getScore() << ") " << endl;
		}
		// If bob's score is higher than alice's score
		else
		{
			// Output cindy as first
			cout << "1. " << cindy.getName() << " (" << cindy.getId() << ", " << cindy.getScore() << ") " << endl;
			// Output bob as second
			cout << "2. " << bob.getName() << " (" << bob.getId() << ", " << bob.getScore() << ") " << endl;
			// Output alice as third
			cout << "3. " << alice.getName() << " (" << alice.getId() << ", " << alice.getScore() << ") " << endl;
		}
	}


	return 0;
}

Student::Student()
{
	// Set id to 0
	id = 0;
	// Set name to empty string
	name = "";
	// Set score to 0
	score = 0;
}

Student::Student(int newId, string newName, int newScore)
{
	// Set id to given newId
	id = newId;
	// Set name to given newName
	name = newName;
	// Set score to given newScore
	score = newScore;
}

void Student::setId(int newId)
{
	// Set id to given newId
	id = newId;
}

int Student::getId()
{

	return id;
}

void Student::setName(string newName)
{
	// Set name to given newName
	name = newName;
}

string Student::getName()
{
	return name;
}

void Student::setScore(int newScore)
{
	// Set score to given newScore
	score = newScore;
}

int Student::getScore()
{
	return score;
}
