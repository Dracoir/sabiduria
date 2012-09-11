/*
 * LinkedList.cpp
 *
 *  Created on: Jan 15, 2011
 *      Author: ricardorodriguez
 */

#include "LinkedList.h"
#include <iostream.h>
#include <time.h>

namespace Utilities {
namespace Structures {

LinkedList::LinkedList()
{
	_head = NULL;
	_numberOfNodes = 0;
}

LinkedList::~LinkedList() {
	delete _head;
}

/////////////////////////////////////////////
// Reverse a respective linked list
// @param head - The head of linked list
// @param previous - "Head's" previous node
Node * LinkedList::Reverse(Node *head, Node *previous)
{
	if(head == NULL)
	{
		return previous;
	}

	Node *temp = head->Next;
	head->Next = previous;
	return Reverse(temp, head);
}

/////////////////////////////////////////////
// STILL UNDER CONSTRUCTION
Node * LinkedList::AltReverse(Node *head, Node *previous)
{
	// Get the middle count/subscript for middle of node list
	int middleOfList = _numberOfNodes/2;

	// Declare traversal node pointers
	Node *traverseHead = head, *traverseTail;

	// Get tail pointer to point to last half of the list
	for(int i = 0; i < middleOfList; i++, traverseHead = traverseHead->Next)
	{
		traverseTail = traverseHead;
	}

	// Reset the traversal head pointer to head of the list
	traverseHead = head;

	// Set the last node of this list to point to NULL
	for(int i = 0; i < middleOfList; i++)
	{
		traverseHead = traverseHead->Next;
	}
	traverseHead->Next = NULL;

	// Reverse both lists
	traverseTail = Reverse(traverseTail, NULL);
	traverseHead = Reverse(traverseHead, NULL);

	// Connect both lists
	while(true)
	{
		if(traverseTail->Next == NULL)
		{
			traverseTail->Next = traverseHead;
			break;
		}
		traverseTail = traverseTail->Next;
	}


    return traverseTail;
}

/////////////////////////////////////////////
// Reverse a respective linked list
void LinkedList::Reverse()
{
	if (_head != NULL)
		_head = Reverse(_head, NULL);
}

/////////////////////////////////////////////
void LinkedList::AltReverse()
{
	if (_head != NULL)
		_head = AltReverse(_head, NULL);
}

/////////////////////////////////////////////
void LinkedList::AddToEnd(const int value)
{
	Node *newNode = new Node(value, NULL);

	if (_head == NULL) {
		_head = newNode;
	} else {
		Node *traversalNode = _head;

		while (traversalNode->Next != NULL)
			traversalNode = traversalNode->Next;

		traversalNode->Next = newNode;
	}

	_numberOfNodes++;
}

/////////////////////////////////////////////
void LinkedList::PrintList()
{
	Node *traversalNode = _head;
	while(traversalNode != NULL)
	{
		std::cout << traversalNode->value << " ";
		traversalNode = traversalNode->Next;
	}
	std::cout << std::endl;
}
}
}
