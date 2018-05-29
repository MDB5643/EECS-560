#include <iostream>
#include "timer.hpp"
#include "bst.hpp"
#include "util.hpp"
#include <climits>

int  main() {
  //Timer* t = new Timer();

  //t->start();
  //IMPLEMENT_ME();
  //std::cout << "operation took: ";
  //t->printTime(t->stop());

  int nodeLoad[9] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};

  double summation;
  BST* mynarySearchTree; //it's a pun!
  Timer* chronos = new Timer();


  for (int maxim : nodeLoad)
  {
    summation = 0;
    for (int i = 0; i < 10; i++)
    {
      mynarySearchTree = new BST();
      chronos->start();
      for (int k = 0; k < maxim; k++)
      {
        int toAdd = rand() % INT_MAX + 1;
        mynarySearchTree->addElem(toAdd);
      }
      double timing = chronos->stop();
      std::cout << "Operation took: " << timing << endl;
      summation = summation + timing;
    }

    double avg = summation/10;
    std::cout << "Average for tree size " << maxim << ": " << avg << endl;

  }
  delete mynarySearchTree;

  return 0;
}
