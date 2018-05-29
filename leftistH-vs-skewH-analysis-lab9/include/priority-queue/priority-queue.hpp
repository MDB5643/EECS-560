#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

//#include "task.hpp"
#include "BinaryNode.h"

/////////////////////////////////////////////////////////////////
// You may not add any public methods in this class            //
// You may add only private member fields and private methods  //
// The public methods will be used to test your implementation //
/////////////////////////////////////////////////////////////////

/**
 * A priority queue is an ADT which supports fast access to the
 * highest priority element. i.e. minimum element on the top
 * This priority queue supports ordering tasks. Ordering logic being
 * task of minimum nice value on top.
 */
class PriorityQueue {

private:
  // Member fields
  // IMPLEMENT ME
  // Add any private member variables here that you might need

  BinaryNode* rootbeer;

  // Member functions
  // IMPLEMENT ME
  // Add any other private functions you might need


public:
  //Member functions
  /**
   * Constructor to construct the priority queue given an array of tasks
   */
  PriorityQueue(Task*, int);

  /**
   * Constructor to construct an empty priority queue.
   */
  PriorityQueue();

  /**
   * Destructor to destroy the priority queue
   * Make sure you destroy everything that you allocate on memory-heap space
   */
  ~PriorityQueue();


  /**
   * This function merges the two PriorityQueues into one queue
   *
   * There are 2 ways of doing it: deep copy `that` and then concatenate
   * `this` and `that` to update `this`. Or use `that` as is to merge
   * into `this`. You will have to make an appropriate design decision accordingly
   * to make sure there is no scope of memory leak
   */
  void concat(PriorityQueue* that);

  BinaryNode* concatAgain(BinaryNode* orig, BinaryNode* added);

  BinaryNode* kittyHelper(BinaryNode* orig, BinaryNode* added);

  /**
   * Adds one task element to PriorityQueue and restructures the heap to
   * maintain the heap property.
   * HINT: Can you use concat to do this?
   */


  void addElem(Task* task);

  BinaryNode* getRoot();

  /**
   * Deletes the min element from the priority queue and possibly restructures it
   * after the delete operation and returns the element that is deleted
   * HINT: Can you use concat to do this?
   */
  Task* deleteMinElem();

  /**
   * This function performs an inorder traversal over the elements of
   * the priority queue and applies the operation *op on each of the elements.
   */
  int inorderTraversal(int identity, int (*op)(Task*));

  void inorderTraverseLazyRecurse(BinaryNode* subTreePtr);

  /**
   * This function performs a post traversal over the elements of
   * the priority queue and applies the operation *op on each of the elements.
   */
  int postorderTraversal(int identity, int (*op)(Task*));

  void postorderTraverseLazyRecurse(BinaryNode* subTreePtr);

  void postorderHeapDestroyer(BinaryNode* subTreePtr);


};

#endif //PRIORITY_QUEUE_HPP defined
