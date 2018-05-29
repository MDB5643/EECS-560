#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>

#include "priority-queue.hpp"
#include "task.hpp"
#include "util.hpp"

/**
 * Models a simple application that runs on the operating system.
 * It is a collection of tasks that needs to be executed.
 */
class Application {

  /**
   * A _unique_ id that application can be used to identify
   */
  int id;

  /**
   * name for the application
   */
  std::string name;

  /**
   * processes arranged in priority order for this application
   */

   int appSize = 0;

public:

  PriorityQueue* tasks = new PriorityQueue();
  /**
   * Public constructor
   */
  Application(int, std::string, Task*, int);

  /**
   * Creates an application object by parsing the string
   * this is called as deserializtion.
   */
  Application(std::string appString);

  /**
   * get application id
   */
  int getId();

  /**
   * get name of appliation
   */
  std::string getName();

  /**
   * get the number of tasks that this application contains
   */
  int getSize();

  /**
   * get the processes associated with the application
   */
  PriorityQueue* getTasks();

};

#endif //APPLICATION_HPP defined
