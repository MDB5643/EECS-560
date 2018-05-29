#include "lib/doubly-linked-list/doubleNode.hpp"

using namespace std;

doubleNode::doubleNode(int v1, int v2, int cost)
{
  Edge* thisEdge = new Edge(v1, v2, cost);
  ve1 = v1;
  ve2 = v2;
}

doubleNode::~doubleNode()
{

}

int doubleNode::getValue()
{
  //return v1+v2+v3;
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
