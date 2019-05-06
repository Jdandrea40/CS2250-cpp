#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "BinaryTree.h"

// BinaryTree Constructor
// Initialize the tree to empty
template <class T>
BinaryTree<T>::BinaryTree(bool isAVL)
{
	isAVLTree = isAVL;
	root = NULL;
}

// BinaryTree Destructor
// Deletes the root node.
// Relies on Node's delete method.
template <class T>
BinaryTree<T>::~BinaryTree(void)
{
	// Calls Recursive function 
	// to clear the roots leaves
	MakeEmpty(root);

	// deltes the root
	delete root;
	root = NULL;
}

// MakeEmpty
// Recurses the entire tree,
template <class T>
void BinaryTree<T>::MakeEmpty(BinaryTreeNode<T>* curr)
{
	// checks the current node for data
	if (curr == NULL)
	{
		return;
	}
	// If there is data
	else
	{
		// Recursivly clear the left had side
		if (curr->GetLeft() != NULL)
		{
			MakeEmpty(curr->GetLeft());
			delete curr->GetLeft();
		}
		// Recursively clear the right hand side
		if (curr->GetRight() != NULL)
		{
			MakeEmpty(curr->GetRight());
			delete curr->GetRight();
		}

		// Set the data to NULL
		curr->SetLeft(NULL);
		curr->SetRight(NULL);
	}
}

/////////////////////////////////////////////////////////////////
// Insert Methods
/////////////////////////////////////////////////////////////////

// BinaryTree Insert
// Public Insert adds the item into the tree.
// If the tree is empty, adds the item as the root.
// Otherwise, uses the private insert to recursively insert.
template <class T>
void BinaryTree<T>::Insert(const T& item)
{
	// sets the root to the item
	// if the Tree is empty
	if (root == NULL)
	{
		root = new BinaryTreeNode<T>(item);
	}
	// Or calls recursive function
	// to insert the next item
	else
	{
		Insert(item, root);
	}
	if (isAVLTree)
	{
		FixHeight(root);
		if (NeedsRebalancing(root))
		{
			root = RebalanceNode(root);
			FixHeight(root);
		}
		
	}
}

// Insert
// Insert the item starting at the current node.  If the
// item is less than the current node, the item is added
// to the left subtree.  If the item is greater, it is
// added to the right subtree.  If there is no subtree,
// the node is added as a child of this node.
template <class T>
void BinaryTree<T>::Insert(const T& item, BinaryTreeNode<T>* curr)
{
	// Smaller items get set to left side of tree
	if (item < curr->GetData())
	{
		// if there is no left node
		if (curr->GetLeft() == NULL)
		{
			// set the next node to item
			curr->SetLeft(new BinaryTreeNode<T>(item));
		}
		// Recursively check tree for proper location
		else
		{
			Insert(item, curr->GetLeft());
		}
	}
	// Larger items = right hand side of tree
	else if (item > curr->GetData())
	{
		// If right node is empty -> Set it to item
		if (curr->GetRight() == NULL)
		{
			curr->SetRight(new BinaryTreeNode<T>(item));
		}
		// Recursively check tree for proper location
		else
		{
			Insert(item, curr->GetRight());
		}
	}

}

/////////////////////////////////////////////////////////////////
// Search Methods
/////////////////////////////////////////////////////////////////

// Search
// Public Search method that uses the private version to search
// from the root.  Returns TRUE if the item is found.  Returns 
// FALSE if the tree is empty or if the item is not found.
template <class T>
bool BinaryTree<T>::Search(const T& item) const
{
	// tree is empty
	if (root == NULL)
	{
		return false;
	}
	// recursive search function call
	else
	{
		return Search(item, root);
	}
}

