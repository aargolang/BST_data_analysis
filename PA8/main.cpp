#include <iostream>
#include <string>
//#include "BST.h"
//#include "DataAnalysis.h"
#include "Node.h"
#include "TransactionNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void tests()
{
	 TransactionNode n(string("Where's all the data?"), 14);
	
	 TransactionNode n2(string("dat 1"), 1); 
	 TransactionNode n3(string("dat 2"), 2); 
	 TransactionNode n4(string("dat 3"), 3);
	 TransactionNode n5(string("dat 4"), 4);
	 // n.printData();
	 Node *root;
	 Node *temp;
	 root = &n;
	 temp = &n2;
	 dynamic_cast<TransactionNode*>(root)->printData();
	 root->setLeft(temp);
	 temp = &n3;
	 root->setRight(temp);
	 temp = &n4;
	 root->getRight()->setLeft(temp);
	 temp = &n5;
	 root->getLeft()->setRight(temp);

	 
	 cout << "pause stuff" << endl;
}

int main()
{
	tests();

	cout << "yeppers" << endl;

	return 0;
}