#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#define LIST_SIZE 10000
#define HEAP_ARRAY_SIZE 15000

using namespace std;

int bounded_random_generator(){
  return (rand() % LIST_SIZE);
}

int  main() {
  fstream wordListFile;
  string* wordList = new string[LIST_SIZE];
  string* heapArray = new string[HEAP_ARRAY_SIZE];

  wordListFile.open("word-list.txt", fstream::in);
  for(int i = 0; i < LIST_SIZE; i++){
    wordListFile >> wordList[i];
  }
  wordListFile.close();

  //fix the random number generator seed for reproducable results
  srand(157341);

  cout << "generating some random words for demo" << endl;
  cout << "----------------------------" << endl;
  for(int i = 0; i < HEAP_ARRAY_SIZE; i++){
    heapArray[i] = wordList[bounded_random_generator()];
    cout << heapArray[i] << " ";
  }

  delete[] wordList;
  delete[] heapArray;
  return 0;
}

