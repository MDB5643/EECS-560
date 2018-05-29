#ifndef DOUBLENODE_H
#define DOUBLENODE_H

class doubleNode
{

private:

  int value;

  doubleNode* nextPtr;

  doubleNode* prevPtr;

public:

  doubleNode(int val);

  ~doubleNode();

  int getValue();

  doubleNode* getNext();

  doubleNode* getPrevious();

  void setNext(doubleNode* nNode);

  void setPrevious(doubleNode* pNode);


};

#endif

//#include "doubleNode.cpp"
