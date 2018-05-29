#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <climits>
#include "timer.hpp"
#include "list.hpp"
#include "util.hpp"


using namespace std;

int  main() {
  Timer* t = new Timer();

  int sizes[9] = {10,50,100,500,1000,5000,10000,50000,100000};

  for (int i = 0; i <= 8; i++)
  {
    int counter = 0;
    double sum = 0;
    double deleteTimes[10];
    int toAdd = 0;
    int toDelete = 0;

    cout << "Size of list:" << sizes[i] << endl;
    cout << "Times:" << endl;
    for (int k = 0; k < 10; k++)
    {
      DoublyLinkedList* megaList = new DoublyLinkedList();
      t->start();
      for (int j = 0; j < sizes[i]; j++)
        {
          toAdd = rand() % INT_MAX + 1;
          megaList->add(toAdd, j);
          counter++;
          if (j == 7)
          {
            toDelete = toAdd;
          }
        }
        t->start();
        megaList->deleteAll(toDelete);
        t->printTime(t->stop());
        deleteTimes[k] = t->stop();
        counter = 0;
    }
    for (int m = 0; m < 10; m++)
    {
      sum = sum + deleteTimes[m];
    }
    double average = sum/10;
    cout << "Average: " << average << endl << endl;
  }
  //std::cout << "operation took: ";
  //t->printTime(t->stop());

  return 0;
}
