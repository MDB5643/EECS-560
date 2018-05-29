#include "simulator/task.hpp"
#include "util/util.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <limits>

using namespace std;

Task::Task(int id, int p, int aid, int t): tid(id), nice(p), appId(aid), ttl(t) {}

Task::Task(std::string taskLine){

}

int Task::getTid() {
  return this->tid;
}

int Task::getNice() {
  return this->nice;
}

int Task::getAppId(){
  return this->appId;
}

int Task::getTtl(){
  return this->ttl;
}
