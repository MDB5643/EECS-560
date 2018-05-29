/**
* @project: Elevator Action
* @filename Stack.cpp
* @author Matt Bailey
* @since 2016.03.01
*/

#include "Stack.h"
#include <iostream>

Stack::Stack()
{
 //constructor
 m_top = nullptr;
 m_size = 0;

}//end of constructor

Stack::~Stack()
{
 //destructor
 while(m_top->getNext() != nullptr)
   {
     Node* temp = m_top->getNext();
     delete m_top;
     m_top = temp;

   }

}//end of destructor

bool Stack::isEmpty() const
{
 //check if stack is empty
 if (m_size == 0)
   {
     return true;
   }
 else
   {
     return false;
   }

}//end of isEmpty method

void Stack::push(const int newEntry)
{
 //entry added to top of stack
 Node* newNode = new Node();
 newNode->setValue(newEntry);
 if(m_top == nullptr)
   {
     m_top = newNode;
     m_size++;
   }
 else
   {
     newNode->setNext(m_top);
     m_top = newNode;
     m_size++;
   }

}//end of push method

void Stack::pop()
{
 //pop and delete top of stack
 if(m_size == 0)
   {
     //throw std::runtime_error("");
     std::cout << "Pop attempted on empty stack!" << std::endl;
   }
 else
   {
     //stack is not empty, delete top
     Node* temp = m_top->getNext();
     delete m_top;
     m_top = temp;
     m_size--;
   }


}//end of pop method

int Stack::peek()
{

 if(m_size == 0)
   {
     std::cout << "Peek attempted on empty stack!" << std::endl;
   }
 else
   {
     return(m_top->getValue());
   }
return 0;

}//end of peek method

int Stack::size() const
{
 return m_size;
}//end of size method

Node* Stack::nextNode()
{
 if (m_top == nullptr)
 {
   std::cout << "NextNode attempted on too small of a Stack." << std::endl;
 }
 else
 {
   return m_top->getNext();
 }
 return 0;
}

int Stack::nextValue()
{
 if (m_top == nullptr)
 {
   std::cout << "NextNode attempted on too small of a Stack." << std::endl;
 }
 else
 {
   Node* nextNode = m_top->getNext();
   return nextNode->getValue();
 }
 return 0;
}
