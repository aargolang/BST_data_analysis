#include "BST.h"

BST::BST() 
{
	mpRoot = nullptr;
}
BST::~BST() 
{
	destroyTree(this->mpRoot);
}
void BST::setRoot(TransactionNode *&newRoot)
{
	mpRoot = newRoot;
}
Node *&BST::getRoot() 
{
	return mpRoot;
}
bool BST::insert(TransactionNode *&newNode) 
{
	bool success = false;
	success = insert(this->mpRoot, newNode);
	return success;
}
void BST::inOrderTraversal() 
{
	// public function to pass the root into private function
	inOrderTraversal(this->mpRoot);
}
TransactionNode & BST::findSmallest() 
{
	// gets the left node until we are at the leftmost node
	Node *cur = this->getRoot();
	while (cur->getLeft() != nullptr) {
		cur = cur->getLeft();
	}
	
	return *(dynamic_cast<TransactionNode*>(cur));
}
TransactionNode & BST::findLargest() 
{
	// gets the right node until we are at the rightmost node
	Node *cur = this->getRoot();
	while (cur->getRight() != nullptr) {
		cur = cur->getRight();
	}

	return *(dynamic_cast<TransactionNode*>(cur));
}
void BST::destroyTree(Node *&pRoot) 
{
	// post order deletes "left right delete"
	if (pRoot != nullptr) {
		destroyTree(pRoot->getLeft());
		destroyTree(pRoot->getRight());
		delete pRoot;
	}
}
bool BST::insert(Node *&parent, TransactionNode *&pMem) 
{
	// inserts TransactionNode into the BST
	bool success = false;

	if (parent == nullptr) {	
		// base case
		if (pMem != nullptr) {
			parent = pMem;
			return true;
		}
	}
	else if (pMem->getUnits() > (dynamic_cast<TransactionNode*>(parent))->getUnits()) {	
		// Right recursion
		success = insert(parent->getRight(), pMem);
	}
	else if (pMem->getUnits() < dynamic_cast<TransactionNode*>(parent)->getUnits()) {
		// left recursion
		success = insert(parent->getLeft(), pMem);
	}
	else {
		cout << "duplicates not allowed!" << endl;
	}

	return success;
}
void BST::inOrderTraversal(Node *& pRoot) 
{
	// traverses the tree from smallest to largest "left process right"
	if (pRoot != nullptr) {
		inOrderTraversal(pRoot->getLeft());
		cout << pRoot->getData() << ", " 
			<< (dynamic_cast<TransactionNode*>(pRoot))->getUnits() << endl;
		inOrderTraversal(pRoot->getRight());
	}
} 