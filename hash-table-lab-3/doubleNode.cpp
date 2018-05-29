#include "doubleNode.hpp"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

using namespace std;

doubleNode::doubleNode(string val)
{
  value = val;

  rowSpot = 0;
  columnSpot = 0;
  matVal = 0;
}

doubleNode::~doubleNode()
{

}

string doubleNode::getValue()
{
  return value;
}

int doubleNode::getRowSpot()
{
  return rowSpot;
}

int doubleNode::getColumnSpot()
{
  return columnSpot;
}

int doubleNode::getMatVal()
{
  return matVal;
}

doubleNode* doubleNode::getNext()
{
  return nextPtr;
}

doubleNode* doubleNode::getPrevious()
{
  return prevPtr;
}

void doubleNode::setNext(doubleNode* nNode)
{
  nextPtr = nNode;
}

void doubleNode::setPrevious(doubleNode* pNode)
{
  prevPtr = pNode;
}

void doubleNode::setRowSpot(int i)
{
  rowSpot = i;
}

void doubleNode::setColumnSpot(int j)
{
  columnSpot = j;
}

void doubleNode::setMatrixVal(int toAdd)
{
  matVal = toAdd;
}
