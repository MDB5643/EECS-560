#include <iostream>
#include <fstream>

#include "util/util.hpp"

using namespace std;

int main(int argc, char** argv){
  fstream inputData;

  if(argc < 2){
    cout << "No input file given, using default test/hl-data.txt" << endl;
    inputData.open("test/hl-data.txt", ifstream::in);
  } else {
    cout << "Using data from " << argv[1] << endl;
    inputData.open(argv[1], ifstream::in);
  }

  // How can you use the graph data structre you have implemented to
  // find minimum number of roads to connect all the areas with minumum cost?
  IMPLEMENT_ME();

  cout << "Roads: " <<  endl;
  cout << "Total Cost: " << endl;

  inputData.close();

  return 0;
}
