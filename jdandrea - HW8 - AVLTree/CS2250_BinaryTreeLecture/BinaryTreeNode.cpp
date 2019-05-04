#ifndef BINARY_TREE_NODE_CPP
#define BINARY_TREE_NODE_CPP

#include "BinaryTreeNode.h"

////////////////////////////////////////////////////////////////////////////
// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
////////////////////////////////////////////////////////////////////////////
template <class T>
int BinaryTreeNode<T>::nbrNodes = 0;

// GetNbrNodes
// Returns the number of nodes created since the application started
// DO NOT CALL THIS FUNCTION IN YOUR CODE - USED ONLY BY THE TESTING CODE
template <class T>
int BinaryTreeNode<T>::GetNbrNodes()
{
	return nbrNodes;
}

// ResetNbrNodes
// Resets the number of nodes to zero
// DO NOT CALL THIS FUNCTION IN YOUR CODE - USED ONLY BY THE TESTING CODE
template <class T>
void BinaryTreeNode<T>::ResetNbrNodes()
{
	nbrNodes = 0;
}
////////////////////////////////////////////////////////////////////////////
// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
////////////////////////////////////////////////////////////////////////////

// BinaryTreeNode Constructor
// Store the item in the node
// Set it to have no children
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& item)
{
	data = item;
	right = NULL;
	left = NULL;
	height = 0;

	++nbrNodes;
}

// Copy constructor
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T>& node)
{
	data = node.data;
	right = node.right;
	left = node.left;
	height = node.height;

	++nbrNodes;
}

// BinaryTreeNode Destructor
// Delete each child.  This recursively
// calls the destructor "down" the tree
template <class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
	--nbrNodes;
}

// GetLeft
// Returns a pointer to the left child
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeft() const
{
	return left;
}

// GetRight
// REturns a pointer to the right child
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetRight() const
{
	return right;
}

// GetData
// Returns the data associated with the node
template <class T>
T BinaryTreeNode<T>::GetData() const
{
	return data;
}

// GetHeight
// Returns the height of the node
template <class T>
int BinaryTreeNode<T>::GetHeight() const
{
	return height;
}

// SetLeft
// Sets the left child
template <class T>
void BinaryTreeNode<T>::SetLeft(BinaryTreeNode<T>* left)
{
	this->left = left;
}

// SetRight
// Sets the right child
template <class T>
void BinaryTreeNode<T>::SetRight(BinaryTreeNode<T>* right)
{
	this->right = right;
}

// SetData
// Sets the data of the node
template <class T>
void BinaryTreeNode<T>::SetData(const T& data)
{
	this->data = data;
}

// SetHeight
// Sets the height of the node
template <class T>
void BinaryTreeNode<T>::SetHeight(int height)
{
	this->height = height;
}

// Insertion Operator
// displays the node's data
template <class T>
ostream& operator<<(ostream& sout, const BinaryTreeNode<T>& node)
{
	sout << node.GetData();
	return sout;
}

#endif