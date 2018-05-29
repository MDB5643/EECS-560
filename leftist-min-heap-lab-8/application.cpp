#include "application.hpp"
#include "priority-queue.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <limits>

using namespace std;

Application::Application(std::string appString){

  appSize = 0;

  //THIS WORKS DON'T TOUCH

  string tokenLine;
  std::stringstream ss(appString);

  ss >> id;
  ss >> name;
  ss >> tokenLine;

  unsigned cut = appString.find("(");
  tokenLine = appString.substr(cut);

  //Task *newTask = new Task(tokenLine);


    int newtid;
    int newnice;
    int newappID;
    int newttl;
    //int counter;
    int temp = 112345;

    std::istringstream strs(tokenLine);
    string thing;

    //THIS WORKS DON'T TOUCH
    while (strs)
    {

        strs.ignore();
        strs >> newtid;
        if (temp == newtid)
        {
          break;
        }
        temp = newtid;
        strs.ignore();
        strs >> newnice;
        strs.ignore();
        strs >> newappID;
        strs.ignore();
        strs >> newttl;

        strs.ignore();
        strs.ignore();

        // cout << newtid << endl;
        // cout << newnice << endl;
        // cout << newappID << endl;
        // cout << newttl << endl;

        appSize++;
        Task *newTask = new Task(newtid, newnice, newappID, newttl);
        tasks->addElem(newTask);


    }



    //cout << "here" << endl;
    //tasks->inorderTraverseLazyRecurse(tasks->getRoot());

  // std::cout << "INSIDE APP:" << std::endl;
  // cout << id << endl;
  // cout << name << endl;
  // cout << tokenLine << endl;

}


Application::Application(int i, std::string appName, Task* ts, int size){



}

int Application::getId(){
  return this->id;
}


std::string Application::getName(){
  return this->name;
}



PriorityQueue* Application::getTasks(){
  return this->tasks;
}



int Application::getSize(){
  return appSize;
}
