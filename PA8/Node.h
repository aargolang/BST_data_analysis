#pragma once

#include <string>

using std::string;

class Node
{
public:
	Node();
	Node(Node &copyNode);
	virtual ~Node();

	void setData(string newDat);
	void setLeft(Node *&newLeftNode);
	void setRight(Node *&newRightNode);
	string &getData();
	Node *&getLeft();
	Node *&getRight();

	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;

};