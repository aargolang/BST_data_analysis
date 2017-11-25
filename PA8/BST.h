#include <string>
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	BST();
	BST(BST &copyBST);
	~BST();

	void setRoot();
	Node *&getRoot();

	void insert(std::string &newDat); // newDat datatype is debatable
	void inOrderTraversal();
	TransactionNode &findSmallest();
	TransactionNode &findLargest();

private:
	Node *mpRoot;

	bool destroyTree();
	bool insert(Node *&pRoot);
	void inOrderTraversal(Node *&pRoot);

};