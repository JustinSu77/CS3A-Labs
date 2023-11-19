/**
	Date: 10/31/2023
	By: Justin Su
	Purpose: main.cpp for Problem #2 of Lab #16
**/
#include <fstream>
#include <string>
#include <iomanip>
#include "Student.h"
using namespace std;

// Node of Linked List
struct Node
{
	// data of Student object
	Student data;
	// Pointer to another struct Node
	struct Node* next;
};

// Redefine struct Node* as NodePtr
typedef struct Node* NodePtr;

/**
	Purpose: Insert new dynamically allocated Node object 
			 into Linked List in sorted asecending 
			 order of Student id.
	Input: - head as NodePtr pointer to first node of Linked List
		   - obj as object of Student class
	Input Requirement: - head as NodePtr pointer to first node of 
					     Linked List
					   - obj as object of Student class
	Result: Insert node into Linked List maintaining
			sorted order based on id of Student object
**/
void insertNodeInSortedOrderById(NodePtr& head, Student obj);

/**
	Purpose: Output data of nodes in Linked List.
	Input: head as NodePtr pointer to first node of Linked List
	Input Requirement: Given head points to first node in Linked List
	Result: Output the data of each node in Linked List 
			with space in between
**/
void printList(NodePtr head);

/**
	Purpose: Deallocate each dynamically allocated 
			 node in Linked List.
	Input: head as NodePtr reference
	Input Requirement: Given head points to first node if Linked List
**/
void deallocateList(NodePtr& head);

int main()
{
	// Declare and initialize variable to store fileName
	string fileName = "";
	// Prompt user for fileName
	cout << "Enter filename : ";
	// Get user input and save to fileName variable
	getline(cin, fileName);
	// Declare and initialize pointer to first node of Linked List
	NodePtr head = NULL;
	// Declare ifstream object
	ifstream inputFile;
	// Open file with fileName
	inputFile.open(fileName);
	// File failed to open
	if (inputFile.fail())
	{
		// Output new line to terminal for readability
		cout << endl;
		// Notify user that file failed to open
		cout << "Failed to open file " << fileName << endl;
		// Exit program with error code 1
		exit(1);
	}
	// Declare and initialize variable to 
	// store id of student object
	int id = 0;
	// Declare and initialize variable to 
	// store name of student object
	string name = "";
	// Declare and initialize variable to 
	// store score of student object
	int score = 0;
	// Read opened file until the end
	while (!inputFile.eof())
	{
		// Read in and store data into id, name, and score
		inputFile >> id >> name >> score;
		// Create Student object with saved id, name, and score
		Student student(id, name, score);
		// Insert into Linked List while maintaining order
		insertNodeInSortedOrderById(head, student);
	}
	// Output newline to terminal for readability
	cout << endl;
	// Output id, name , and score of each node in Linked List neatly 
	cout << "  ID      Name   Score" << endl;
	cout << "------------------------" << endl;
	printList(head);
	// Deallocate nodes of Linked List
	deallocateList(head);

	return 0;
}

void insertNodeInSortedOrderById(NodePtr& head, Student obj)
{
	// Declare and initialize dynamic memory for new node
	NodePtr newNode = new Node;
	// Set the data of new Node to be given Student object
	newNode->data = obj;
	// Set next pointer of new Node to point to NULl at first
	newNode->next = NULL;
	// If Linked List is empty
	if (!head)
	{
		// Make new Node the head
		head = newNode;
		// Get out of function
		return;
	}
	// If id of given Student object is less than 
	// or equal to the id of Student object of head node
	if (obj.getId() <= head->data.getId())
	{
		// Insert new node at head
		// Set new Node next pointer to be head
		newNode->next = head;
		// Set head to be the new Node
		head = newNode;
		// Get out of function
		return;
	}
	// Declare and initialize  pointer to start at head
	NodePtr traverse = head;
	// Declare and initialize pointer to also start at head
	NodePtr prev = head;
	// Keep traversing Linked List if node is not NULL and 
	// the current node has Student object with id of less than id of given Student object
	while (traverse != NULL && traverse->data.getId() <= obj.getId())
	{
		// Make prev point to what traverse was pointing to
		prev = traverse;
		// Move traverse to next node
		traverse = traverse->next;
	}
	// Insert newnode in between two nodes
	// Set next pointer to be new Node
	prev->next = newNode;
	// Set next pointer to be node pointed to by traverse
	newNode->next = traverse;
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
	// Loop through Linked List
	for (NodePtr iter = head; iter != NULL; iter = iter->next)
	{
		// Output the id, name, and score of the current node neatly to terminal
		cout << iter->data.getId() << "  " << setw(8)
			<< iter->data.getName() << "   " << iter->data.getScore() << endl;
	}
}
void deallocateList(NodePtr& head)
{
	// If Linked List is empty
	if (head == NULL)
	{
		// Get out of function
		return;
	}
	// If head is the only node
	if (head->next == NULL)
	{
		// Deallocate head
		delete head;
		// Set head to NULL
		head = NULL;
		// Get out of function
		return;
	}
	// Declare and initialize variable 
	// to start at head
	NodePtr traverse = head;
	// Declare and initialize variable to 
	// point to node that will be deleted
	NodePtr discard = NULL;
	// Traversing Linked List 
	while (traverse != NULL)
	{
		// Save current node to be deleted
		discard = traverse;
		// Go to next node
		traverse = traverse->next;
		// Deallocate node to be deleted
		delete discard;
	}
	// Set head to NULL
	head = NULL;
}
