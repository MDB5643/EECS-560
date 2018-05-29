#include <iostream>
#include <climits>
#include "timer.hpp"
#include "list.hpp"
#include "util.hpp"
#include "sparse-matrix.hpp"

using namespace std;

int  main() {
  Timer* t = new Timer();


  int sizes[5] = {100,500,1000,5000,10000};

  for (int i = 0; i < 5; i++)
  {
    //SparseMatrix* matrix1 = new SparseMatrix(sizes[i], sizes[i]);
    //SparseMatrix* matrix2 = new SparseMatrix(sizes[i], sizes[i]);
    DoublyLinkedList* matrix1 = new DoublyLinkedList();
    DoublyLinkedList* matrix2 = new DoublyLinkedList();
    //doubleNode* testPtr = matrix1->getHead();
    int toAdd = 0;
    int possI = 0;
    int possJ = 0;
    int tenP = sizes[i]*(.1);
    cout << "Size of both matrices: " << sizes[i] << endl;
    srand(time(NULL));
    int nonZeros1 = rand() % tenP + 1;
    int nonZeros2 = rand() % tenP + 1;

    cout << "Number of non-zero elements in matrix 1: " << nonZeros1 << endl;
    cout << "Number of non-zero elements in matrix 2: " << nonZeros2 << endl;

    for (int j = 0; j < nonZeros1; j++)
    {
      toAdd = rand() % INT_MAX + 1;
      possI = rand() % sizes[i] + 1;
      possJ = rand() % sizes[i] + 1;
      matrix1->add(toAdd, possI, possJ, j);
      //cout << "Added " << testPtr->getValue() << " to (" << testPtr->getRowSpot() << ", " << testPtr->getColumnSpot() << ")" << endl;
      //testPtr = testPtr->getNext();
    }

    cout << "" << endl;

    for (int k = 0; k < nonZeros2; k++)
    {
      toAdd = rand() % INT_MAX + 1;
      possI = rand() % sizes[i] + 1;
      possJ = rand() % sizes[i] + 1;
      matrix2->add(toAdd, possI, possJ, k);
    }

    t->start();
    bool isEqual = matrix1->equals(matrix2);
    std::cout << "operation took: ";
    t->printTime(t->stop());
    if (isEqual)
    {
      cout << "The matrices are equivalent" << endl;
    }
    else
    {
      cout << "The matrices are not equivalent" << endl;
    }

  }

  return 0;
}
