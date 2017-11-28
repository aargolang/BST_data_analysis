#pragma once

#include <string>
#include <iostream>
#include "Node.h"

using std::string;
using std::cout;
using std::endl;

class TransactionNode : public Node
{
public:
	// constructors
	TransactionNode(string &newData = string(""), int newUnits = 0);
	TransactionNode(TransactionNode &copyNode);
	~TransactionNode();

	// get/setters
	void setUnits(int newUnits);
	int getUnits();

	// public functions
	void printData();

private:
	// private data
	int mUnits;
};