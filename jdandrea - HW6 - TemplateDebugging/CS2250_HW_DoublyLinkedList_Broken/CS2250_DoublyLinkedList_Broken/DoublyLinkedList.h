#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedListNode.h"

template <class T>
class DoublyLinkedList;

template <class T>
ostream& operator<<(ostream& sout, const DoublyLinkedList<T>& list);

template <class T>
class DoublyLinkedList
{
public:
	// Constructors & Destructor
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>& list);
	~DoublyLinkedList();

	// Add methods
	void AddFront(T item);
	void AddBack(T item);

	// Remove methods
	T RemoveFront();
	T RemoveBack();
	bool RemoveItem(T item);

	// Facilitator methods
	bool Search(T item) const;
	int  Size() const;
	void PrintFullNodes() const;

	// Operators
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhsList);
	friend ostream& operator<< <> (ostream& sout, const DoublyLinkedList<T>& list);

	// Accessors for TESTING ONLY
	const DoublyLinkedListNode<T>* const GetHead() const;
	const DoublyLinkedListNode<T>* const GetTail() const;
	int GetCount() const;

private:
	DoublyLinkedListNode<T>* SearchNodes(T item) const;

	DoublyLinkedListNode<T>* m_head;   // first node in list
	DoublyLinkedListNode<T>* m_tail;   // last node in list
	int m_count;                    // number of nodes in list
};

#include "DoublyLinkedList.cpp"
#include "DoublyLinkedListNode.cpp"

#endif