#include "minmax-heap.hpp"
#include "../util/util.hpp"


//////////////////////////////////
// Private Functions Definition //
//////////////////////////////////
void MinMaxHeap::buildHeap(){
  int placedIndex = numItemsInHeap - 1;

  if (numItemsInHeap > curr)
  {
    if(atMinLevel == false)
    {
      atMinLevel = true;
    }
    else
    {
      atMinLevel = false;
    }
    interval = interval*2;
    curr = (numItemsInHeap-1) + interval;
  }

  if (placedIndex <= 0)
  {
    //cout << "No need to bubble" << endl;
    return;
  }

  if (placedIndex == 0)
  {

  }

  else if (atMinLevel == false)
  {
    if (ArrayghtArrayghtArrayght[(placedIndex - 1) / 2] > ArrayghtArrayghtArrayght[placedIndex])
    {
      std::string temp = ArrayghtArrayghtArrayght[(placedIndex - 1) / 2];
      ArrayghtArrayghtArrayght[(placedIndex - 1) / 2] = ArrayghtArrayghtArrayght[placedIndex];
      ArrayghtArrayghtArrayght[placedIndex] = temp;
      int newPlace = (placedIndex - 1) / 2;
      if (numItemsInHeap >= 8)
      {
        if (ArrayghtArrayghtArrayght[(((newPlace - 1) / 2) - 1) / 2] > ArrayghtArrayghtArrayght[newPlace])
        {
          //std::cout << "adding...";
          //cout << "Bubbling index " << (placedIndex - 1) / 2 << " against index " << placedIndex << endl;
          std::string temp = ArrayghtArrayghtArrayght[((((newPlace - 1) / 2) - 1) / 2)];
          ArrayghtArrayghtArrayght[((((newPlace - 1) / 2) - 1) / 2)] = ArrayghtArrayghtArrayght[newPlace];
          ArrayghtArrayghtArrayght[newPlace] = temp;
          newPlace = ((((newPlace - 1) / 2) - 1) / 2);
        }
      }
     }
    // else if (ArrayghtArrayghtArrayght[(((placedIndex - 1) / 2) - 1) / 2] < ArrayghtArrayghtArrayght[placedIndex])
    // {
    //   if (numItemsInHeap >= 8)
    //   {
    //     std::string temp = ArrayghtArrayghtArrayght[(((placedIndex - 1) / 2) - 1) / 2];
    //     ArrayghtArrayghtArrayght[(((placedIndex - 1) / 2) - 1) / 2] = ArrayghtArrayghtArrayght[placedIndex];
    //     ArrayghtArrayghtArrayght[placedIndex] = temp;
    //   }
    // }

  }

  else
  {
    if (ArrayghtArrayghtArrayght[(placedIndex - 1) / 2] < ArrayghtArrayghtArrayght[placedIndex])
    {
      std::string temp = ArrayghtArrayghtArrayght[(placedIndex - 1) / 2];
      ArrayghtArrayghtArrayght[(placedIndex - 1) / 2] = ArrayghtArrayghtArrayght[placedIndex];
      ArrayghtArrayghtArrayght[placedIndex] = temp;
      int newPlace = (placedIndex - 1) / 2;
      if (numItemsInHeap >= 4)
      {
        if (ArrayghtArrayghtArrayght[(((newPlace - 1) / 2) - 1) / 2] < ArrayghtArrayghtArrayght[newPlace])
        {
            //std::cout << "adding...";
            //cout << "Bubbling index " << (placedIndex - 1) / 2 << " against index " << placedIndex << endl;
            std::string temp = ArrayghtArrayghtArrayght[((((newPlace - 1) / 2) - 1) / 2)];
            ArrayghtArrayghtArrayght[((((newPlace - 1) / 2) - 1) / 2)] = ArrayghtArrayghtArrayght[newPlace];
            ArrayghtArrayghtArrayght[newPlace] = temp;
            newPlace = ((((newPlace - 1) / 2) - 1) / 2);
        }
      }


    }
    // else if (ArrayghtArrayghtArrayght[(((placedIndex - 1) / 2) - 1) / 2] > ArrayghtArrayghtArrayght[placedIndex])
    // {
    //   if (numItemsInHeap >= 4)
    //   {
    //     std::string temp = ArrayghtArrayghtArrayght[(((placedIndex - 1) / 2) - 1) / 2];
    //     ArrayghtArrayghtArrayght[(((placedIndex - 1) / 2) - 1) / 2] = ArrayghtArrayghtArrayght[placedIndex];
    //     ArrayghtArrayghtArrayght[placedIndex] = temp;
    //   }
    // }

  }


}

/////////////////////////////////
// Public functions definition //
/////////////////////////////////

MinMaxHeap::MinMaxHeap(){
  heapArray = new std::string[15000];
  heapSize = 10000;
  numItemsInHeap = 0;
  ArrayghtArrayghtArrayght = new std::string[heapSize];
}

MinMaxHeap::MinMaxHeap(std::string * elems, int size){
  interval = 1;
  curr = 1;
  atMinLevel = true;
  deepBlueCopy = new std::string[heapSize];
  ArrayghtArrayghtArrayght = new std::string[heapSize];
  for(int j = 0; j < size; j++)
  {
    deepBlueCopy[j] = elems[j];
  }



  for(int i = 0; i < size; i++)
  {
    addElem(elems[i]);
  }
}

MinMaxHeap::~MinMaxHeap() {
  delete[] ArrayghtArrayghtArrayght;
}

void MinMaxHeap::addElem(std::string elem) {
  ArrayghtArrayghtArrayght[numItemsInHeap] = elem;

  numItemsInHeap++;

  buildHeap();
}

void MinMaxHeap::deleteElem(std::string elem) {
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] == elem)
    {
      numItemsInHeap--;
      ArrayghtArrayghtArrayght[i] = ArrayghtArrayghtArrayght[numItemsInHeap];
      int bubbleDown = i;
      int child1Index = i * 2 + 1;
      int child2Index = i * 2 + 2;

      while(child1Index < numItemsInHeap)
      {
        //printTree();

        int minimalIndex = bubbleDown;
        if (ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child1Index])
        {
          minimalIndex = child1Index;
        }

        if (child2Index > numItemsInHeap && ArrayghtArrayghtArrayght[minimalIndex] > ArrayghtArrayghtArrayght[child2Index])
        {
          minimalIndex = child2Index;
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

int MinMaxHeap::size(){
  return numItemsInHeap;
}

bool MinMaxHeap::exists(std::string elem){
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] == elem)
    {
      return true;
    }
  }
  return false;
  return false;
}

std::string MinMaxHeap::deleteMinElem(){
  std::string min = ArrayghtArrayghtArrayght[0];
  deleteElem(ArrayghtArrayghtArrayght[0]);
  return min;
}

std::string MinMaxHeap::deleteMaxElem(){
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

void MinMaxHeap::levelOrderPrint(){
  for (int i = 0; i < numItemsInHeap; i++)
  {
    std::cout << ArrayghtArrayghtArrayght[i] << std::endl;
  }
}