// Search
// Private Search method that examines the current node and
// recursively its children until it finds the item.  If
// the current node has no children and does not match
// the item, then the search is exhausted and the item
// was not found.
// Returns TRUE if the item is found, FALSE if not. 
template <class T>
bool BinaryTree<T>::Search(const T& item, BinaryTreeNode<T>* curr) const
{
	// reached the end of the tree
	if (curr == NULL)
	{
		return false;
	}
	// item is less than current node
	// move left
	if (item < curr->GetData())
	{
		return Search(item, curr->GetLeft());
	}
	// item was greater than current
	// move right
	else if (item > curr->GetData())
	{
		return Search(item, curr->GetRight());
	}
	// item was found
	else if (item == curr->GetData())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/////////////////////////////////////////////////////////////////
// Remove Methods
/////////////////////////////////////////////////////////////////

// Remove
// The public versrion of Remove that initiates the recursive
// search for the item to remove.
// Returns true if the remove was successful, false otherwise.
template <class T>
bool BinaryTree<T>::Remove(const T& item)
{
	// empty tree check
	if (root == NULL)
	{
		return false;
	}
	// root check
	else if (root->GetData() == item)
	{
		root = RemoveNode(root);
		return true;
	}
	// recurse until item is found
	else
	{
		return Remove(item, root);
		return true;
	}
}

// Remove
// The private version of Remove, recursively searches for the item
// to remove. Returns true if the removal was successful, false otherwise.
// Uses RemoveNode to actually remove the node of the item once found and 
// fixes the parent's pointer to the removed node.
template <class T>
bool BinaryTree<T>::Remove(const T& item, BinaryTreeNode<T>* curr)
{
	// checks for actual data in current noce
	if (curr == NULL)
	{
		return false;
	}
	// Checks right node for actual values
	if (curr->GetRight() != NULL)
	{
		// checks the right child and compares to item
		if (curr->GetRight()->GetData() == item)
		{
			// if equal, removes node, and set it to the proper node
			curr->SetRight(RemoveNode(curr->GetRight()));
			return true;
		}
		// else recursively move through tree
		else if (item > curr->GetData())
		{
			return Remove(item, curr->GetRight());
		}
	}
	// checks left child for actual data
	if (curr->GetLeft() != NULL)
	{
		// if the left node is equal to the search item
		if (curr->GetLeft()->GetData() == item)
		{
			// removes the node and sets it to the proper node
			curr->SetLeft(RemoveNode(curr->GetLeft()));
			return true;
		}
		else
		{
			return Remove(item, curr->GetLeft());
		}
	}
	else
	{
		return false;
	}

}

// RemoveNode
// Removes the curr node by determining which node should take its
// place in the revised tree.  Returns the node that should take
// curr's place in the tree with restructured children as appropriate.
// If curr had no children, null is returned.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RemoveNode(BinaryTreeNode<T>* curr)
{
	// If there are no leaves, delete the current node
	if (curr->GetLeft() == NULL && curr->GetRight() == NULL)
	{	
		delete curr;
		return NULL;
	}
	// checks for a single branch off of found node
	else if (curr->GetLeft() == NULL || curr->GetRight() == NULL)
	{
		// If there is no Left Branch
		if (curr->GetLeft() == NULL)
		{
			// bring up the next Right Leaf
			BinaryTreeNode<T>* temp = curr->GetRight();
			delete curr;
			return temp;
		}
		// No Right branch
		else
		{
			// bring up the next left leaf
			BinaryTreeNode<T>* temp = curr->GetLeft();
			delete curr;
			return temp;
		}
	}
	// Two Child branches
	// Get the right value, then iterate to the lowest
	// left value and replace curr with that value
	else if (curr->GetRight() != NULL)
	{
		// Placeholders for tree restructuring
		BinaryTreeNode<T>* minimum = curr;
		BinaryTreeNode<T>* parent = curr;
		BinaryTreeNode<T>* temp = curr;
		temp = temp->GetRight();

		// No left branch, bring up right leaf
		if (temp->GetLeft() == NULL)
		{
			parent = temp;
		}
		minimum = temp;

		// iterate through to find minimum value
		// of left branch
		while (temp->GetLeft() != NULL)
		{	
			parent = minimum;
			minimum = minimum->GetLeft();
			temp = temp->GetLeft();
		}
		// sets curr to minimum value
		curr->SetData(minimum->GetData());

		// iterate through to find minimum right value
		if (minimum->GetRight() != NULL)
		{
			// sets the parent node to the found Min value
			parent->SetLeft(minimum->GetRight());
		}
		else
		{
			// sets to null of no value is in right position
			parent->SetLeft(NULL);
		}

		if (parent == minimum)
		{
			curr->SetRight(minimum->GetRight());
		}

		// removes the minimum valued node
		// and sets to NULL after moving to new
		// location
		minimum->SetLeft(NULL);
		minimum->SetRight(NULL);
		RemoveNode(minimum);
		return curr;
	}
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// AVL METHODS - ADD THESE IN WEEK 2
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// AVL Methods
/////////////////////////////////////////////////////////////////

// NeedsBalancing
// Determines if the curr node needs to be rebalanced by looking
// at its children and grandchildren.  If there is a difference in
// height between the left and right child that is greater than 1,
// the node needs to be rebalanced.  False otherwise.
template <class T>
bool BinaryTree<T>::NeedsRebalancing(BinaryTreeNode<T>* curr)
{
	int leftHeight, rightHeight;

	// sets leftHeight to the height of left branch
	if (curr->GetLeft() != NULL)
	{
		leftHeight = curr->GetLeft()->GetHeight();
	}
	else
	{
		// if null = -1
		leftHeight = -1;
	}
	// sets rightHeight to height of branch
	if (curr->GetRight() != NULL)
	{
		rightHeight = curr->GetRight()->GetHeight();
	}
	else
	{
		// null = -1
		rightHeight = -1;
	}
	// Checks the difference in height of both branches
	if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1)
	{
		// rebalances
		return true;
	}
	// does not need rebalance
	return false;
	
}

// RebalanceNode the current node
// Rebalances the curr node by moving around its children and
// grandchildren as required based on which type of rotation
// is necessary (left-left, right-right, right-left or left-right).
// Returns the new node that should replace curr in the tree.
template <class T>
BinaryTree<T>* BinaryTree<T>::RebalanceNode(BinaryTreeNode<T>* curr)
{
	int leftHeight, leftLeftH, leftRightH;
	int rightHeight, rightLeftH, rightRightH;

	// Checks for a Left Node
	if (curr->GetLeft() != NULL)
	{
		leftHeight = curr->GetLeft()->GetHeight();
		// Checks for a Left Child of Left Node
		if (curr->GetLeft()->GetLeft() != NULL)
		{
			// gets its height
			leftLeftH = curr->GetLeft()->GetLeft()->GetHeight();
		}
		else
		{
			// NO CHILD -> -1
			leftLeftH = -1;
		}
		// Checks for a Right Child of left node
		if (curr->GetLeft()->GetRight() != NULL)
		{
			// sets its height
			leftRightH = curr->GetLeft()->GetRight()->GetHeight();
		}
		else
		{
			// NO CHILD -> -1
			leftRightH = -1;
		}
	}
	// If no left node, all values = -1
	else
	{
		leftHeight = -1;
		leftLeftH = -1;
		leftRightH = -1;
	}

	// Checks for a Left Node
	if (curr->GetRight() != NULL)
	{
		rightHeight = curr->GetRight()->GetHeight();
		// Checks for a Left Child of Left Node
		if (curr->GetRight()->GetLeft() != NULL)
		{
			// gets its height
			rightLeftH = curr->GetRight()->GetLeft()->GetHeight();
		}
		else
		{
			// NO CHILD -> -1
			rightLeftH = -1;
		}
		// Checks for a Right Child of left node
		if (curr->GetRight()->GetRight() != NULL)
		{
			// sets its height
			rightRightH = curr->GetRight()->GetRight()->GetHeight();
		}
		else
		{
			// NO CHILD -> -1
			rightRightH = -1;
		}
	}
	// If no left node, all values = -1
	else
	{
		rightHeight = -1;
		rightLeftH = -1;
		rightRightH = -1;
	}
	// LEFT - LEFT


	// LEFT - RIGHT

	// RIGHT - RIGHT

	// RIGHT - LEFT
	return NULL;
}
// Used for left rotations
template <class T>
BinaryTree<T>* BinaryTree<T>::RotateLeft(BinaryTreeNode<T>* curr)
{
	// Gets the left and right children of the current node
	BinaryTreeNode<T>* rightChild = curr->GetRight();
	BinaryTreeNode<T>* leftChild = curr->GetLeft();

	// sets curr to the new left subtree of the right child
	rightChild->SetLeft(curr);
	// sets curr new right subtree to the original left subtree
	curr->SetRight(rightChild);
	
	// Fixes the heights after rotation
	FixHeight(curr);
	FixHeight(rightRightC);

	// returns the new node
	return rightChild;
}

// Method for right rotations
template <class T>
BinaryTree<T>* BinaryTree<T>::RotateRight(BinaryTreeNode<T>* curr)
{
	// gets the left and right children of curr
	BinaryTreeNode<T>* leftChild = curr->GetLeft();
	BinaryTreeNode<T>* rightChild = curr->GetRight();

	// sets curr to the new left subtree
	leftChild->SetLeft(curr);
	// sets currs new right subtree
	curr->SetRight(rightChild);

	// fixes the heights after rotation
	FixHeight(curr);
	FixHeight(leftLeftC);
	
	// returns the new node after rotation
	return leftChild;
}

// FixHeight
// Fixes the height of curr by looking at the height of its
// chilren and taking the larger height and adding one.
template <class T>
void BinaryTree<T>::FixHeight(BinaryTreeNode<T>* curr)
{
	// height of the left and right nodes
	int leftHeight;
	int rightHeight;

	// checks if there is an existing left child
	if (curr->GetLeft() != NULL)
	{
		// if true, gets it height
		leftHeight = curr->GetLeft()->GetHeight();
	}
	else
	{
		// no child = height is -1
		// that way when node is added,  the height will be 0
		leftHeight() = -1;
	}
	// checks if there is a right child
	if (curr->GetRight() != NULL)
	{
		// gets the height if true
		rightHeight = curr->GetRight()->GetHeight();
	}
	else
	{
		// no child -> height is -1
		rightHeight = -1;
	}

	// checks whether the heights of left is greater than right
	if (leftHeight > rightHeight)
	{
		// if true, adds 1 to lefts height
		curr->SetHeight(leftHeight + 1);
	}
	else
	{
		// else adds 1 to right height
		curr->SetHeight(rightHeight + 1);
	}
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// DO NOT CHANGE ANYTHING BELOW THIS LINE
// ALL METHODS BELOW THIS LINE ARE FINE AND SHOULD WORK WITH
// YOUR CODE.  YOU DO NOT NEED TO CHANGE ANYTHING FROM HERE TO
// THE BOTTOM OF THE FILE.
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

// IsAVL
// Returns true if the tree is an AVL tree and false otherwise
template <class T>
bool BinaryTree<T>::IsAVL() const
{
	return isAVLTree;
}

/////////////////////////////////////////////////////////////////
// Print Methods
/////////////////////////////////////////////////////////////////

// InOrderPrint
// Public version of InOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::InOrderPrint(ostream& sout) const
{
	InOrderPrint(sout, root);
}

// PreOrderPrint
// Public version of PreOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::PreOrderPrint(ostream& sout) const
{
	PreOrderPrint(sout, root);
}

// PostOrderPrint
// Public version of PostOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::PostOrderPrint(ostream& sout) const
{
	PostOrderPrint(sout, root);
}

// InOrderPrint
// Prints the tree in order (left child, current
// node, right child).
template <class T>
void BinaryTree<T>::InOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}
	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		InOrderPrint(sout, curr->GetLeft());
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		InOrderPrint(sout, curr->GetRight());
	}
}

// PreOrderPrint
// Prints the tree in pre-order (current node, left child,
// right child).
template <class T>
void BinaryTree<T>::PreOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		PreOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		PreOrderPrint(sout, curr->GetRight());
	}
}

// PostOrderPrint
// Prints the tree "post-order".  Prints
// the left subtree, prints the right subree, then the current node.
template <class T>
void BinaryTree<T>::PostOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		PostOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		PostOrderPrint(sout, curr->GetRight());
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";
}

/////////////////////////////////////////////////////////////////
// Operators
/////////////////////////////////////////////////////////////////

// Insertion Operator
// Display the tree using an in-order print
template <class T>
ostream& operator<<(ostream& sout, const BinaryTree<T>& tree)
{
	sout << "PreOrderPrint:   ";
	tree.PreOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "InOrderPrint:    ";
	tree.InOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "PostOrderPrint:  ";
	tree.PostOrderPrint(sout, tree.root);
	sout << "\n";
	return sout;
}

#endif
