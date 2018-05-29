#include <iostream>
#include <fstream>

#include "util.hpp"
#include "bst.hpp"

using namespace std;

void printMenu();
void printTreeMenu();
void initialize(BST* &myBST, int argCount, char** args);
void cleanUp(BST* &myBST);
/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){
    int option;
    int printTreeOption;
    int elem;
    BST* myBST = nullptr;

    //read from the file and initialize the BST
    initialize(myBST, argCount, args);
    printMenu();
    cin >> option;
    while(option != 6){
	switch(option){
	case 1:
	    cout << "Enter element to be added: ";
	    int newElement;
	    cin >> newElement;
	    myBST->addElem(newElement);
	    cout << endl;
	    break;
	case 2:
	    // 2: delete
	    cout << "Enter element to be deleted: ";
	    cin >> elem;
	    myBST->deleteElem(elem);
	    break;
	case 3:
	    //3: exists
	    cout << "Enter element to be checked for existence: ";
	    cin >> elem;
	    (myBST->exists(elem) == true)
		? cout << "Element found"
		: cout << "Could not find element";
	    cout << endl;
	    break;
	case 4:
	    //4: height
	    cout << "Height of the tree is: " << myBST->height() << endl;
	    break;
	case 5:
	    //5: print
	    printTreeMenu();
	    cin >> printTreeOption;
	    myBST->print(printTreeOption);
	    break;
	default:
	    cout << "Invalid argument." << endl;
	    break;
	}
	printMenu();
	cin >> option;
    }

  cleanUp(myBST);
  return 0;
}

/**
 * Prints the menu of choices to the user
 */
void printMenu(){
    cout << "Please choose one of the following commands:" << endl;
    cout << "1: add" << endl;
    cout << "2: delete" << endl;
    cout << "3: exists" << endl;
    cout << "4: height" << endl;
    cout << "5: print" << endl;
    cout << "6: exit" << endl;
    cout << ">> ";
}

void printTreeMenu(){
    cout << "Please choose traversal option for printing:" << endl;
    cout << "1: inorder traversal " << endl;
    cout << "2: preorder traversal " << endl;
    cout << "3: postorder traversal " << endl;
    cout << "4: levelorder traversal " << endl;
    cout << ">> ";
}

/**
 * Initializes the data structures and program environment
 */
void initialize(BST*  &myBST, int argCount, char** args){
    fstream inputData;
    if(argCount < 2){
      cout << "No input file given, using default data.txt" << endl;
      inputData.open("data.txt", ifstream::in);
    } else {
      cout << "Using data from " << args[1] << endl;
      inputData.open(args[1], ifstream::in);
    }
    myBST = new BST();
    while(!inputData.eof()){
      int newElement;
      inputData >> newElement;
      if(inputData.good()){
        myBST->addElem(newElement);
      }
    }
    inputData.close();
}

/**
 * clean up all the space allocated on heap and environment variables if any
 */
void cleanUp(BST* &myBST){
  //IMPLEMENT ME
  delete myBST;
}
