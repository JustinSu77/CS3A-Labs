/**
	Date: 11/2/2023
	By: Justin Su
	Purpose: Node.cpp for Lab #17
**/
#include <iostream>
#include "Node.h"

// Set private member variable data to 0
// Set private member variable link to NULL
Node::Node() :data(0), link(NULL)
{

}

// Set private member variable data to given newdata
// Set private member variable link to given nextNode
Node::Node(int newData, Node* nextNode) :data(newData), link(nextNode)
{

}

void Node::setData(int newData)
{
	// Set private member variable data to given newData
	data = newData;
}

void Node::setLink(Node* nextNode)
{
	// Set private member variable link to given nextNode
	link = nextNode;
}

int Node::getData() const
{
	// Return private member variable data
	return data;
}

Node* Node::getLink() const
{
	// Return private member variable link
	return link;
}
