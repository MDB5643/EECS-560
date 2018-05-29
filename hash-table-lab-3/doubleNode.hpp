#ifndef DOUBLENODE_H
#define DOUBLENODE_H
#include <string>
using namespace std;

class doubleNode
{

private:

  string value;

  int rowSpot;

  int columnSpot;

  int matVal;

  doubleNode* nextPtr;

  doubleNode* prevPtr;

public:

  doubleNode(string val);

  ~doubleNode();

  string getValue();

  int getRowSpot();

  int getColumnSpot();

  int getMatVal();

  doubleNode* getNext();

  doubleNode* getPrevious();

  void setNext(doubleNode* nNode);

  void setPrevious(doubleNode* pNode);

  void setRowSpot(int x);

  void setColumnSpot(int y);

  void setMatrixVal(int toAdd);

};

#endif

//#include "doubleNode.cpp"
