/**
	Date: 11/2/2023
	By: Justin Su
	Purpose: main.cpp for Problem #1 of Lab #17
**/

#include <iostream>
#include "Node.h"
using namespace std;

typedef Node* NodePtr;

/**
	Purpose: Output data of nodes in Linked List to terminal.
	Input: head as NodePtr to first node of Linked List
	Input Requirement: Given head as Nodeptr to first node of Linked List or is NULL
	Result: The data of each node in Linked List is outputted to terminal
**/
void printList(NodePtr head);

/**
	Purpose: Insert new node with given newValue 
			 into with head of given head Linked list while maintaining sorted order.
	Input: head as pointer ot first node of Linked List or NULL
		   newValue as the value the new node inserted will have
	Input Requirement: Given head should point to first node of LInked List or NULL
					   Given newValue should be an integer
	Result: - New dynamically allocated Node with given newValue is 
			 inserted into Linked List with head pointed by given head 
			 while maintaining sorted order
			-If Linked List was empty, make newNode the head
			-If newValue is less than data of head, insert it 
			 at the front of Linked List and make it the head 
**/
void insertNodeInSortedOrder(NodePtr& head, int newValue);

/**
	Purpose: Merges the two Linked Lists with their heads pointed 
			 to by the given NodePtr and returns a NodePtr to 
			 the head of this merged list.
	Input: listOne as NodePtr to head of first Linked List
		   listTwo as NodePtr to head of second Linked List
	Input Requirement: -Given listOneHead points to first node 
					    of first Linked List or NULL
					   -Given listTwoHead points to first node 
					    of second Linked List or NULL
	Result: A NodePtr pointer to a larger Linked List with the 
	        nodes of the given Linked Lists in sorted order is returned
**/
NodePtr mergeTwoLists(NodePtr listOneHead, NodePtr listTwoHead);


/**
	Purpose: Deallocates the nodes in Linked List with head pointed 
	to by given head
	Input: head as NodePtr to first node of Linked List
	Input Requirement: Given head points to the first node of Linked List
	Result: If given head is NULL, return
			Otherwise the nodes of Linked List is deallocated
**/
void deallocateList(NodePtr& head);

