/**
	Date: 10/26/2023
	By: Justin Su
	Purpose: Problem #1 for Lab #15
**/
#include <iostream>
using namespace std;

// Struct definition for Node
struct Node
{
	int data;
	struct Node* next;
};

// Define sruct Node* be NodePtr
typedef struct Node* NodePtr;

/**
	Purpose: Insert new node with given value into Linked List 
			 with given head as its head while maintaining sorted order.
	Input: - head as NodePtr reference so head can be changed
		   - value as data of node to be inserted in Linked List
	Input Requirement: - Given head should point to the first node 
					     of Linked List
					   - Given value should be an integer
	Result: - New node is created dynamically with data of given 
			  value and inserted into Linked List that starts at 
			  given head at position where the data of the node to 
			  its left is smaller and the data of the node to the 
			  right is larger
			- If Linked List is empty, insert and make new node the head
**/
void insertNodeInSortedOrder(NodePtr& head, int value);

/**
	Purpose: Output the data of the nodes in Linked List that 
			 has head node pointed to by given head.
	Input: - head as pointer of type NodePtr
	Input Requirement: - Given head should point to the first node 
					     of Linked List
	Result: The data of each node in Linked List with 
			head of given head is outputted to terminal
**/
void printList(NodePtr head);

/**
	Purpose: Deallocate all nodes of Linked List with head of given head.
	Input: head as pointer of type NodePtr
	Input Requirement: Given head should point to the first node of Linked List
	Result: All nodes in Linked List are deallocated
**/
void deallocateList(NodePtr& head);


int main()
{
	// Declare and initialize array with 10 elements
	int A[10] = {4,3,6,1,10,9,5,8,7,2};
	// Declare and initialize variable to store arraySize
	int arraySize = sizeof(A) / sizeof(int);
	// Declare and initialize head of the Linked List as NULL
	NodePtr head = NULL;
	// Loop through given A array
	for (int i = 0; i < arraySize; i++)
	{
		// Save the integer at current index of array
		int value = A[i];
		// Insert the value into the Linked List while 
		// maintaining sorted order
		insertNodeInSortedOrder(head, value);
		// Output the linked list
		printList(head);
	}
	deallocateList(head);
	
	return 0;
}

void printList(NodePtr head)
{
	// If Linked list is empty
	if (head == NULL)
	{
		// Get out of function
		return;
	}
	// Loop through Linked list
	for (NodePtr iter = head; iter != NULL; iter = iter->next)
	{
		// Output the data of each node
		cout << iter->data << " ";
	}
	// Output new line to terminal for readability
	cout << endl;
}

void insertNodeInSortedOrder(NodePtr& head, int value)
{
	// Create new node to be inserted
	NodePtr newNode = new Node;
	// Set its data to be given value
	newNode->data = value;
	// Sets its next pointer to NULL
	newNode->next = NULL;
	// If Linked list is empty
	if (head == NULL)
	{
		// Set head as new node
		head = newNode;
		// Get out of function
		return;
	}
	// If the given value is less than the data of head
	if (value <= head->data)
	{
		// Insert node at start of linked list
		// Set next of linked list to be head
		newNode->next = head;
		// Make newNode the head
		head = newNode;
		// Get out of function
		return;
	}
	// Declare and initialize pointer to 
	// traverse linked list to point at head
	NodePtr traverse = head;
	// Declare and initialize pointer to be 
	// one node before head to point at head
	NodePtr prev = head;
	// Find position to insert new node
	// While traverse is not at end of list and 
	// the data of currnet node is less than the given value
	while (traverse != NULL && traverse->data < value)
	{
		// Set prev to point at what traverse pointed to
		prev = traverse;
		// Set traverse to next node
		traverse = traverse->next;
	}
	// Make next of newNode to be traverse
	newNode->next = traverse;
	// Set next of prev to be newNode
	prev->next = newNode;
}

void deallocateList(NodePtr& head)
{
	// If Linked List is already empty
	if (head == NULL)
	{
		// Get out of function
		return;
	}
	// If there is only one node
	if (head->next == NULL) 
	{
		delete head;
		head = NULL;
		return;
	}
	// Declare and initialize pointer to traverse 
	// Linked list to start at head
	NodePtr traverse = head;
	// Declare and initialize pointer to store 
	// node to be deleted as NULL
	NodePtr discard = NULL;
	// Keep looping while not at end of list
	while (traverse != NULL)
	{
		// Store the currentn node
		discard = traverse;
		// Set traverse to next node
		traverse = traverse->next;
		// Deallocate the node stored in discard
		delete discard;
	}
}

 
