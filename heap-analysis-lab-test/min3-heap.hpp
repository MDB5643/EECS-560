#ifndef MIN3_HEAP_H
#define MIN3_HEAP_H

/////////////////////////////////////////////////////////////////
// You may not add any public methods in this class            //
// You may add only private member fields and private methods  //
// The public methods will be used to test your implementation //
/////////////////////////////////////////////////////////////////

#include <string>

/**
 * Min 3-heap is a heap with 3 childern and the root node is the
 * node of the smallest value.
 */
class Min3Heap {

private:
  // Member fields
  // IMPLEMENT ME
  // Add any private member variables here that you might need

  std::string* ArrayghtArrayghtArrayght = nullptr;

  std::string* deepBlueCopy = nullptr;

  std::string* heapArray = nullptr;

  int heapSize;

  int numItemsInHeap;

  // Member functions
  /**
   * Build the min heap using bottom up approach
   */
  void buildHeap();

  /**
   * Constructor to construct the min 3-heap.
   */


  // IMPLEMENT ME
  // Add any other private functions you might need
public:
  //Member functions
  /**
   * Constructor to construct the min 3-heap given an array
   */
   Min3Heap();
  Min3Heap(std::string*, int passSize);

  /**
   * Destructor to destroy the min 3-heap
   * Make sure you destroy everything that you allocate on memory-heap space
   */
  ~Min3Heap();

  /**
   * Adds `elem` to Min3Heap and restructures the heap to
   * maintain the heap property.
   */
  void addElem(std::string elem);

  /**
   * Deletes all the occurances of the `elem` from the min 3-heap
   * Restructures the heap if necessary to maintain the heap property.
   */
  void deleteElem(std::string elem);

  /**
   * Deletes the min element from the heap and restructures to maintain the heap property
   * after the delete operation and returns the element that is deleted
   */
  std::string deleteMinElem();

  /**
   * Deletes the max element from the heap and restructures to maintain the  heap
   * property after the delete operation and returns the element that is deleted
   */
  std::string deleteMaxElem();

  /**
   * Should return true if the `elem` exists, return false otherwise
   */
  bool exists(std::string elem);

  /**
   * This function performs a levelorder traversal over the existing
   * min 3-heap and prints out each node in a level order fashion
   */
  void levelOrderPrint();

};

#endif //MIN3_HEAP_H defined
