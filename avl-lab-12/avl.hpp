#ifndef AVL_HPP
#define AVL_HPP
#include "book.hpp"
#include "BinaryNode.h"
#include <string>

/**
 * AVL tree is a self balanced binary search tree
 */
class AVL {

private:
  //Member fields


  //Member functions
  //IMPLEMENT ME

public:
  BinaryNode* rootbeer;

  //Member functions
  /**
   * Constructor to construct the binary search tree.
   */
  AVL();

  /**
   * Destructor to destroy the binary search tree
   * Make sure you destroy everything that you allocate on heap.
   */
  ~AVL();

  /**
   * Returns true if the AVL tree is empty or returns false
   */
  bool isEmpty();

  /**
   * add a book instance to the AVL Tree and balance it if necessary
   */
  void addBook(Book*);

  /**
  * recursive helper function for addBook
  */

  BinaryNode* addHelp(BinaryNode*, Book*);

  /**
  * two more recursive functions to calculate subtree height
  */

  int heighthelp(BinaryNode*);

  int heighthelpHELP(BinaryNode*);

  Book* searchHelp(int, BinaryNode*);

  /**
   * Searches for the book given its id
   */
  Book* search(int id);

  /**
   * this function performs a levelorder traversal over the existing
   * AVL tree and performs the operation op on each of the Book instance
   * stored in the AVL tree.
   */
  void levelorderTraverse(BinaryNode*);

  void inorderTraverseLazyRecurse(BinaryNode* subTreePtr);

  BinaryNode* leftleftrotation(BinaryNode*);
  BinaryNode* leftrightrotation(BinaryNode*);
  BinaryNode* rightrightrotation(BinaryNode*);
  BinaryNode* rightleftrotation(BinaryNode*);

};

#endif //AVL_HPP defined
