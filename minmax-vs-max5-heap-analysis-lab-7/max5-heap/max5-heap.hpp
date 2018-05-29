#ifndef MAX5_HEAP_H
#define MAX5_HEAP_H

/////////////////////////////////////////////////////////////////
// You may not add any public methods in this class            //
// You may add only private member fields and private methods  //
// The public methods will be used to test your implementation //
/////////////////////////////////////////////////////////////////

#include <string>

/**
 * Max 5-heap is a heap with 5 childern. The root node is the
 * node of the largest value. Each sub-tree of the heap has
 * the highest value as its root node.
 * Please use a static array of size 15000 for implementation of the heap
 *
 * Caution: You may _not_ use any other cpp container library eg. queue, lists etc
 * or STL for your implementation.
 */
class Max5Heap {

private:
  // Member fields
  // IMPLEMENT ME
  // Add any private member variables here that you might need here

  // Member functions

  std::string* ArrayghtArrayghtArrayght = nullptr;

  std::string* deepBlueCopy = nullptr;

  std::string* heapArray = nullptr;

  int heapSize;

  int numItemsInHeap;

  /**
   * Build the max heap using bottom up approach
   */
  void buildHeap();

  /**
   * Default private constructor to construct the max 5-heap.
   */

  // IMPLEMENT ME
  // Add any other private functions you might need here

public:
  //Member functions
  /**
   * Constructor to construct the max 5-heap given an array and size
   */
  Max5Heap(std::string* elems, int size);

  Max5Heap();

  /**
   * Destructor to destroy the max 5-heap
   * Make sure you destroy everything that you allocate on memory-heap space
   */
  ~Max5Heap();

  /*
   * Returns the current size of the heap. i.e. number of elements
   */
  int size();

  /**
   * Adds `elem` to Max5Heap. Restructures the tree to
   * maintain the heap property.
   */
  void addElem(std::string elem);

  /**
   * Deletes all the occurances of the `elem` from the max 5-heap
   * Restructures the heap if necessary to maintain the heap property.
   */
  void deleteElem(std::string elem);

  /**
   * Deletes the min element from the heap and restructures to maintain the heap property
   * after the delete operation. Returns the element that is deleted
   */
  std::string deleteMinElem();

  /**
   * Deletes the max element from the heap and restructures to maintain the  heap
   * property after the delete operation. Returns the element that is deleted
   */
  std::string deleteMaxElem();

  /**
   * Should return true if the `elem` exists, return false otherwise
   */
  bool exists(std::string elem);

  /**
   * This function performs a levelorder traversal over the existing
   * max 5-heap and prints out each node in a level order fashion
   * Please print every level on a new line.
   */
  void levelOrderPrint();

};

#endif // MAX5_HEAP_H defined
