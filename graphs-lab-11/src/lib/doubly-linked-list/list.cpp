#include "lib/doubly-linked-list/list.hpp"
#include "util/util.hpp"

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
  }
}

bool DoublyLinkedList::isEmpty() {
  //IMPLEMENT ME
  if (headPtr == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
  return true;
}

int DoublyLinkedList::size(){
  //IMPLEMENT ME
  return listSize;
}

void DoublyLinkedList::add(int v1, int v2, int cost, int position) {
  if (position > listSize)
  {
    throw 0;
  }
  doubleNode* newNode =  new doubleNode(v1, v2, cost);
  doubleNode* temp = headPtr;
  if (headPtr == nullptr)
  {
    headPtr = newNode;
    listSize++;
  }
  else
  {
    doubleNode* tempFollow;
    for (int i = 0; i <= position; i++)
    {
      if (temp->getNext() == nullptr)
      {
        temp->setNext(newNode);
        newNode->setPrevious(temp);
        listSize++;
        return;
      }
      else if (i == position)
      {
        //temp->setPrevious(tempFollow->getNext());
        if (position == 0)
        {
          newNode->setPrevious( nullptr);
          temp->setPrevious(newNode);
          headPtr = newNode;
        }
        else
        {
          tempFollow->setNext(newNode);
          temp->setPrevious(tempFollow->getNext());
          newNode->setPrevious(tempFollow);
        }
        newNode->setNext(temp);
        listSize++;
      }
      else
      {
        tempFollow = temp;
        temp = temp->getNext();
      }

    }
  }
}

void DoublyLinkedList::deleteAll(Edge elem) {
  //IMPLEMENT ME
  IMPLEMENT_ME();
}

int DoublyLinkedList::find(Edge elem) {
  doubleNode* temp = headPtr;
  int position = 0;

  while (temp != nullptr)
  {
    if (temp->ve1 == elem.getV1() && temp->ve2 == elem.getV2())
    {
      std::cout << "The edge you're looking for is at index " << position << '\n';
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
  IMPLEMENT_ME();
  //IMPLEMENT ME
}
