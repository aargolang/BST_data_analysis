#include "TransactionNode.h"

TransactionNode::TransactionNode(string &newData, int newUnits): Node(newData){
	mUnits = newUnits;
}
TransactionNode::TransactionNode(TransactionNode & copyNode): Node(copyNode) {
	mUnits = copyNode.mUnits;
}
TransactionNode::~TransactionNode() {
	// destroy something
}

void TransactionNode::setUnits(int newUnits) {
	mUnits = newUnits;
}
int TransactionNode::getUnits() {
	return 0;
}
void TransactionNode::printData() {
	cout << "data is: " << mData << endl;
	cout << "units are: " << mUnits << endl;
}
