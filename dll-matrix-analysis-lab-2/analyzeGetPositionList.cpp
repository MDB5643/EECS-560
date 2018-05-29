#include <iostream>
#include <climits>
#include "timer.hpp"
#include "list.hpp"
#include "util.hpp"

using namespace std;

int  main() {
  Timer* t = new Timer();

  int sizes[9] = {10,50,100,500,1000,5000,10000,50000,100000};

  for(int i : sizes)
  {
    double sum = 0;

    for(int k = 0; k <=8; k++)
    {
      DoublyLinkedList* megaList = new DoublyLinkedList();

      for(int j = 0; j < i; j++)
      {
        int toAdd = rand() % INT_MAX + 1;

        megaList->add(toAdd, j);
      }

      t->start();

      megaList->getPositionList(megaList);
      double testTime = t->stop();
      sum = sum + testTime;
      cout << testTime << endl;

    }

    double avgTime = sum/10;
    cout << "List size: " << i << endl;
    cout << "Average time: " << avgTime << endl;

  }


  // IMPLEMENT_ME();
  // std::cout << "operation took: ";
  // t->printTime(t->stop());

  return 0;
}
