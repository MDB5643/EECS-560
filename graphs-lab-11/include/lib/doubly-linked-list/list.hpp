#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "edge.hpp"
#include "doubleNode.hpp"

class DoublyLinkedList {
  //Member fields
  doubleNode* headPtr;

  doubleNode* tailPtr;

  int listSize = 0;

  //Member functions
 public:
  /**
   * Public constructor to construct the list
   */
  DoublyLinkedList();

  /**
   * Destructor to destroy the list
   */
  ~DoublyLinkedList();

  /**
   * returns true if the list is empty or returns false
   */
  bool isEmpty();

  /**
   * returns the size of the linked list
   */
  int size();

  /**
   * add and element on a specific position
   * Should throw an exception if the value of position
   * is not in range of [0, this.size()]
   */
  void add(int v1, int v2, int cost, int position);

  /**
   * Deletes all the occurences of the elem from the list
   */
  void deleteAll(Edge elem);

  /**
   * Should find the first occurence of the position of the element in the list.
   * returns -1 if the element does not exist in the list
   */
  int find(Edge elem);


  /**
   * Prints all the elements of the list with delimited with space
   */
  void print();
};

#endif //DOUBLY_LINKED_LIST_H defined
