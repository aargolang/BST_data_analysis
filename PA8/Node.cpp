#include "Node.h"

Node::Node(string &newData){
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}
Node::Node(Node &copyNode) {
	// shallow copy
	mData = copyNode.mData;
	mpLeft = copyNode.mpLeft;
	mpRight = copyNode.mpRight;
}
Node::~Node() {
	// maybe destructor 
}

void Node::setData(string newDat) {
	mData = newDat;
}
void Node::setLeft(Node *& newLeftNode) {
	mpLeft = newLeftNode;
}
void Node::setRight(Node *& newRightNode) {
	mpRight = newRightNode;
}
string & Node::getData() {
	return mData;
}
Node *& Node::getLeft() {
	return mpLeft;
}
Node *& Node::getRight() {
	return mpRight;
}

