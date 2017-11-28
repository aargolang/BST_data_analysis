#include "TransactionNode.h"

TransactionNode::TransactionNode(string &newData, int newUnits): Node(newData)
{
	// passes the data into the Node() constructor
	mUnits = newUnits;
}
TransactionNode::TransactionNode(TransactionNode & copyNode): Node(copyNode) 
{
	// passes the copyNode into the Node() copy constructor
	mUnits = copyNode.mUnits;
}
TransactionNode::~TransactionNode() 
{
	// nothing needed
}

void TransactionNode::setUnits(int newUnits) 
{
	mUnits = newUnits;
}
int TransactionNode::getUnits() 
{
	return mUnits;
}
void TransactionNode::printData() 
{
	cout << "data is: " << mData << endl;
	cout << "units are: " << mUnits << endl;
}
