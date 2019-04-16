#ifndef DOUBLY_LINKED_LIST_NODE_CPP
#define DOUBLY_LINKED_LIST_NODE_CPP
#include "DoublyLinkedList.h"

// Static member for TESTING ONLY
template <class T>
int DoublyLinkedListNode<T>::nbrOfNodes = 0;

template <class T>
int DoublyLinkedListNode<T>::GetNbrOfNodes()
{
	return nbrOfNodes;
}

// Constructors
// Default constructor
// Initializes next and previous pointers to NULL
// Initializes data to a "safe" value of 0
template <class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(void)
{
	m_data = 0;
	m_next = NULL;
	m_prev = NULL;

	++nbrOfNodes;
}

// Copy Constructor
// Copies an existing node exactly by copying each data member
template <class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(const DoublyLinkedListNode<T>& node)
{
	m_data = node.m_data;
	m_next = node.m_next;
	m_prev = node.m_prev;

	++nbrOfNodes;
}

// Constructor
// Accepts the data to store in the node as the parameter
// Initializes previous and next pointers to NULL
template <class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(T data)
{
	m_data = data;
	m_next = NULL;
	m_prev = NULL;

	++nbrOfNodes;
}

// Constructor
// Accepts data, prev, and next pointers as parameters
template <class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(T data, DoublyLinkedListNode<T>* prev, DoublyLinkedListNode<T>* next)
{
	m_data = data;
	m_next = next;
	m_prev = prev;

	++nbrOfNodes;
}

// Destructor
template <class T>
DoublyLinkedListNode<T>::~DoublyLinkedListNode(void)
{
	m_next = NULL;
	m_prev = NULL;

	--nbrOfNodes;
}

// Accessors
// GetData - returns the data stored in the node
template <class T>
T DoublyLinkedListNode<T>::GetData() const
{
	return m_data;
}

// GetNext - returns the pointer to the next node
template <class T>
DoublyLinkedListNode<T>* DoublyLinkedListNode<T>::GetNext() const
{
	return m_next;
}

// GetPrev - returns the pointer to the prevous node
template <class T>
DoublyLinkedListNode<T>* DoublyLinkedListNode<T>::GetPrev() const
{
	return m_prev;
}

// Mutators
// SetData - sets the data to store in the node
template <class T>
void DoublyLinkedListNode<T>::SetData(T data)
{
	m_data = data;
}

// SetNext - sets the pointer to the next node
template <class T>
void DoublyLinkedListNode<T>::SetNext(DoublyLinkedListNode<T>* next)
{
	m_next = next;
}

// SetPrev - sets the pointer to the previous node
template <class T>
void DoublyLinkedListNode<T>::SetPrev(DoublyLinkedListNode<T>* prev)
{
	m_prev = prev;
}

// operator<< - displays the node
template <class T>
ostream& operator<<(ostream& sout, const DoublyLinkedListNode<T>& curr)
{
	sout << "[ (data) " << curr.m_data << " : (prev) " << curr.m_prev << " : (next) " << curr.m_next << " ]";
	return sout;
}

template <class T>
DoublyLinkedListNode<T>& DoublyLinkedListNode<T>::operator=(const DoublyLinkedListNode<T>& rhsNode)
{
	if (this != &rhsNode)
	{
		m_data = rhsNode.m_data;
		m_next = rhsNode.m_next;
		m_prev = rhsNode.m_prev;
	}
	return *this;
}
#endif // !DOUBLY_LINKED_LIST_NODE_CPP

