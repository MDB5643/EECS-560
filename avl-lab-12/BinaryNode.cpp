
#ifndef _BINARY_NODE_CPP
#define _BINARY_NODE_CPP


#include "BinaryNode.h"

using namespace std;


BinaryNode::BinaryNode()
{
  //value = 0;
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
}

void BinaryNode::setBook(Book* inBook)
{
  nodeBook = inBook;
}

Book* BinaryNode::getBook()
{
  return nodeBook;
}

int BinaryNode::getVal()
{
  //return value;
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

#endif
