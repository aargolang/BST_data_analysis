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
	TransactionNode(string &newData, int newUnits = 0);
	TransactionNode(TransactionNode &copyNode);
	~TransactionNode();

	void setUnits(int newUnits);
	int getUnits();

	void printData();

private:
	int mUnits;
};