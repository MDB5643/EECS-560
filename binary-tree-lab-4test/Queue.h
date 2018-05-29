

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"


class Queue
{

public:

  /*
  pre: queue object is created
  post: private member variables are initialized
  */
  Queue();

  /*
	pre: destructor
	post: deletes instances of stack class
	*/
  ~Queue();

  /*
	pre: queue object has been created
	post: returns true if queue is empty, flase otherwise
	*/
  bool isEmpty() const;

  /*
  pre: value is inputed
  post: adds value to the queue. If queue empty, add to front, if queue not empty, add to back.
  **/
  void enqueue(int newEntry);

  /*
  pre: value is inputed and in queue
  post: Removes value from queue
  **/
  void dequeue();

  /*
  pre: assumes value in queue
  post: returns value in front of queue
  **/
  int peekFront();

  Node* getFront();

  Node* nextNode();

  int nextValue();


private:
  Node* m_front;

  Node* m_rear;

  int m_size;

};

//#include "Queue.cpp"

#endif
