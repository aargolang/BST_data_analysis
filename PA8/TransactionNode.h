#include "Node.h"

class TransactionNode : protected Node
{
public:
	TransactionNode();
	TransactionNode(TransactionNode &copyNode);
	~TransactionNode();

	void setUnits(int newUnits);
	int getUnits();

	void printData();

private:
	int mUnits;
};