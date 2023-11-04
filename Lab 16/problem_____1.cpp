/**
	Date: 10/31/2023
	By: Justin Su
	Purpose: Problem #1 for Lab #16
**/
#include <iostream>
using namespace std;

// Node for Linked List
struct Node
{
	// Data with type of integer
	int data;
	// Pointer to another Node
	struct Node* next;
};

// Redefine struct Node* to NodePtr 
typedef struct Node* NodePtr;

/**
	Purpose: Output data of nodes in Linked List.
	Input: head as NodePtr pointer to first
		   node of Linked List
	Input Requirement: Given head pointer
					   should point to first node
	Result: The data of the nodes of the Linked List
			are outputted to terminal.
**/
void printList(NodePtr head);

/**
	Purpose: Insert new dynamically allocated Node variable 
			 with given newValue at start of Linked List.
	Input: head as NodePtr pointer to first
			node of Linked list
	Input Requirement: - Given head pointer points to
					     first node in Linked List or NULL
					   - Given newValue should be an integer
	Result: - Insert new node with given newValue into
			  front of Linked List.
			- Set head to point to this newNode.
**/
void insertNewNodeAtHead(NodePtr& head, int newValue);

/**
	Purpose: Return whether or not a node with given
			 targetData exists in Linked List.
	Input: - head as NodePtr pointer to first node of Linked List
		   - targetData as data of Node to search
	Input Requirement: - Given head points to the first node
					     of Linked List or is NULL
					   - Given targetData is an integer
	Result: - Returns true if a node with given targetData
			  exists in Linked List.
			- Returns false otherwise.
**/
bool targetDataExistsInLinkedList(NodePtr head, int targetData);

/**
	Purpose: Deletes dynamically allocated node with 
			given data targetData from Linked List.
	Input: -head as NodePtr pointer to first node of Linked List
		   -targetData as data of Node to delete
	Input Requirement: - Given head points to the first
					    node of Linked List or is NULL
					   - Given targetData is an integer
	Result: - Node in Linked List with data of given
			  targetData is deleted.
			- Necessary pointers are adjusted after node is deleted.
			- If head is the node to be deleted then delete it
			  and set to NULL
**/
void deleteNodeWithTargetData(NodePtr& head, int targetData);

/**
	Purpose: Deallocate the dynamically allocated 
			 nodes of Linked List.
	Input: head NodePtr reference
	Input Requirement: Given head should point to
					   first node of Linked List or NULL
	Result: Nodes of Linked List are deallocated.
			Given head is set to NULL.
**/
void deallocateList(NodePtr& head);

int main()
{
	// Declare and initialize array with 10 elements
	int A[10] = { 4,3,6,1,10,9,5,8,7,2 };
	// Declare and initialize size of array
	int arraySize = sizeof(A) / sizeof(int);
	// Declare and initialize head of Linked List to NULL
	NodePtr head = NULL;
	// Loop through all elements of Linked List
	for (int i = 0; i < arraySize; i++)
	{
		// Declare and initialize variable 
		// to store current element of array
		int data = A[i];
		// Insert data into front of Linked List
		insertNewNodeAtHead(head, data);
	}
	// Output elements in Linked List
	cout << "< Original Linked List >" << endl;
	printList(head);
	// Output newline to terminal for readability
	cout << endl;
	// Declare and initialize variable to store user input
	char userInput = ' ';
	// Do loop to run program before asking 
	// user if they want to proceed
	do
	{
		// Declare and initialize variable to store integer 
		// to delete from Linked List from user
		int targetData = 0;
		// Prompt user for the integer to delete
		cout << "Enter data to delete : ";
		// Store user input
		cin >> targetData;
		
		// If node with given targetData exists in Linked list
		if (targetDataExistsInLinkedList(head, targetData))
		{
			// Delete it
			deleteNodeWithTargetData(head, targetData);
			// Output to user the integer just deleted
			cout << "< After deleting " << targetData
				<< " >" << endl;
		}
		// If node with given targetData does not exist in Linked List
		else
		{
			// Notify 
			cout << targetData << " does not exist in Linked List" << endl;
		}
		// Output Linked List
		printList(head);
		// If Linked List becomes empty
		if (head == NULL)
		{
			// Get out of loop
			break;
		}
		// Output newline to terminal for readability
		cout << endl;
		// Prompt user if they want to run program again
		cout << "More (y/n)? ";
		// Get user input
		cin >> userInput;
		// Keep looping while user input is not N or n
	} while (userInput != 'N' && userInput != 'n');
	// Call function to deallocae all nodes in Linked List
	deallocateList(head);

	return 0;
}

