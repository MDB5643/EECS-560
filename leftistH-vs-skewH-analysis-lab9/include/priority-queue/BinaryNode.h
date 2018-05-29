

#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <cstddef>
#include "simulator/task.hpp"

using namespace std;


class BinaryNode
{

private:

	int rank;
	int nicevalue;
	int tidvalue;

	Task* nodeTask;

	BinaryNode* leftChildPtr;

	BinaryNode* rightChildPtr;

public:

	BinaryNode();

	BinaryNode(int nicevalue, int tidvalue);

	BinaryNode* leftPtr;

	BinaryNode* rightPtr;

	void setVal(int);

	int getniceval();

	int gettidvalue();

	int getRank();

	void setRank(int setter);

	void setniceval(int nval);

	void settidvalue(int tval);

	bool isLeaf();

	void setTask(Task* task);

  Task* getTask();

	BinaryNode* getLeftChildPtr();

	BinaryNode* getRightChildPtr();

	void setLeftChildPtr(BinaryNode* leftPtr);

	void setRightChildPtr(BinaryNode* rightPtr);

}; // end BinaryNode

//#include "BinaryNode.cpp"

#endif
