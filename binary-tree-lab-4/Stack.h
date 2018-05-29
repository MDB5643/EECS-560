/**
* @project: Elevator Action
* @filename Stack.h
* @author Matt Bailey
* @since 2016.03.01
*/

/**
*implements all methods from the StackInterface class
*put precondition, postcondition, return, and throw comments in this class
*use Node class form lab3 as building blocks for stack, but need teplated version
*/

#ifndef STACK_H
#define STACK_H

#include "Node.h"



class Stack
{
 public:
 /*
 pre: Stack object is created
 post: private member variables are initialized
 */
 Stack();

 /*
 pre: Destructor
 post: Deletes instances of stack class
 */
 ~Stack();

 /*
 pre: Stack object has been created
 post: Returns true if stack is empty, flase otherwise
 */
 bool isEmpty() const;

 /*
 pre: value is inputed
 post:adds value to the top of the Stack
 **/
 void push(int);

 /*
 pre: Assumes stack is not empty
 post: Entry added to top of stack
 **/
 void pop();

 /*
 pre: assumes the stack is not empty
 post: top of the stack is removed, throws PreconditionViolationException
 *when a pop is attempted on an empty stack. Does not return a value in this case.
 **/
 int peek();

 /*
 pre: stack created
 post: returns the size of the stack
 **/
 int size() const;


 Node* nextNode();

 int nextValue();

 private:
   //isnatce of node class, pointer
   Node* m_top;

   //size of Stack
   int m_size;


};

//#include "Stack.cpp"

#endif
