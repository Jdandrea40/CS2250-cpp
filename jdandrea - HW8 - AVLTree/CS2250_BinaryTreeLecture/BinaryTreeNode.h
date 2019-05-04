#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class BinaryTreeNode;

template <class T>
ostream& operator<< (ostream& sout, const BinaryTreeNode<T>& node);

template <class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode(const T& item);
	BinaryTreeNode(const BinaryTreeNode<T>& node);
	~BinaryTreeNode();

	BinaryTreeNode<T>* GetLeft() const;
	BinaryTreeNode<T>* GetRight() const;
	T GetData() const;
	int GetHeight() const;

	// Mutators
	void SetLeft(BinaryTreeNode<T>* left);
	void SetRight(BinaryTreeNode<T>* right);
	void SetData(const T& data);
	void SetHeight(int height);

	friend ostream& operator<< <> (ostream& sout, const BinaryTreeNode<T>& node);

	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
	static int GetNbrNodes();
	static void ResetNbrNodes();
	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
private:

	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	T data;
	int height;

	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
	static int nbrNodes;
	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
};

#include "BinaryTreeNode.cpp"

#endif