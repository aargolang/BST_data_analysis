#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	// no default values needed
}
DataAnalysis::~DataAnalysis()
{
	mCsvStream.close();
}
void DataAnalysis::runAnalysis()
{
	openFile();
	readFile();
	displayAnalysis();
}
void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
}
bool DataAnalysis::readLine()
{
	// reads the lines of the file into the trees
	std::string buffer;
	bool success = false;
	if (std::getline(mCsvStream, buffer, ',')) 
	{
		TransactionNode *bufferNode = new TransactionNode();
		bufferNode->setUnits(atoi(buffer.c_str()));
		std::getline(mCsvStream, buffer, ',');
		bufferNode->setData(buffer);
		std::getline(mCsvStream, buffer, '\n');
		sortTransactions(bufferNode, buffer);
		success = true;
	}
	return success;
}
void DataAnalysis::readFile()				
{
	// discard the first line and calls readLine till the stream reaches the end of the file
	std::string buffer;
	std::getline(mCsvStream, buffer, '\n');
	while (mCsvStream.eof() == false) {		
		readLine();
	}
}
void DataAnalysis::sortTransactions(TransactionNode *&newNode, string &transactionType)
{
	// puts the node into the correct tree based on the type of transaction
	if (transactionType == "Purchased") {
		mTreePurchased.insert(newNode);
	}
	else if (transactionType == "Sold") {
		mTreeSold.insert(newNode);
	}
}
void DataAnalysis::displayAnalysis()
{
	// displays the largest and smallest values of each tree
	TransactionNode *tempNode = &(mTreeSold.findSmallest());
	cout << "least number of units sold: "<< tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
	tempNode = &(mTreeSold.findLargest());
	cout << "most number of units sold: " << tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
	tempNode = &(mTreePurchased.findLargest());
	cout << "least number of units purchased: " << tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
	tempNode = &(mTreePurchased.findSmallest());
	cout << "most number of units purchased: " << tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
}