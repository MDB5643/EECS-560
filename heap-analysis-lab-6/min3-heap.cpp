#include "min3-heap.hpp"
#include "util.hpp"
#include <string>


//////////////////////////////////
// Private Functions Definition //
//////////////////////////////////
void Min3Heap::buildHeap(){
  int placedIndex = numItemsInHeap - 1;
  if (placedIndex <= 0)
  {
    //cout << "No need to bubble" << endl;
    return;
  }

  while (ArrayghtArrayghtArrayght[(placedIndex - 1) / 3] > ArrayghtArrayghtArrayght[placedIndex])
  {
    //std::cout << "adding...";
    //cout << "Bubbling index " << (placedIndex - 1) / 2 << " against index " << placedIndex << endl;
    std::string temp = ArrayghtArrayghtArrayght[(placedIndex - 1) / 3];
    ArrayghtArrayghtArrayght[(placedIndex - 1) / 3] = ArrayghtArrayghtArrayght[placedIndex];
    ArrayghtArrayghtArrayght[placedIndex] = temp;
    placedIndex = (placedIndex - 1) / 3;
  }
}

/////////////////////////////////
// Public functions definition //
/////////////////////////////////

Min3Heap::Min3Heap(){

  heapArray = new std::string[15000];
  heapSize = 10000;
  numItemsInHeap = 0;
  ArrayghtArrayghtArrayght = new std::string[heapSize];


}

Min3Heap::Min3Heap(std::string *inString, int passSize){

  deepBlueCopy = new std::string[heapSize];
  ArrayghtArrayghtArrayght = new std::string[heapSize];
  for(int j = 0; j < passSize; j++)
  {
    deepBlueCopy[j] = inString[j];
  }



  for(int i = 0; i < passSize; i++)
  {
    addElem(inString[i]);
  }
}


Min3Heap::~Min3Heap() {
  delete[] ArrayghtArrayghtArrayght;
}

void Min3Heap::addElem(std::string elem) {
  // if (numItemsInHeap >= heapSize)
  // {
  //   std::cout << "The queue has been maxed out. A new, larger queue is being made.\n";
  //   heapSize = 2*heapSize;
  //   std::string* newarr = new std::string[heapSize];
  //   for (int i = 0; i < numItemsInHeap; i++)
  //   {
  //     newarr[i] = ArrayghtArrayghtArrayght[i];
  //   }
  //   delete[] ArrayghtArrayghtArrayght;
  //   ArrayghtArrayghtArrayght = newarr;
  // }

    ArrayghtArrayghtArrayght[numItemsInHeap] = elem;
    //std::cout << "made it here now" << std::endl;
    numItemsInHeap++;
    // 0 1 2 3 4 5 6 7 8
    buildHeap();

}

void Min3Heap::deleteElem(std::string elem) {
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] == elem)
    {
      numItemsInHeap--;
      ArrayghtArrayghtArrayght[i] = ArrayghtArrayghtArrayght[numItemsInHeap];
      int bubbleDown = i;
      int child1Index = i * 3 + 1;
      int child2Index = i * 3 + 2;
      int child3Index = i * 3 + 3;
      while(child1Index < numItemsInHeap)
      {
        //printTree();

        int minimalIndex = bubbleDown;
        if (ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child1Index])
        {
          minimalIndex = child1Index;
        }

        if (ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child2Index])
        {
          minimalIndex = child2Index;
        }

        if (child3Index > numItemsInHeap && ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child3Index])
        {
          minimalIndex = child3Index;
        }

        if (minimalIndex != bubbleDown)
        {
          //cout << "Swapping index " << minimalIndex << "(" << ArrayghtArrayghtArrayght[minimalIndex]
          //	 << ") with index " << bubbleDown << "(" << ArrayghtArrayghtArrayght[bubbleDown] << ")" << endl;
          std::string temp = ArrayghtArrayghtArrayght[bubbleDown];
          ArrayghtArrayghtArrayght[bubbleDown] = ArrayghtArrayghtArrayght[minimalIndex];
          ArrayghtArrayghtArrayght[minimalIndex] = temp;
          bubbleDown = minimalIndex;
          child1Index = bubbleDown * 3 + 1;
          child2Index = bubbleDown * 3 + 2;
          child3Index = bubbleDown * 3 + 3;
        }
        else
        {
          //cout << "Bigger than both children" << endl;
          break;
        }
      }
    }
  }
}

bool Min3Heap::exists(std::string elem){
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] == elem)
    {
      return true;
    }
  }
  return false;
}

std::string Min3Heap::deleteMinElem(){
  std::string temp;
  std::string toDelete = ArrayghtArrayghtArrayght[0];
  numItemsInHeap--;
  ArrayghtArrayghtArrayght[0] = ArrayghtArrayghtArrayght[numItemsInHeap];
  int bubbleDown = 0;
  int child1Index = 1;
  int child2Index = 2;
  int child3Index = 3;
  while(child1Index < numItemsInHeap)
  {
    //printTree();

    int minimalIndex = bubbleDown;
    if (ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child1Index])
    {
      minimalIndex = child1Index;
    }

    if (ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child2Index])
    {
      minimalIndex = child2Index;
    }

    if (child3Index > numItemsInHeap && ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child3Index])
    {
      minimalIndex = child3Index;
    }

    if (minimalIndex != bubbleDown)
    {
      //cout << "Swapping index " << minimalIndex << "(" << ArrayghtArrayghtArrayght[minimalIndex]
      //	 << ") with index " << bubbleDown << "(" << ArrayghtArrayghtArrayght[bubbleDown] << ")" << endl;
      temp = ArrayghtArrayghtArrayght[bubbleDown];
      ArrayghtArrayghtArrayght[bubbleDown] = ArrayghtArrayghtArrayght[minimalIndex];
      ArrayghtArrayghtArrayght[minimalIndex] = temp;
      bubbleDown = minimalIndex;
      child1Index = bubbleDown * 3 + 1;
      child2Index = bubbleDown * 3 + 2;
      child3Index = bubbleDown * 3 + 3;
    }
    else
    {
      //cout << "Bigger than both children" << endl;
      break;
    }
  }
  //printTree();

  return toDelete;
}

std::string Min3Heap::deleteMaxElem(){
  std::string maxElem = ArrayghtArrayghtArrayght[0];
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] > maxElem)
    {
      maxElem = ArrayghtArrayghtArrayght[i];
    }
  }
  deleteElem(maxElem);
  return maxElem;
}


void Min3Heap::levelOrderPrint(){
  for (int i = 0; i < numItemsInHeap; i++)
  {
    std::cout << ArrayghtArrayghtArrayght[i] << std::endl;
  }
}
