#pragma once

#include <iostream>
#include <fstream>
#include "BST.h"
#include "Node.h"
#include "TransactionNode.h"

using std::cout;
using std::endl;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	void openFile();
	bool readLine();
	void readFile();
	void sortTransactions(TransactionNode *&newNode, string &transactionType);
	void displayAnalysis();
};