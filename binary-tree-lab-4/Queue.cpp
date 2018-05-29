


#include "Node.cpp"
#include "Queue.h"
#include <iostream>

Queue::Queue()
{
  //constructor
  m_front = nullptr;
  m_size = 0;

}//end of constructor

Queue::~Queue()
{
  //destructor
  while(m_front->getNext() != nullptr)
    {
      Node* temp = m_front->getNext();
      delete m_front;
      m_front = temp;

    }

}//end of destructor

Node* Queue::getFront()
{
  return m_front;
}

bool Queue::isEmpty() const
{
  //checks to see if stack is empty
  if (m_size == 0)
    {
      return true;
    }
  else
    {
      return false;
    }

}//end of isEmpty method


void Queue::enqueue(const int newEntry)
{
  Node* newNode = new Node;
  newNode->setValue(newEntry);

  if(newNode == nullptr)
  {
    std::cout << "Heap memory is full." << std::endl;
  }
  else if(m_front == nullptr)
  {
    m_front = newNode;
    m_size++;
  }
  else
  {
    Node* temp = m_front;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		  temp->setNext(newNode);

      m_size++;
  }


}//end of enqueue method

void Queue::dequeue()
{
  Node* temp = m_front;
  if (m_size == 0)
  {
    std::cout << "Tried to delete an empty queue." << std::endl;
  }
  else
  {
    //Node<T>* temp = m_front;
    temp = m_front->getNext();
    delete m_front;
    m_front = temp;
    m_size--;
  }

}//end of dequeue method

int Queue::peekFront()
{
  if(m_size == 0)
    {
      std::cout << "Peek attempted on empty queue." << std::endl;
    }
  else
    {
      return(m_front->getValue());
    }
return 0;
}//end of peekFront method

Node* Queue::nextNode()
{
  if(m_front == nullptr)
  {
    std::cout << "NextNode attempted on too small of a queue." << std::endl;
  }
  else if (m_front->getNext() == nullptr)
  {
    return nullptr;
  }
  else
  {
    Node* temp = m_front;
    temp = temp->getNext();

    return temp;
  }
  return nullptr;
}

int Queue::nextValue()
{
  if (m_front == nullptr)
  {
    std::cout << "NextNode attempted on too small of a queue." << std::endl;
  }
  else if (m_front->getNext() == nullptr)
  {
    return 0;
  }
  else
  {
    Node* temp = m_front;
    temp = temp->getNext();

    return temp->getValue();
  }
  return 0;
}
