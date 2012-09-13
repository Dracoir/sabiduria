/*
 * LinkedList.h
 *
 *  Created on: Jan 15, 2011
 *      Author: ricardorodriguez
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct Node {
	int value;
	Node *Next;

	Node(int newValue, Node *newNext) {
		value = newValue;
		Next = newNext;
	}
};

namespace Sabiduria {
namespace Structures {

class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();

	// Reverses the nodes in the lined list, by recursively swapping the "next" node
	// pointers of two nodes at a time
	void Reverse();

	// Splits the list into two halves, separating the work of reversing the nodes
	// into two processes
	void AltReverse();

	// Prints the node list
	void PrintList();

	// Adds a node to the list
	void AddToEnd(int value);
private:
	Node * Reverse(Node *head, Node *previous);

	Node * AltReverse(Node *head, Node *previous);

	int   _numberOfNodes;
	Node *_head;

};

}
}

#endif /* LINKEDLIST_H_ */
