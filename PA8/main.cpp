#include <iostream>
#include <string>
#include "BST.h"
//#include "DataAnalysis.h"
#include "Node.h"
#include "TransactionNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void tests()
{
	TransactionNode n1(string("iPhone6s"), 9000);
	TransactionNode n2(string("XboxOne"), 3000); 
	TransactionNode n3(string("Galaxys6"), 6000); 
	TransactionNode n4(string("WiiU"), 2000);
	TransactionNode n5(string("Playstation4"), 13000);
	TransactionNode n6(string("SurfacePro4"), 19000);
	TransactionNode n7(string("iPadAir2"), 12000);
	Node *temp;
	temp = &n1;

	BST *testTree = new BST();
	testTree->insert(string("iPhone6s"), 9000);
	testTree->insert(string("XboxOne"), 3000);
	testTree->insert(string("Galaxys6"), 6000);
	testTree->insert(string("WiiU"), 2000);
	testTree->insert(string("Playstation4"), 13000);
	testTree->insert(string("SurfacePro4"), 19000);
	testTree->insert(string("iPadAir2"), 12000);
	//TransactionNode *tempT = &testTree->findSmallest();
	//tempT = &testTree->findLargest();
	//testTree->inOrderTraversal();
	//temp = new TransactionNode(string("test the delete"), 666);
	//delete temp;
	//tempT = new TransactionNode(string("testing other delete"),777);
	//delete temp;

	delete testTree;
	
	 cout << "pause stuff" << endl;
}

int main()
{
	tests();

	cout << "yeppers" << endl;

	return 0;
}