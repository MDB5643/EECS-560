#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

/////////////////////////////////////////////////////////////////////
// You may add any private methods or private data fields          //
// You may not add any public methods or modify the signatures     //
// of the existing functions. Your code will                       //
// be tested againt the public mehtods that have been predeclared  //
/////////////////////////////////////////////////////////////////////

#include <string>

#include "task.hpp"
#include "simulator/application.hpp"
#include "priority-queue/priority-queue.hpp"

class Scheduler {

  PriorityQueue* schedule;
  int schedSize;

public:

  /**
   * default constructor
   */
  Scheduler();

  /**
   * default destructor
   */
    ~Scheduler();
  /**
   * adds all the tasks from the application in the schedule
   */
  void addApplicationToSchedule(Application* );

  /**
   * returns the hightest priority task that should be scheduled
   * on the processor and deletes it from the schedule
   */
  Task* executeNextOnProcessor();

  /**
   * returns true if schedule is empty, false otherwise
   */
  bool isEmpty();

  /**
   * returns the size of the current schedule
   */
   int scheduleSize();
};

#endif //SCHEDULER_HPP defined
