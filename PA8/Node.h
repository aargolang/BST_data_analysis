#pragma once

#include <string>

using std::string;

class Node
{
public:
	// constructos and virtual destructor
	Node(string &newData);
	Node(Node &copyNode);
	virtual ~Node();

	// public functions
	void setData(string newDat);
	void setLeft(Node *&newLeftNode);
	void setRight(Node *&newRightNode);
	string &getData();
	Node *&getLeft();
	Node *&getRight();

	// pure virtual functions
	virtual void printData() = 0;

protected:
	// private data members
	string mData;
	Node *mpLeft;
	Node *mpRight;
};