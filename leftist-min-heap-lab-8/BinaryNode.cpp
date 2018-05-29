
#ifndef _BINARY_NODE_CPP
#define _BINARY_NODE_CPP


#include "BinaryNode.h"

using namespace std;


BinaryNode::BinaryNode()
{
  //value = 0;
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
  rank = 0;
}

BinaryNode::BinaryNode(int nvalue, int tvalue)
{
  nicevalue = nvalue;
  tidvalue = tvalue;
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
  rank = 0;
}

// void BinaryNode::setVal(int val)
// {
//   value = val;
// }

int BinaryNode::getRank()
{
  return rank;
}

void BinaryNode::setRank(int setter)
{
  rank = setter;
}

int BinaryNode::getniceval()
{
    return nicevalue;
}

int BinaryNode::gettidvalue()
{
  return tidvalue;
}

void BinaryNode::setniceval(int nval)
{
  nicevalue = nval;
}

void BinaryNode::settidvalue(int tval)
{
  tidvalue = tval;
}

bool BinaryNode::isLeaf()
{
  if (leftChildPtr == nullptr && rightChildPtr == nullptr)
  {
    return true;
  }
  else
  {
      return false;
  }
}

BinaryNode* BinaryNode::getLeftChildPtr()
{
  return leftChildPtr;
}

BinaryNode* BinaryNode::getRightChildPtr()
{
  return rightChildPtr;
}

void BinaryNode::setLeftChildPtr(BinaryNode* leftPtr)
{
    leftChildPtr = leftPtr;
}

void BinaryNode::setRightChildPtr(BinaryNode* rightPtr)
{
  rightChildPtr = rightPtr;
}

void BinaryNode::setTask(Task* task)
{
    nodeTask = task;
}

Task* BinaryNode::getTask()
{
  return nodeTask;
}

#endif
