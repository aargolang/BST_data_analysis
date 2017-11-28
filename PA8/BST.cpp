#include "BST.h"

BST::BST() {
	mpRoot = nullptr;
}
BST::~BST() {
	destroyTree(this->mpRoot);
}

void BST::setRoot(TransactionNode *&newRoot) {
	mpRoot = newRoot;
}
Node *& BST::getRoot() {
	return mpRoot;
}
bool BST::insert(std::string & newDat, int units) {
	bool success = false;
	success = insert(this->mpRoot, newDat, units);
	return success;
}
bool BST::insert(TransactionNode *&newNode) {
	bool success = false;
	success = insert(this->mpRoot, newNode);
	return success;
}
void BST::inOrderTraversal() {
	// some recursion stuff 
	inOrderTraversal(this->mpRoot);
}
TransactionNode & BST::findSmallest() {
	// TODO: this is messy
	Node *cur = this->getRoot();
	while (cur->getLeft() != nullptr) {
		cur = cur->getLeft();
	}
	
	return *(dynamic_cast<TransactionNode*>(cur));
}
TransactionNode & BST::findLargest() {
	// TODO: this is messy
	Node *cur = this->getRoot();
	while (cur->getRight() != nullptr) {
		cur = cur->getRight();
	}

	return *(dynamic_cast<TransactionNode*>(cur));
}
void BST::destroyTree(Node *&pRoot) {
	// post order deletes
	if (pRoot != nullptr) {
		destroyTree(pRoot->getLeft());
		destroyTree(pRoot->getRight());
		delete pRoot;
	}
}
bool BST::insert(Node *&parent, string & newDat, int units) {
	bool success = false;		

	if (parent == nullptr) {												// base case
		TransactionNode *pMem;
		pMem = new TransactionNode(newDat, units);
		if (pMem != nullptr) {
			parent = pMem;
			return true;
		}
	}
	else if (units > (dynamic_cast<TransactionNode*>(parent))->getUnits()) {	// Right recursion
		success = insert(parent->getRight(), newDat, units);
	}
	else if (units < dynamic_cast<TransactionNode*>(parent)->getUnits()) {	// Left recursion 
		success = insert(parent->getLeft(), newDat, units);
	}
	else { 
		cout << "duplicates not allowed!" << endl; 
	}

	return success;
}
bool BST::insert(Node *&parent, TransactionNode *&pMem) {
	// TODO: todo!
	bool success = false;

	if (parent == nullptr) {												// base 
		if (pMem != nullptr) {
			parent = pMem;
			return true;
		}
	}
	else if (pMem->getUnits() > (dynamic_cast<TransactionNode*>(parent))->getUnits()) {	// Right recursion
		success = insert(parent->getRight(), pMem);
	}
	else if (pMem->getUnits() < dynamic_cast<TransactionNode*>(parent)->getUnits()) {	// Left recursion 
		success = insert(parent->getLeft(), pMem);
	}
	else {
		cout << "duplicates not allowed!" << endl;
	}

	return success;
}
void BST::inOrderTraversal(Node *& pRoot) {
	if (pRoot != nullptr) {
		inOrderTraversal(pRoot->getLeft());
		cout << pRoot->getData() << ", " 
			<< (dynamic_cast<TransactionNode*>(pRoot))->getUnits() << endl;
		inOrderTraversal(pRoot->getRight());
	}
} 