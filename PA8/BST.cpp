#include "BST.h"

BST::BST() {

}
BST::BST(BST & copyBST) {

}
BST::~BST() {

}

void BST::setRoot(TransactionNode *&newRoot) {
	mpRoot = newRoot;
}
Node *& BST::getRoot() {
	return mpRoot;
}
bool BST::insert(std::string & newDat) {
	bool success = false;
	success = insert(this->mpRoot, newDat);
	return success;
}
void BST::inOrderTraversal() {
	// some recursion stuff here 
}
TransactionNode & BST::findSmallest() {
	// TODO: fix this
	TransactionNode n(string("The smallest node"),0);
	return n;
}
TransactionNode & BST::findLargest() {
	// TODO: fix this
	TransactionNode n(string("The largest node"), 0);
	return n;
}
bool BST::destroyTree() {
	return false;
}
bool BST::insert(Node *& pRoot, string & newDat) {
	return false;
}
void BST::inOrderTraversal(Node *& pRoot) {

}