#include "max5-heap.hpp"
#include "../util/util.hpp"


//////////////////////////////////
// Private Functions Definition //
//////////////////////////////////
void Max5Heap::buildHeap(){
  int placedIndex = numItemsInHeap-1;
  if (placedIndex <= 0)
  {
    //cout << "No need to bubble" << endl;
    return;
  }

  // for (int i = placedIndex; i >= 0; i--)
  // {
  //   int k = i;
  //   std::string v = ArrayghtArrayghtArrayght[k];
  //   bool heap = false;
  //   while (heap == false && 5*k <= numItemsInHeap-1)
  //   {
  //     int j = 5*k;
  //     if (j < numItemsInHeap)
  //     {
  //       if (ArrayghtArrayghtArrayght[j] < ArrayghtArrayghtArrayght[j+1])
  //       {
  //         j = j + 1;
  //         if (ArrayghtArrayghtArrayght[j] < ArrayghtArrayghtArrayght[j+1])
  //         {
  //           j = j + 1;
  //           if (ArrayghtArrayghtArrayght[j] < ArrayghtArrayghtArrayght[j+1])
  //           {
  //             j = j + 1;
  //             if (ArrayghtArrayghtArrayght[j] < ArrayghtArrayghtArrayght[j+1])
  //             {
  //               j = j + 1;
  //             }
  //           }
  //         }
  //
  //       }
  //     }
  //       if (v >= ArrayghtArrayghtArrayght[j])
  //       {
  //         heap = true;
  //       }
  //       else
  //       {
  //         ArrayghtArrayghtArrayght[k] = ArrayghtArrayghtArrayght[j];
  //         k = j;
  //       }
  //
  //
  //   }
  //   ArrayghtArrayghtArrayght[k] = v;
  // }

  while (ArrayghtArrayghtArrayght[(placedIndex - 1) / 5] < ArrayghtArrayghtArrayght[placedIndex])
  {
    //std::cout << "adding...";
    //cout << "Bubbling index " << (placedIndex - 1) / 2 << " against index " << placedIndex << endl;
    std::string temp = ArrayghtArrayghtArrayght[(placedIndex - 1) / 5];
    ArrayghtArrayghtArrayght[(placedIndex - 1) / 5] = ArrayghtArrayghtArrayght[placedIndex];
    ArrayghtArrayghtArrayght[placedIndex] = temp;
    placedIndex = (placedIndex - 1) / 5;
  }

}

/////////////////////////////////
// Public functions definition //
/////////////////////////////////

Max5Heap::Max5Heap(){
  heapArray = new std::string[15000];
  heapSize = 10000;
  numItemsInHeap = 0;
  ArrayghtArrayghtArrayght = new std::string[heapSize];
}

Max5Heap::Max5Heap(std::string * elems, int size){
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

Max5Heap::~Max5Heap() {
  delete[] ArrayghtArrayghtArrayght;
}

void Max5Heap::addElem(std::string elem) {
  ArrayghtArrayghtArrayght[numItemsInHeap] = elem;
  //std::cout << "made it here now" << std::endl;
  numItemsInHeap++;
  // 0 1 2 3 4 5 6 7 8
  buildHeap();

}

void Max5Heap::deleteElem(std::string elem) {
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] == elem)
    {
      numItemsInHeap--;
      ArrayghtArrayghtArrayght[i] = ArrayghtArrayghtArrayght[numItemsInHeap];
      int bubbleDown = i;
      int child1Index = i * 5 + 1;
      int child2Index = i * 5 + 2;
      int child3Index = i * 5 + 3;
      int child4index = i * 5 + 4;
      int child5index = i * 5 + 5;
      while(child1Index < numItemsInHeap)
      {
        //printTree();

        int minimalIndex = bubbleDown;
        if (ArrayghtArrayghtArrayght[minimalIndex] < ArrayghtArrayghtArrayght[child1Index])
        {
          minimalIndex = child1Index;
        }

        if (ArrayghtArrayghtArrayght[minimalIndex] < ArrayghtArrayghtArrayght[child2Index])
        {
          minimalIndex = child2Index;
        }

        if (ArrayghtArrayghtArrayght[minimalIndex] < ArrayghtArrayghtArrayght[child3Index])
        {
          minimalIndex = child3Index;
        }

        if (ArrayghtArrayghtArrayght[minimalIndex] < ArrayghtArrayghtArrayght[child4index])
        {
          minimalIndex = child4index;
        }

        if (child5index < numItemsInHeap && ArrayghtArrayghtArrayght[minimalIndex] < ArrayghtArrayghtArrayght[child5index])
        {
          minimalIndex = child5index;
        }

        if (minimalIndex != bubbleDown)
        {
          //cout << "Swapping index " << minimalIndex << "(" << ArrayghtArrayghtArrayght[minimalIndex]
          //	 << ") with index " << bubbleDown << "(" << ArrayghtArrayghtArrayght[bubbleDown] << ")" << endl;
          std::string temp = ArrayghtArrayghtArrayght[bubbleDown];
          ArrayghtArrayghtArrayght[bubbleDown] = ArrayghtArrayghtArrayght[minimalIndex];
          ArrayghtArrayghtArrayght[minimalIndex] = temp;
          bubbleDown = minimalIndex;
          child1Index = bubbleDown * 5 + 1;
          child2Index = bubbleDown * 5 + 2;
          child3Index = bubbleDown * 5 + 3;
          child4index = bubbleDown * 5 + 4;
          child5index = bubbleDown * 5 + 5;
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

int Max5Heap::size(){
  return numItemsInHeap;
}

bool Max5Heap::exists(std::string elem){
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] == elem)
    {
      return true;
    }
  }
  return false;
}

std::string Max5Heap::deleteMinElem(){
  std::string minElem = ArrayghtArrayghtArrayght[0];
  for (int i = 0; i < numItemsInHeap; i++)
  {
    if (ArrayghtArrayghtArrayght[i] < minElem)
    {
      minElem = ArrayghtArrayghtArrayght[i];
    }
  }
  deleteElem(minElem);
  return minElem;
}

std::string Max5Heap::deleteMaxElem(){


  deleteElem(ArrayghtArrayghtArrayght[0]);
  return "";
}

void Max5Heap::levelOrderPrint(){
  for (int i = 0; i < numItemsInHeap; i++)
  {
    std::cout << ArrayghtArrayghtArrayght[i] << std::endl;
  }
}
