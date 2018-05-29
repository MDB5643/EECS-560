#include "list.hpp"
#include "util.hpp"


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

void DoublyLinkedList::add(int elem, int position) {
  //IMPLEMENT ME
  if (position > listSize)
  {
    throw 0;
  }
  doubleNode* newNode =  new doubleNode(elem);
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
        tempFollow->setNext(newNode);
        temp->setPrevious(tempFollow->getNext());
        newNode->setPrevious(tempFollow);
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

void DoublyLinkedList::deleteAll(int elem) {
  doubleNode* temp = headPtr;
  doubleNode* tempFollow = nullptr;
  for (int i = 0; i < listSize; i++)
  {
    if (temp->getValue() == elem)
    {
      if (temp == headPtr)
      {
        headPtr = temp->getNext();
        temp->getNext()->setPrevious(nullptr);
        delete temp;
        listSize--;
      }
      else
      {
        if (temp->getNext() == nullptr)
        {
          tempFollow->setNext(temp->getNext());
          delete temp;
          listSize--;
        }
        else
        {
          temp->getNext()->setPrevious(tempFollow);
          tempFollow->setNext(temp->getNext());
          delete temp;
          listSize--;
        }
      }
    }
    tempFollow = temp;
    temp = temp->getNext();
  }
}

int DoublyLinkedList::find(int elem) {
  //IMPLEMENT ME
  doubleNode* temp = headPtr;
  int position = 0;

  while (temp != nullptr)
  {
    if (temp->getValue() == elem)
    {
      std::cout << elem << " is at index " << position << '\n';
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
  while (temp != nullptr)
  {
    std::cout << temp->getValue() << '\n';
    temp = temp->getNext();
  }
  //IMPLEMENT ME
}
