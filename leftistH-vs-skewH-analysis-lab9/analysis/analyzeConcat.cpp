#include <iostream>
#include "util/timer.hpp"
#include "priority-queue/leftist-heap/leftist-heap.hpp"
#include "priority-queue/skew-heap/skew-heap.hpp"
#include "priority-queue/priority-queue.hpp"
#include "util/util.hpp"
#include <climits>

int  main() {
  int valueLoad[9] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};

  double summation;
  PriorityQueue* testHeapo1;
  PriorityQueue* testHeapo2;
  Timer* chronos = new Timer();


  for (int maxim : valueLoad)
  {
    summation = 0;
    for (int i = 0; i < 10; i++)
    {

      testHeapo1 = new PriorityQueue();
      testHeapo2 = new PriorityQueue();

      for (int k = 0; k < maxim; k++)
      {
        int toAdd = rand() % INT_MAX + 1;
        Task* testTasko = new Task(toAdd, toAdd, 0, 0);
        testHeapo1->addElem(testTasko);
      }
      for (int k = 0; k < maxim; k++)
      {
        int toAdd = rand() % INT_MAX + 1;
        Task* testTasko = new Task(toAdd, toAdd, 0, 0);
        testHeapo2->addElem(testTasko);
      }
      chronos->start();
      testHeapo1->concat(testHeapo2);
      double timing = chronos->stop();
      std::cout << "Operation took: " << timing << endl;
      summation = summation + timing;
    }

    double avg = summation/10;
    std::cout << "Average for heap size " << maxim << ": " << avg << endl;

  }
  //delete testHeapo;

  return 0;
}
