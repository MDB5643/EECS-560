#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include "edge.hpp"

class doubleNode
{

private:

  //Edge* thisEdge;

  doubleNode* nextPtr;

  doubleNode* prevPtr;

public:

  int ve1;

  int ve2;

  doubleNode(int v1, int v2, int cost);

  ~doubleNode();

  int getValue();

  doubleNode* getNext();

  doubleNode* getPrevious();

  void setNext(doubleNode* nNode);

  void setPrevious(doubleNode* pNode);


};

#endif

//#include "doubleNode.cpp"
