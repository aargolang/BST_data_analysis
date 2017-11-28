#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{

}
DataAnalysis::~DataAnalysis()
{
	mTreePurchased.~BST();
	mTreeSold.~BST();
	mCsvStream.close();
}
void DataAnalysis::runAnalysis()
{
	openFile();
	readFile();
	displayAnalysis();
	cout << "stop" << endl;
}
void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
}
bool DataAnalysis::readLine()
{
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
	std::string buffer;
	std::getline(mCsvStream, buffer, '\n'); // discard first line
	while (mCsvStream.eof() == false) {
		readLine();
	}
}
void DataAnalysis::sortTransactions(TransactionNode *&newNode, string &transactionType)
{
	if (transactionType == "Purchased") {
		mTreePurchased.insert(newNode);
	}
	else if (transactionType == "Sold") {
		mTreeSold.insert(newNode);
	}
}
void DataAnalysis::displayAnalysis()
{
	TransactionNode *tempNode = &(mTreeSold.findSmallest());
	cout << "least number of units sold: "<< tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
	tempNode = &(mTreeSold.findLargest());
	cout << "most number of units sold: " << tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
	tempNode = &(mTreeSold.findLargest());
	cout << "least number of units purchased: " << tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
	tempNode = &(mTreeSold.findLargest());
	cout << "most number of units purchased: " << tempNode->getData() << " at " << tempNode->getUnits() << " units." << endl;
}