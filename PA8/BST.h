#pragma once

#include <string>
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	BST();
	BST(BST &copyBST);
	~BST();

	void setRoot(TransactionNode *&newRoot);
	Node *&getRoot();

	bool insert(std::string &newDat, int units); // newDat datatype is debatable
	void inOrderTraversal();
	TransactionNode &findSmallest();
	TransactionNode &findLargest();

private:
	Node *mpRoot;

	void destroyTree(Node *&pRoot);
	bool insert(Node *&pRoot, string &newDat, int units);
	void inOrderTraversal(Node *&pRoot);

};