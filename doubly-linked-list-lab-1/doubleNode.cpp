#include "doubleNode.hpp"

using namespace std;

doubleNode::doubleNode(int val)
{
  value = val;
}

doubleNode::~doubleNode()
{

}

int doubleNode::getValue()
{
  return value;
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
