#include <iostream>
#include <fstream>

#include "util.hpp"
#include "binary-tree.hpp"
#include "Queue.h"

using namespace std;

void printMenu();
void printTreeMenu();
void initialize(BinaryTree* &myBinaryTree, int argCount, char** args);
void cleanUp(BinaryTree* &myBinaryTree);
/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){

  int option;
  int printType;
  int elem;
  BinaryTree* myBinaryTree = new BinaryTree();

  //read from the file and initialize the BinaryTree
  initialize(myBinaryTree, argCount, args);
  printMenu();
  cin >> option;
  while(option != 7){
    switch(option){
    case 1:
      cout << "Enter element to be added: ";
      int newElement;
      cin >> newElement;
      myBinaryTree->addElem(newElement);
      cout << endl;
      break;
    case 2:
      // 2: deletes the last element
      cout << "deleting last element: " << myBinaryTree->deleteElem();
      break;
    case 3:
      //3: exists
      cout << "Enter element to be searched for: ";
      cin >> elem;
      (myBinaryTree->exists(elem) == true)
        ? cout << "Element found"
        : cout << "Could not find element";
      cout << endl;
      break;
    case 4:
      //4: sum
      cout << "Sum: " << myBinaryTree->sum();
      break;
    case 6:
      //4: print
      printTreeMenu();
      cin >> printType;
      myBinaryTree->print(printType);
      break;
    default:
      cout << "Invalid argument." << endl;
      break;
    }
    printMenu();
    cin >> option;
  }

  cleanUp(myBinaryTree);
  return 0;
}

/**
 * Prints the menu of choices to the user
 */
void printMenu(){
  cout << "\nPlease choose one of the following commands:" << endl;
  cout << "1: addElem" << endl;
  cout << "2: deleteElem" << endl;
  cout << "3: exists" << endl;
  cout << "4: sum all elements" << endl;
  cout << "6: print" << endl;
  cout << "7: exit" << endl;
  cout << ">> ";
  //Queue* BlooregardQueueKazoo = new Queue();
  // BlooregardQueueKazoo->enqueue(7);
  // cout << BlooregardQueueKazoo->peekFront();
  // BlooregardQueueKazoo->enqueue(5);
  // BlooregardQueueKazoo->dequeue();
  // cout << BlooregardQueueKazoo->peekFront();
}

void printTreeMenu(){
  cout << "Which traversal? " << endl;
  cout << "1: inorder traversal " << endl;
  cout << "2: preorder traversal " << endl;
  cout << "3: postorder traversal " << endl;
  cout << ">> ";
}


/**
 * Initializes the data structures and program environment
 */
void initialize(BinaryTree*  &myBinaryTree, int argCount, char** args){
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
        myBinaryTree->addElem(newElement);
      }
    }
    cout << "Done reading the file!" << endl;
    inputData.close();
}

/**
 * clean up all the space allocated on heap and environment variables if any
 */
void cleanUp(BinaryTree* &myBinaryTree){
  //IMPLEMENT ME
  delete myBinaryTree;
}
