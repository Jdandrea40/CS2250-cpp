#include <iostream>
#include <string>

using namespace std;

#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H

#define NULL 0
template <class T>
class DoublyLinkedListNode;

template <class T>
ostream& operator<< (ostream& sout, const DoublyLinkedListNode<T>& list);

template <class T>
class DoublyLinkedListNode
{
public:
	// Constructors
	DoublyLinkedListNode(void);       // Default
	DoublyLinkedListNode(const DoublyLinkedListNode<T>& node);    // Copy
	DoublyLinkedListNode(T data);
	DoublyLinkedListNode(T data, DoublyLinkedListNode<T>* prev, DoublyLinkedListNode<T>* next);

	// Destructor
	~DoublyLinkedListNode(void);

	// Accessors/Inspectors
	T GetData() const;
	DoublyLinkedListNode<T>* GetNext() const;
	DoublyLinkedListNode<T>* GetPrev() const;

	// Mutators/Manipulators
	void SetData(T data);
	void SetNext(DoublyLinkedListNode<T>* next);
	void SetPrev(DoublyLinkedListNode<T>* prev);

	DoublyLinkedListNode<T>& operator=(const DoublyLinkedListNode<T>& list);
	friend ostream& operator<< <> (ostream& sout, const DoublyLinkedListNode<T>& list);

	static int GetNbrOfNodes();

private:
	T m_data;						 // node's item
	DoublyLinkedListNode<T>* m_next; // next in list
	DoublyLinkedListNode<T>* m_prev;

	// Static members for TESTING ONLY
	static int nbrOfNodes;
};

#include "DoublyLinkedListNode.cpp"

#endif