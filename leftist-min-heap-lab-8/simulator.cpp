#include <iostream>
#include <fstream>
#include <string>

#include "scheduler.hpp"
#include "application.hpp"
#include "task.hpp"

using namespace std;

void initialize(Scheduler*& myScheduler, int argc, char** argv);

////////////////////////////////////////
// You may not change this main file. //
// You can create a new main file for //
// your debugging purposes            //
////////////////////////////////////////

/**
 * This is the entry point for the program.
 * The simulator does 2 main things:
 * Reads data from the input file passed in as a parameter (or data.txt by default)
 * and then works on the data by maininting a schedule. The goal of
 * this exercise is to
 * 1) Build a parser to parse input data into
 *    correct domain objects (Application, Task)
 * 2) Bulid a leftist heap as a Priority Queue
 * 3) Execute the scheduler by using the data given in data.txt. Print
 *    necessary information on the console output.
 * At the end of the simulation, make sure you have destroyed all
 * the memory you have alocated on the heap.
 */
int main(int argc, char** argv){

    // initialize scheduler
    Scheduler* myScheduler = new Scheduler();

    //Read the input data from the file and
    fstream inputData;
    int appCount;
    std::string time;
    int tasksToExecute;

    if(argc < 2){
	cout << "No input file given, using default data.txt" << endl;
	inputData.open("data.txt", ifstream::in);
    } else {
	cout << "Using data from " << argv[1] << endl;
	inputData.open(argv[1], ifstream::in);
    }

    inputData >> appCount;
    cout << "app count: " << appCount << endl;
    for(int timeStampCount = 0; timeStampCount < appCount; timeStampCount++){
	//read the time unit and print it out as is
	if(inputData.is_open()) {
	    getline(inputData, time);
	    getline(inputData, time);
	} else {
	    cout << "Error! This should never happen";
	    break;
	}

	cout << time << endl;

	//read then number of tasks to execute in this time stamp
	inputData >> tasksToExecute;
	cout << "Tasks Executed (" << tasksToExecute << "): ";
	for(int i = 0; i < tasksToExecute; i ++){
	    Task* task = myScheduler->executeNextOnProcessor();
	    cout << task->getTid() << "(" <<  task->getAppId() << ", " << task->getNice() << ")" << " ";
	    delete task;
	}
	cout << endl;

	cout << "Application added to Queue: ";
	//read the next line to get the app data into a string
	std::string appString;
	getline(inputData, appString);
  getline(inputData, appString);
	Application* newApp = new Application(appString);
	cout << newApp->getName() << endl;
	//_Caution_: make sure you deep copy newApp
	myScheduler->addApplicationToSchedule(newApp);
	delete newApp;
    }

    //Last step is to pop all the elements out in the correct piority order.
    cout << endl << "T" << (appCount) << endl;
    cout << "Tasks executed: ";
    while(myScheduler->scheduleSize() != 0){
	Task* task = myScheduler->executeNextOnProcessor();
	cout << task->getTid() << "(" <<  task->getAppId() << ", " << task->getNice() << ")" << " ";
	delete task;
    }
    inputData.close();
    cout << endl << "Done.";


    delete myScheduler;
    return 0;
}
