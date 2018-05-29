#include <iostream>


#include "../util/timer.hpp"
#include "minmax-heap.hpp"
#include "../util/util.hpp"

#include "random-word-generator-demo.cpp"

using namespace std;

int  main() {

  MinMaxHeap* heapaleap;


  string* inputDataArr;

   int sizelist[11] = {10, 50, 100, 250, 500, 750, 1000, 2500, 5000, 7500, 10000};
   double summation;
  // Min3Heap* heapaleap = nullptr;
   Timer* chronos = new Timer;
  //

   for (int maxim : sizelist)
   {

      inputDataArr = wordGen(maxim);
       heapaleap = new MinMaxHeap();

       for (int i = 0; i < maxim; i++)
       {
         heapaleap->addElem(inputDataArr[i]);
       }

       for (int j = 0; j < 10; j++)
       {
         chronos->start();
          heapaleap->deleteMinElem();
          double timing = chronos->stop();
          std::cout << "Operation took: " << timing << endl;
          summation = summation + timing;

        }




        double avg = summation/10;
        cout << "Average: " << avg << endl;

     }


  return 0;
}