int main()
{
	// Declare and initialize variable for 
	// number of elements in first LinkedList
	int listOneSize = 0;
	// Prompt user for number of nodes first Linked List will have
	cout << "Enter the number of elements in first linkedlist: ";
	// Store userinput into listOneSize
	cin >> listOneSize;
	// If given listOneSize is less than or equal to 0
	if (listOneSize <= 0)
	{
		// Output newline to terminal for readability
		cout << endl;
		//Notify
		cout << "Size of first Linked List should be greater than 0" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable to store values node will have
	int nodeValue = 0;
	// Declare and initialize pointer to head of first Linked List
	NodePtr listOneHead = NULL;
	// Ask user for value of each node that will be in first Linked List 
	for (int i = 1; i <= listOneSize; i++)
	{
		// Prompt user for the value of each node
		cout << "Enter the " << i << " element of first linkedlist: ";
		// Store the userInput
		cin >> nodeValue;
		// Insert node with given nodeValue into linked list 
		// that has its head pointed to by listOneHead
		// Use this function to ensure no matter what order value 
		// of nodes is entered, the Linked List will always be sorted first
		insertNodeInSortedOrder(listOneHead, nodeValue);
	}
	// Output newline to terminal for readability
	cout << endl;
	
	// Declare and initialize variable for 
	// number of elements in second LinkedList
	int listTwoSize = 0;
	// Prompt user for number of nodes second Linked List will have
	cout << "Enter the number of elements in second linkedlist: ";
	// Store userinput into listTwoSize
	cin >> listTwoSize;
	// If given listTwoSize is less than or equal to 0
	if (listTwoSize <= 0)
	{
		// Output newline to terminal for readability
		cout << endl;
		//Notify
		cout << "Size of second Linked List should be greater than 0" << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize pointer to head of second Linked List
	NodePtr listTwoHead = NULL;
	// Ask user for value of each node that will be in second Linked List 
	for (int i = 1; i <= listTwoSize; i++)
	{
		// Prompt user for the value of each node
		cout << "Enter the " << i << " element of second linkedlist: ";
		// Store the userInput
		cin >> nodeValue;
		// Insert node with given nodeValue into linked list 
		// that has its head pointed to by listTwoHead
		// Use this function to ensure no matter what order value 
		// of nodes is entered, the Linked List will always be sorted first
		insertNodeInSortedOrder(listTwoHead, nodeValue);
	}
	// Output newline to terminal for readability
	cout << endl;
	 
	// Output the data of nodes in first linked List
	cout << "The first linked list is shown as:" << endl;
	printList(listOneHead);
	// Output the data of the nodes in second linked list
	cout << "The second linked list is shown as:" << endl;
	printList(listTwoHead);
	// Declare and initialize head pointer to the 
	// Linked List returned by mergeTwoLists function
	NodePtr head = mergeTwoLists(listOneHead, listTwoHead);
	// Output the nodes in merged Linked List
	cout << "Merged Linked List is: " << endl;
	printList(head);
	// Deallocate first linked list
	deallocateList(listOneHead);
	// Deallocate second linked list
	deallocateList(listTwoHead);
	// Deallocate merged linked list
	deallocateList(head);

	return 0;
}

void printList(NodePtr head)
{
	// If Linked List is empty
	if (head == NULL)
	{
		// Notify
		cout << "Linked List is empty!" << endl;
		// Get out of function
		return;
	}
	// Otherwise loop through linked List
	for (NodePtr iter = head; iter != NULL; iter = iter->getLink())
	{
		// Output the data with a -> after it
		cout << iter->getData() << "->";
	}
	// Output NULL and endline and the end
	cout << "NULL" << endl;
}

 

void insertNodeInSortedOrder(NodePtr& head, int newValue)
{
	// Create new node with given newValue that points to NULL
	NodePtr newNode = new Node(newValue, NULL);
	// If Linked List is empty
	if (head == NULL)
	{
		// Set head to new node
		head = newNode;
		// Get out of function
		return;
	}
	// If the given value is less than the data of head
	// Insert new node at head
	if (newValue <= head->getData())
	{
		// Set next node of new node to head
		newNode->setLink(head);
		// Set head to be new node
		head = newNode;
		return;
	}
	// Declare and initialize pointer to head
	NodePtr traverse = head;
	// Declare and initialize pointer that will be behind traverse
	NodePtr prev = head;
	// Traverse Linked List while traverse is not NULL or 
	// the data of traverse is not less than or equal to newValue
	while (traverse != NULL && traverse->getData() <= newValue)
	{
		// Set prev to current traverse
		prev = traverse;
		// Set traverse to next node
		traverse = traverse->getLink();
	}
	// Set the next node of newNode to be traverse
	newNode->setLink(traverse);
	// Set the next node of prev to be newn node
	prev->setLink(newNode);
}

NodePtr mergeTwoLists(NodePtr listOneHead, NodePtr listTwoHead)
{
	// Declare and initialize pointer to 
	// head of merged list that will be returned
	NodePtr result = NULL;
	// Declare and initialize pointer to first Linked List
	NodePtr traverse = listOneHead;
	// Declare and initialize variable to store 
	// data of nodes to be inserted
	int nodeValue = 0;
	// Traverse the first Linked List 
	// while current node is not NULL
	while (traverse != NULL)
	{
		// Store the data of current node
		nodeValue = traverse->getData();
		// Set result as the head of merged list, 
		// insert node with nodeValue into it
		insertNodeInSortedOrder(result, nodeValue);
		// Set traverse to next node
		traverse = traverse->getLink();
	}
	// Set traverse to point to second Linked List
	traverse = listTwoHead;
	// Traverse the second Linked List while current node is not NULL
	while (traverse != NULL)
	{
		// Store the data of current node 
		nodeValue = traverse->getData();
		// Set result as the head of merged list,
		// insert node with nodeValue into it
		insertNodeInSortedOrder(result, nodeValue);
		// Set traverse to next node
		traverse = traverse->getLink();
	}
	// Return result pointer
	return result;
}

void deallocateList(NodePtr& head)
{
	// If Linked List is empty
	if (head == NULL)
	{
		// Get out of function
		 return;
	}
	// Declare and initialize pointer to 
	// traverse Linked List to start at head
	NodePtr traverse = head;
	// Declare and initialize pointer to store 
	// node to be deleted 
	NodePtr discard = NULL;
	// Traverse linked list
	while (traverse != NULL)
	{
		// Store current node to be deleted
		discard = traverse;
		// Set traverse to next node
		traverse = traverse->getLink();
		// Delete node store in discard 
		delete discard;
	}
	// Set head to NULL
	head = NULL;
}
