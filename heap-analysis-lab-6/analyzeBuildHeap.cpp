#include <iostream>
#include <fstream>

#include "timer.hpp"
#include "min3-heap.hpp"
#include "util.hpp"
#include "random-word-generator-demo.cpp"

using namespace std;

int  main() {

  Min3Heap* heapaleap;


  string* inputDataArr;

   int sizelist[11] = {10, 50, 100, 250, 500, 750, 1000, 2500, 5000, 7500, 10000};
   double summation;
  // Min3Heap* heapaleap = nullptr;
   Timer* chronos = new Timer;
  //
   for (int maxim : sizelist)
   {

      inputDataArr = wordGen(maxim);
       heapaleap = new Min3Heap();

       for (int j = 0; j < 10; j++)
       {
         chronos->start();
          heapaleap->addElem(inputDataArr[j]);
          double timing = chronos->stop();
          std::cout << "Operation took: " << timing << endl;
          summation = summation + timing;
        }



        double avg = summation/10;
        cout << "Average: " << avg << endl;

     }



  return 0;
}
