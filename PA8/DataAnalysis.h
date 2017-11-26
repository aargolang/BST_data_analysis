#pragma once

#include <iostream>
#include <fstream>
#include "BST.h"

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
	void readLine();
	void readFile();
	void sortTransactions();
	void displayAnalysis();
};