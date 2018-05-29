#include <iostream>
#include <fstream>
#include <string>

#include "util.hpp"
#include "min3-heap.hpp"

////////////////////////////////////////
// You may not change this main file. //
// You can create a new main file for //
// your debugging purposes            //
////////////////////////////////////////

using namespace std;

void printMenu();
void initialize(Min3Heap* &myMin3Heap, int argCount, char** args);
void cleanUp(Min3Heap* &myMin3Heap);

/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){
    int option;
    string elem;
    Min3Heap* myMin3Heap = nullptr;

    //read from the file and initialize the Min3Heap
    initialize(myMin3Heap, argCount, args);
    printMenu();
    cin >> option;
    while(option != 7){
	switch(option){
	case 1:
	    cout << "Enter element to be added: ";
	    cin >> elem;
	    myMin3Heap->addElem(elem);
	    cout << endl;
	    break;
	case 2:
	    // 2: delete
	    cout << "Enter element to be deleted: ";
	    cin >> elem;
	    myMin3Heap->deleteElem(elem);
	    break;
	case 3:
	    //3: exists
	    cout << "Enter element to be checked for existence: ";
	    cin >> elem;
	    (myMin3Heap->exists(elem) == true)
		? cout << "Element found"
		: cout << "Could not find element";
	    cout << endl;
	    break;
	case 4:
	    //4: delete min
	    cout << "Deleted min element: " << myMin3Heap->deleteMinElem() << endl;
	    break;
        case 5:
            //5: delete max
	    cout << "Deleted max element: " << myMin3Heap->deleteMaxElem() << endl;
	    break;
	case 6:
	    //6: print tree in level order traversal
            cout << "Printing heap:" << endl;
            myMin3Heap->levelOrderPrint();
	    break;
	default:
	    cout << "Invalid argument." << endl;
	    break;
	}
	printMenu();
	cin >> option;
    }

  cleanUp(myMin3Heap);
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
    cout << "4: delete min" << endl;
    cout << "5: delete max" << endl;
    cout << "6: print level order" << endl;
    cout << "7: exit" << endl;
    cout << ">> ";
}

/**
 * Initializes the data structures and program environment
 */
void initialize(Min3Heap*  &myMin3Heap, int argCount, char** args){
    fstream inputData;
    int elemCount = 0;

    if(argCount < 2){
      cout << "No input file given, using default data.txt" << endl;
      inputData.open("data.txt", ifstream::in);
    } else {
      cout << "Using data from " << args[1] << endl;
      inputData.open(args[1], ifstream::in);
    }
    inputData >> elemCount;
    string* inputDataArr = new string[elemCount];

    for(int i = 0; i < elemCount; i++){
      inputData >> inputDataArr[i];
    }
    inputData.close();

    //CAUTION: ensure you deep copy inputDataArr inside your constructor
    myMin3Heap = new Min3Heap(inputDataArr, elemCount);
    delete[] inputDataArr;
    inputDataArr = nullptr;
}

/**
 * clean up all the space allocated on heap and environment variables if any
 */
void cleanUp(Min3Heap* &myMin3Heap){
  //IMPLEMENT ME
  delete myMin3Heap;
}
