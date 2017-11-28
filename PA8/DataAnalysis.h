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
	// constructors
	DataAnalysis();
	~DataAnalysis();

	// public functions
	void runAnalysis();

private:
	// private data members/streams
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	// private functions
	void openFile();
	bool readLine();
	void readFile();
	void sortTransactions(TransactionNode *&newNode, string &transactionType);
	void displayAnalysis();
};