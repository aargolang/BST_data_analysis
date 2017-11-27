#include "TransactionNode.h"

TransactionNode::TransactionNode(string &newData, int newUnits): Node(newData){
	mUnits = newUnits;
}
TransactionNode::TransactionNode(TransactionNode & copyNode): Node(copyNode) {
	mUnits = copyNode.mUnits;
}
TransactionNode::~TransactionNode() {
	cout << "in transaction node destructor" << endl;
	// destroy something
}

void TransactionNode::setUnits(int newUnits) {
	mUnits = newUnits;
}
int TransactionNode::getUnits() {
	return mUnits;
}
void TransactionNode::printData() {
	cout << "data is: " << mData << endl;
	cout << "units are: " << mUnits << endl;
}
