//////////////////////////////////////////////////////////
// PLEASE DO NOT CHANGE THIS FILE UNLESS APPROVED BY ME //
// CREATE YOUR OWN MAIN FILE FOR DEBUGGING              //
//////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

#include "util.hpp"
#include "hash-table.hpp"
#include "list.hpp"
#include "doubleNode.hpp"

using namespace std;

void printMenu();
void initialize(HashTable* &myHashTable, int argCount, char** args);
void cleanUp(HashTable* myHashTable);

/**
 * This is the main entry point for the application
 * if you want to use your own custom data file you will have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){
  int option;
  HashTable* myHashTable = nullptr;
  string elem;

  //read from the file and initialize the hash table
  initialize(myHashTable, argCount, args);
  printMenu();
  cin >> option;
  while(option != 5){
    switch(option){
    //add
    case 1:
      cout << "Enter element to add: ";
      cin >> elem;
      myHashTable->putValue(elem);
      myHashTable->print();
      break;
    case 2:
      // 2: delete
      cout << "Enter element to be deleted: ";
      cin >> elem;
      myHashTable->deleteValue(elem);
      myHashTable->print();
      break;
    case 3:
      //3: search value
      cout << "Enter element to be searched: ";
      cin >> elem;
      cout << (myHashTable->searchValue(elem) ? "Exists" : "Does not exist");
      break;
    case 4:
      //4: print
      myHashTable->print();
      break;
    default:
      cout << "Invalid argument. Please try again" << endl;
      break;
    }
    printMenu();
    cin >> option;
  }
  cleanUp(myHashTable);
  return 0;
}

/**
 * Prints the menu of choices to the user
 */
void printMenu(){
  cout << "Please choose one of the following commands:" << endl;
  cout << "1: add" << endl;
  cout << "2: delete" << endl;
  cout << "3: search" << endl;
  cout << "4: print" << endl;
  cout << "5: exit" << endl;
  cout << ">> ";
}

/**
 * Initializes the data structures and program environment
 */
void initialize(HashTable* &myHashTable, int argCount, char** args){
    fstream inputData;
    if(argCount < 2){
      cout << "No input file given, using default data.txt" << endl;
      inputData.open("data.txt", ifstream::in);
    } else {
      cout << "Using data from " << args[1] << endl;
      inputData.open(args[1], ifstream::in);
    }

    int initial_size;
    inputData >> initial_size;
    myHashTable = new HashTable(initial_size);

    while(!inputData.eof()){
      string newElement;
      inputData >> newElement;
      if(inputData.good()){
          myHashTable->putValue(newElement);
      }
    }
    inputData.close();
}

void cleanUp(HashTable* myHashTable){
  delete myHashTable;
}