void printList(NodePtr head)
{
	// If Linked List is empty
	if (head == NULL)
	{
		// Notify
		cout << "Linked List is empty" << endl;
		// Get out of function
		return;
	}
	// Loop through Linked List
	for (NodePtr iter = head; iter != NULL; iter = iter->next)
	{
		// Output data at current node with space after
		cout << iter->data << " ";
	}
	// Output newline to terminal
	cout << endl;
}

void insertNewNodeAtHead(NodePtr& head, int newValue)
{
	// Create new node
	NodePtr newNode = new Node;
	// Set newNode data to given newValue
	newNode->data = newValue;
	// Set newNode next to be NULL
	newNode->next = NULL;
	// If Linked List is empty
	if (head == NULL)
	{
		// Make newNode the head
		head = newNode;
		// Get out ouf function
		return;
	}
	// Make newNode point to head
	newNode->next = head;
	// Set newNode as current head
	head = newNode;
}

bool targetDataExistsInLinkedList(NodePtr head, int targetData)
{
	// Loop through nodes of Linked List
	for (NodePtr iter = head; iter != NULL; iter = iter->next)
	{
		// If the data at current node is equal to given targetData
		if (iter->data == targetData)
		{
			// Return true
			return true;
		}
	}
	// Otherwise return false
	return false;
}

void deleteNodeWithTargetData(NodePtr& head, int targetData)
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
		// Delete head
		delete head;
		// Set head to NULL
		head = NULL;
		// Get out of function
		return;
	}
	// If head has data of given targetData
	if (head->data == targetData)
	{
		// Store head to be deleted
		NodePtr discard = head;
		// Set head to be next node
		head = head->next;
		// delete head
		delete discard;
		// Get out of function
		return;
	}
	// Declare and initialize pointer to traverse linked list
	NodePtr traverse = head;
	// Declare and initialize pointer that will point to the node before traverse
	NodePtr prev = head;
	// While travese is not at last node
	while (traverse->next != NULL)
	{
		// If the current node has data of given targetData
		if (traverse->data == targetData)
		{
			// Grt out of loop
			break;
		}
		// Save current node to prev
		prev = traverse;
		// Go to next node
		traverse = traverse->next;
	}
	// Save current node to be deleted
	NodePtr discard = traverse;
	// Set the next node of last node to the node affter node to be deleted
	prev->next = traverse->next;
	// Delete node
	delete discard;
}

void deallocateList(NodePtr& head)
{
	// If Linked list is empty
	if (head == NULL)
	{
		// Get out of function
		return;
	}
	// If head is the only node
	if (head->next == NULL)
	{
		// Delete head
		delete head;
		// Set head to NULL
		head = NULL;
		// Get out of function
		return;
	}
	// Declare and initialize pointer that will traverse Linked List
	NodePtr traverse = head;
	// Declare and initialize pointer that will hold the node to be deleted
	NodePtr discard = NULL;
	// Traverse the Linked List
	while (traverse != NULL)
	{
		// Save currnent node to be deleted
		discard = traverse;
		// Go to next node
		traverse = traverse->next;
		// Delete node
		delete discard;
	}
	// Set head to NULL
	head = NULL;
}


