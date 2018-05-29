

#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <cstddef>

using namespace std;


class BinaryNode
{

private:

	int value;

	BinaryNode* leftChildPtr;

	BinaryNode* rightChildPtr;

public:

	BinaryNode();

	BinaryNode(int val);

	BinaryNode* leftPtr;

	BinaryNode* rightPtr;

	void setVal(int);

	int getVal();

	bool isLeaf();

	BinaryNode* getLeftChildPtr();

	BinaryNode* getRightChildPtr();

	void setLeftChildPtr(BinaryNode* leftPtr);

	void setRightChildPtr(BinaryNode* rightPtr);

}; // end BinaryNode

//#include "BinaryNode.cpp"

#endif
