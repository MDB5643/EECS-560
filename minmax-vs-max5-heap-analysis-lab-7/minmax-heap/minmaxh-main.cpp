#include <iostream>
#include <fstream>
#include <string>

#include "../util/util.hpp"
#include "minmax-heap.hpp"

////////////////////////////////////////
// You may not change this main file. //
// You can create a new main file for //
// your debugging purposes            //
////////////////////////////////////////

using namespace std;

void printMenu();
void initialize(MinMaxHeap* &myMinMaxHeap, int argCount, char** args);
void cleanUp(MinMaxHeap* &myMinMaxHeap);

/**
 * This is the main entry point for the application
 * if you want to use your own custom datafile you'd have to pass that
 * as an argument to the function.
 * i.e. ./main mytest.txt
 */
int main(int argCount, char** args){
    int option;
    string elem;
    MinMaxHeap* myMinMaxHeap = nullptr;

    //read from the file and initialize the MinMaxHeap
    initialize(myMinMaxHeap, argCount, args);
    printMenu();
    cin >> option;
    while(option != 7){
	switch(option){
	case 1:
	    cout << "Enter element to be added: ";
	    cin >> elem;
	    myMinMaxHeap->addElem(elem);
	    cout << endl;
	    break;
	case 2:
	    // 2: delete
	    cout << "Enter element to be deleted: ";
	    cin >> elem;
	    myMinMaxHeap->deleteElem(elem);
	    break;
	case 3:
	    //3: exists
	    cout << "Enter element to be checked for existence: ";
	    cin >> elem;
	    (myMinMaxHeap->exists(elem) == true)
		? cout << "Element exists"
		: cout << "Element does not exist";
	    cout << endl;
	    break;
	case 4:
	    //4: delete min
	    cout << "Deleted min element: " << myMinMaxHeap->deleteMinElem();
	    break;
        case 5:
            //5: delete max
	    cout << "Deleted max element: " << myMinMaxHeap->deleteMaxElem();
	    break;
	case 6:
	    //6: print tree in level order traversal
            cout << "Printing heap:" << endl;
            myMinMaxHeap->levelOrderPrint();
	    break;
	default:
	    cout << "Invalid argument." << endl;
	    break;
	}
	printMenu();
	cin >> option;
    }

  cleanUp(myMinMaxHeap);
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
void initialize(MinMaxHeap*  &myMinMaxHeap, int argCount, char** args){
    fstream inputData;
    int elemCount = 0;

    if(argCount < 2){
      cout << "No input file given, using default minmaxh-data.txt" << endl;
      inputData.open("out/minmaxh-data.txt", ifstream::in);
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
    myMinMaxHeap = new MinMaxHeap(inputDataArr, elemCount);
    delete[] inputDataArr;
    inputDataArr = nullptr;
}

/**
 * clean up all the space allocated on heap and environment variables if any
 */
void cleanUp(MinMaxHeap* &myMinMaxHeap){
  //IMPLEMENT ME
  delete myMinMaxHeap;
}
