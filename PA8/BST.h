#pragma once

#include <string>
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	// constructors
	BST();
	~BST();

	// set/getters
	void setRoot(TransactionNode *&newRoot);
	Node *&getRoot();

	// public functions
	bool insert(TransactionNode *&newNode);
	void inOrderTraversal();
	TransactionNode &findSmallest();
	TransactionNode &findLargest();

private:
	// private data members
	Node *mpRoot;

	// private functions
	void destroyTree(Node *&pRoot);
	bool insert(Node *&pRoot, TransactionNode *&pMem);
	void inOrderTraversal(Node *&pRoot);
};