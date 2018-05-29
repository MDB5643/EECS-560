#include <iostream>
#include <fstream>

#include "util.hpp"
#include "list.hpp"
#include "doubleNode.hpp"

using namespace std;

void printMenu();
void initialize(DoublyLinkedList* myList, int argCount, char** args);
void cleanUp(DoublyLinkedList* myList);
/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){
  int option;
  int elem;
  DoublyLinkedList* myList = new DoublyLinkedList();

  //read from the file and initialize the doubly link list
  initialize(myList, argCount, args);
  printMenu();
  cin >> option;
  while(option != 5){
    switch(option){
    case 1:
      cout << "Enter element to add: ";
      int newElement, position;
      cin >> newElement;
      cout << "Enter position to add element: ";
      cin >> position;
      try
      {
        myList->add(newElement, position);
      }
      catch(int e)
      {
        std::cout << "Position out of bounds!" << '\n';
      }
      myList->print();
      break;
    case 2:
      // 2: delete
      cout << "Enter element to be deleted: ";
      cin >> elem;
      myList->deleteAll(elem);
      myList->print();
      break;
    case 3:
      //3: find
      cout << "Enter element to be searched: ";
      cin >> elem;
      myList->find(elem);
      break;
    case 4:
      //4: print
      myList->print();
      break;
    default:
      cout << "Invalid argument. Please try again" << endl;
      break;
    }
    printMenu();
    cin >> option;
  }

  cleanUp(myList);
  return 0;
}

/**
 * Prints the menu of choices to the user
 */
void printMenu(){
  cout << "Please choose one of the following commands:" << endl;
  cout << "1: add" << endl;
  cout << "2: delete" << endl;
  cout << "3: find" << endl;
  cout << "4: print" << endl;
  cout << "5: exit" << endl;
  cout << ">> ";
}

/**
 * Initializes the data structures and program environment
 */
void initialize(DoublyLinkedList*  myList, int argCount, char** args){
    fstream inputData;
    if(argCount < 2){
      cout << "No input file given, using default data.txt" << endl;
      inputData.open("data.txt", ifstream::in);
    } else {
      cout << "Using data from " << args[1] << endl;
      inputData.open(args[1], ifstream::in);
    }
    while(!inputData.eof()){
	     int newElement;
	      inputData >> newElement;
	       if(inputData.good()){
		         myList->add(newElement, myList->size());
	          }
}
    inputData.close();
}

void cleanUp(DoublyLinkedList* myList){
  delete myList;
}
