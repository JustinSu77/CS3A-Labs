/**
	Date: 11/2/2023
	By: Justin Su
	Purpose: Node.h for Lab #17
**/
#pragma once

// Class for Node of Linked List
class Node
{
public:
	/**
		Purpose: Default constructor.
		Precondition: Node object is instantiated
		Postcondition: -Private member variable data is set to 0
					   -Private member variable link is set to NULL
	**/
	Node();

	/**
		Purpose: Constructor with 2 arguments.
		Precondition: Node object is instantiated
		Postcondition: -Private member variable newData
					   is set to given newData
					   -Private member variable nextNode is set
					   to point to given nextNode
	**/
	Node(int newData, Node* nextNode);

	/**
		Purpose: Setter function for private member variable data.
		Precondition: Node object is instantiated
		Postcondition: Private member variable data is set to given newData
	**/
	void setData(int newData);

	/**
		Purpose: Setter function for private member variable link
		Precondition: Node object is instantiated
		Postcondition: Private member variable link is set to given nextNode
	**/
	void setLink(Node* nextNode);

	/**
		Purpose: Getter function for private member variable data.
		Precondition: Node object is instantiated
		Postcondition: Private member data is returned
	**/
	int getData() const;

	/**
		Purpose: Getter function for private member variable.
		Precondition: Node object is instantiated
		Postcondition: Private member link is returned
	**/
	Node* getLink() const;
private:
	int data;
	Node* link;
};

