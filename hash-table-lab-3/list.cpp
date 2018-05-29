#include "list.hpp"
//#include "util.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
  //IMPLEMENT ME
  headPtr = nullptr;
  tailPtr = nullptr;
  listSize = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
  doubleNode* temp = headPtr;
  while (headPtr != nullptr)
  {
    headPtr = headPtr->getNext();
    delete temp;
    temp = headPtr;
    listSize--;
  }
}

bool DoublyLinkedList::isEmpty() {

  if (headPtr == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int DoublyLinkedList::size(){
  //IMPLEMENT ME
  return listSize;
}

void DoublyLinkedList::add(string elem) {
  //IMPLEMENT ME
  // if (position > listSize)
  // {
  //   throw 0;
  // }
  doubleNode* newNode =  new doubleNode(elem);
  doubleNode* temp = headPtr;
  if (headPtr == nullptr)
  {
    headPtr = newNode;
    listSize++;
  }
  else
  {
    //doubleNode* tempFollow;
    // for (int i = 0; i <= position; i++)
    // {
      if (temp->getNext() == nullptr)
      {
        temp->setNext(newNode);
        newNode->setPrevious(temp);
        listSize++;
        return;
      }
      // else if (i == position)
      // {
      //   //temp->setPrevious(tempFollow->getNext());
      //   if (position == 0)
      //   {
      //     newNode->setPrevious( nullptr);
      //     temp->setPrevious(newNode);
      //     headPtr = newNode;
      //   }
      //   else
      //   {
      //     tempFollow->setNext(newNode);
      //     temp->setPrevious(tempFollow->getNext());
      //     newNode->setPrevious(tempFollow);
      //   }
      //   newNode->setNext(temp);
      //   listSize++;
      // }
      else
      {
        //tempFollow = temp;
        temp = temp->getNext();
      }

    }

}

bool DoublyLinkedList::deleteAll(string elem) {
  doubleNode* temp = headPtr;
  doubleNode* tempFollow = nullptr;
  for (int i = 0; i < listSize; i++)
  {
    if (temp->getValue() == elem)
    {
      if (temp == headPtr)
      {
        headPtr = temp->getNext();
        temp->setPrevious(nullptr);
        delete temp;
        listSize--;
        return true;
      }
      else
      {
        if (temp->getNext() == nullptr)
        {
          tempFollow->setNext(temp->getNext());
          delete temp;
          listSize--;
          return true;
        }
        else
        {
          temp->getNext()->setPrevious(tempFollow);
          tempFollow->setNext(temp->getNext());
          delete temp;
          listSize--;
          return true;
        }
      }
    }
    tempFollow = temp;
    temp = temp->getNext();
  }
  return false;
}

int DoublyLinkedList::find(string elem) {
  //IMPLEMENT ME
  doubleNode* temp = headPtr;
  int position = 0;

  while (temp != nullptr)
  {
    if (temp->getValue() == elem)
    {
      //std::cout << elem << " is at index " << position << '\n';
      return position;
    }
    else
    {
      temp = temp->getNext();
      position++;
    }

  }
  return -1;
}

void DoublyLinkedList::print() {
  doubleNode* temp = headPtr;
  for (int i = 0; i < listSize; i++)
  {
    std::cout << "\"" << temp->getValue() << "\"";
    temp = temp->getNext();
  }
  //IMPLEMENT ME
}

// DoublyLinkedList* DoublyLinkedList::getPositionList(DoublyLinkedList* argList)
// {
//   DoublyLinkedList* posList = new DoublyLinkedList;
//   doubleNode* temp = argList->headPtr;
//
//   while (temp != nullptr)
//   {
//     //std::cout << "here" << std::endl;
//     posList->add(find(temp->getValue()), posList->listSize);
//     temp = temp->getNext();
//   }
//   delete temp;
//   return posList;
// }

doubleNode* DoublyLinkedList::getHeadPtr()
{
  return headPtr;
}


//overloaded add method for matrices

// void DoublyLinkedList::add(int elem, int coordi, int coordj, int position) {
//   //IMPLEMENT ME
//   // if (position > listSize)
//   // {
//   //   throw 0;
//   // }
//   doubleNode* newNode =  new doubleNode(elem);
//   doubleNode* temp = headPtr;
//   //newNode->setMatrixVal(elem);
//   newNode->setRowSpot(coordi);
//   newNode->setColumnSpot(coordj);
//   if (headPtr == nullptr)
//   {
//     headPtr = newNode;
//     listSize++;
//   }
//   else
//   {
//     doubleNode* tempFollow;
//     for (int i = 0; i <= listSize; i++)
//     {
//       if (temp->getNext() == nullptr)
//       {
//         temp->setNext(newNode);
//         newNode->setPrevious(temp);
//         listSize++;
//       //  std::cout << "Added " << newNode->getValue() << " to (" << newNode->getRowSpot() << ", " << newNode->getColumnSpot() << ")" << std::endl;
//         return;
//       }
//       else if (i == position)
//       {
//         //temp->setPrevious(tempFollow->getNext());
//         if (position == 0)
//         {
//           newNode->setPrevious( nullptr);
//           temp->setPrevious(newNode);
//           headPtr = newNode;
//         }
//         else
//         {
//           tempFollow->setNext(newNode);
//           temp->setPrevious(tempFollow->getNext());
//           newNode->setPrevious(tempFollow);
//         }
//         newNode->setNext(temp);
//         listSize++;
//         std::cout << "Added " << newNode->getValue() << " to (" << newNode->getRowSpot() << ", " << newNode->getColumnSpot() << ")" << std::endl;
//         return;
//       }
//       else
//       {
//         tempFollow = temp;
//         temp = temp->getNext();
//       }
//
//     }
//   }
// }

bool DoublyLinkedList::equals(const DoublyLinkedList* that){
  bool found;
  doubleNode* temp = this->headPtr;
  while(temp != nullptr)
  {
    doubleNode* temp2 = that->headPtr;
    for(int i = 0; i < that->listSize; i++)
    {
      std::cout << "";
      if (temp2->getValue() == temp->getValue() && temp2->getRowSpot() == temp->getRowSpot() && temp2->getColumnSpot() == temp->getColumnSpot())
      {
        found = true;
        break;
      }
      else
      {
        //std::cout << "whatever" << std::endl;

        temp2 = temp2->getNext();
      }
    }
    //std::cout << "escaped" << std::endl;
    if (found == true)
    {
      temp = temp->getNext();
    }
    else
    {
      return false;
    }
  }
  return false;
}

// DoublyLinkedList* DoublyLinkedList::transpose(DoublyLinkedList* argList)
// {
//   //int counter = 0;
//   int newI;
//   int newJ;
//   doubleNode* temp = argList->headPtr;
//   DoublyLinkedList* newList = new DoublyLinkedList();
//   std::cout << "" << std::endl;
//   for (int i = 0; i < argList->listSize; i++)
//   {
//     newI = temp->getColumnSpot();
//     newJ = temp->getRowSpot();
//     newList->add(temp->getValue(), newI, newJ, newList->listSize);
//     temp = temp->getNext();
//     //counter++;
//   }
//   return newList;
// }
