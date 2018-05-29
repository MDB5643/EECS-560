#ifndef TASK_HPP
#define TASK_HPP

#include<string>

/**
 * Task is the undivisable entity of work that can be performed
 * by the operating system. (someting like a set of instructions)
 */
class Task {
  /**
   * id that _uniqulely_ identifies the task in
   * the operating system across
   * applications
   */
  int tid;

  /**
   * nice value is the priority of the task
   * lower the nice value higher the priority
   */
  int nice;

  /**
   * the application id the task belongs to
   */
  int appId;

  /**
   * time needed to execute the task on the operating system
   */
  int ttl;

public:
  /**
   * Constructor for task
   */
  Task(int, int, int, int);

  /**
   * Creates a task by reading the string (7, 0, 1, 5)
   * This is called deserializtion of object
   */
  Task(std::string);

  /**
   * Get tid for the task
   */
  int getTid();

  /**
   * get nice value for the task
   */
  int getNice();

  /**
   * get the application id the task belongs to
   */
  int getAppId();

  /**
   * get the time to live value
   */
  int getTtl();
};

#endif // TASK_HPP defined
