#pragma once

#include <string>
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();

	void setRoot(TransactionNode *&newRoot);
	Node *&getRoot();

	bool insert(std::string &newDat, int units); // newDat datatype is debatable
	bool insert(TransactionNode *&newNode);
	void inOrderTraversal();
	TransactionNode &findSmallest();
	TransactionNode &findLargest();

private:
	Node *mpRoot;

	void destroyTree(Node *&pRoot);
	bool insert(Node *&pRoot, string &newDat, int units);
	bool insert(Node *&pRoot, TransactionNode *&pMem);
	void inOrderTraversal(Node *&pRoot);

};