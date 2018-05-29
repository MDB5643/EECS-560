#ifndef MINMAX_HEAP_H
#define MINMAX_HEAP_H

/////////////////////////////////////////////////////////////////
// You may not add any public methods in this class            //
// You may add only private member fields and private methods  //
// The public methods will be used to test your implementation //
/////////////////////////////////////////////////////////////////

#include <string>

/**
 * MinMax heap has alternating min and max levels. The root node is the
 * node of the minimum value. Childen of root are max nodes of respective
 * sub-heaps
 * Please use a static array of size 15000 for implementation of the heap
 *
 * Caution: You may _not_ use any other cpp container library eg. queue, lists etc
 * or STL for your implementation.
 */
class MinMaxHeap {

private:
  // Member fields
  // IMPLEMENT ME
  // Add any private member variables here that you might need here

  // Member functions

  std::string* ArrayghtArrayghtArrayght = nullptr;

  std::string* deepBlueCopy = nullptr;

  std::string* heapArray = nullptr;

  //std::string* newAdds = nullptr;

  int heapSize;

  int numItemsInHeap;

  int curr;

  int interval;

  bool atMinLevel = true;

  /**
   * Build the minmax heap using bottom up approach
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
  MinMaxHeap(std::string* elems, int size);

  MinMaxHeap();

  /**
   * Destructor to destroy the minmax heap
   * Make sure you destroy everything that you allocate on memory-heap space
   */
  ~MinMaxHeap();

  /*
   * Returns the current size of the heap. i.e. number of elements
   */
  int size();

  /**
   * Adds `elem` to MinMaxHeap. Restructures the tree to
   * maintain the heap property.
   */
  void addElem(std::string elem);

  /**
   * Deletes all the occurances of the `elem` from the max 5-heap
   * Restructures the heap if necessary to maintain the heap property.
   */
  void deleteElem(std::string elem);

  /**
   * Deletes the min element from the heap and restructures the tree to maintain
   * the heap property after the delete operation.
   * Returns the element that is deleted
   */
  std::string deleteMinElem();

  /**
   * Deletes the max element from the heap and restructures the tree to maintain
   * the heap property after the delete operation.
   * Returns the element that is deleted
   */
  std::string deleteMaxElem();

  /**
   * Should return true if the `elem` exists, return false otherwise
   */
  bool exists(std::string elem);

  /**
   * This function performs a levelorder traversal over the existing
   * minmax heap and prints out each node in a level order fashion
   * prints every level on a new line.
   */
  void levelOrderPrint();

};

#endif // MINMAX_HEAP_H defined
