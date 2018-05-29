
#ifndef NODE_H
#define NODE_H


class Node
{

public:
 /*
   pre: Node object is created
   post: private member variables are initialized
 */
 Node();

 /*
   pre: valid integer is passed into parameter
   post: m_value is set to val
 */
 void setValue(int value);

 /*
   pre: m_value has valid value
   post: value is returned
 */
 int getValue() const;

 /*
   pre: valid Node* is passed into parameter
   post: m_next is set
 */
 void setNext(Node* prev);

 /*
   pre: m_next has a valid value
   post: value is returned
 */
 Node* getNext() const;


private:
 //the value in the node
 int m_value;

 //the pointer to another node
 Node* m_next;


};

#endif
