#include "simulator/scheduler.hpp"
#include "simulator/task.hpp"
#include "util/util.hpp"

Scheduler::Scheduler(){
  this->schedule = new PriorityQueue();
  schedSize = 0;
  IMPLEMENT_ME();
}

void Scheduler::addApplicationToSchedule(Application* app){
  schedule->concat(app->tasks);
  schedSize = schedSize + app->getSize();
  schedule->inorderTraverseLazyRecurse(schedule->getRoot());
}

Scheduler::~Scheduler()
{

}

Task* Scheduler::executeNextOnProcessor(){
  schedSize--;
  return schedule->deleteMinElem();
}

bool Scheduler::isEmpty(){
  if (schedule->getRoot() == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Scheduler::scheduleSize(){
  cout << schedSize << endl;
  return schedSize;
}
