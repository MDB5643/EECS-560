
#include "binary-tree.hpp"
#include "util.hpp"


BinaryTree::BinaryTree()
{
  m_root = nullptr;
  m_size = 0;
  m_sum = 0;
  //Queue* BlooregardQueueKazoo = new Queue();
}

BinaryTree::~BinaryTree() {
  while(m_size != 1)
  {
    deleteElem();
  }
}

void BinaryTree::addRecursive(int elem, BinaryNode* curr)
{
  BinaryNode* newBinaryNode = new BinaryNode();
  newBinaryNode->setVal(elem);
  if (m_root == nullptr)
  {
    m_root = newBinaryNode;
    BlooregardQueueKazoo.enqueue(elem);
    ImmortalQueue.enqueue(elem);
    m_size++;
    m_sum = m_sum + elem;
    cout << "Added " << elem << " to root" << endl;
    cout << "Front of queue is " << BlooregardQueueKazoo.peekFront() << endl;
    return;
  }
  else if (curr->getVal() == BlooregardQueueKazoo.peekFront())
  {
    if(curr->getLeftChildPtr() == nullptr)
    {
      curr->setLeftChildPtr(newBinaryNode);
      BlooregardQueueKazoo.enqueue(elem);
      ImmortalQueue.enqueue(elem);
      m_size++;
      m_sum = m_sum + elem;
      cout << "Added " << elem << " to left" << endl;
      cout << "Front of queue " << BlooregardQueueKazoo.peekFront() << endl;
      return;
    }
    else if(curr->getRightChildPtr() == nullptr)
    {
      curr->setRightChildPtr(newBinaryNode);
      BlooregardQueueKazoo.enqueue(elem);
      ImmortalQueue.enqueue(elem);
      cout << "Added " << elem << " to right" << endl;
      BlooregardQueueKazoo.peekFront();
      BlooregardQueueKazoo.dequeue();
      BlooregardQueueKazoo.peekFront();
      m_size++;
      m_sum = m_sum + elem;
      return;
    }
  }

  else
  {
    if(curr->getLeftChildPtr()->getLeftChildPtr() != nullptr && curr->getLeftChildPtr()->getRightChildPtr() != nullptr)
    {
      if(curr->getRightChildPtr()->getLeftChildPtr() != nullptr && curr->getRightChildPtr()->getRightChildPtr() != nullptr)
      {
        addRecursive(elem, curr->getLeftChildPtr());
      }
      else
      {
        cout << "Front of queue is " << BlooregardQueueKazoo.peekFront() << endl;
        cout << "Going right" << endl;
        addRecursive(elem, curr->getRightChildPtr());
      }
    }
    else
    {
      if (curr->getLeftChildPtr() != nullptr)
      {
        cout << "Front of queue is " << BlooregardQueueKazoo.peekFront() << endl;
        cout << "Going left" << endl;
        addRecursive(elem, curr->getLeftChildPtr());
      }
    }
    //curr = curr->getLeftChildPtr();

  }
}

void BinaryTree::addElem(int elem) {

  BinaryNode* cruisePtr = m_root;
  addRecursive(elem, cruisePtr);
  return;
}

int BinaryTree::deleteElem() {

Node* temp = ImmortalQueue.getFront();
//Node* BlooTemp = BlooregardQueueKazoo.getFront();
//cout << temp->getValue() << endl;
  while(temp->getNext()->getNext() != nullptr)
    {
      temp = temp->getNext();
      //m_front = temp;
    }

  // while(BlooTemp->getNext()->getNext() != nullptr)
  // {
  //   BlooTemp = BlooTemp->getNext();
  // }

  int toDelete = temp->getNext()->getValue();
  //cout << temp->getNext()->getValue() << endl;
  deleteRecHelper(toDelete, m_root);
  m_size--;
  m_sum = m_sum - toDelete;
  delete temp->getNext();
  temp->setNext(nullptr);
  //delete BlooTemp->getNext();
  //BlooTemp->setNext(nullptr);


  return toDelete;
}

void BinaryTree::deleteRecHelper(int elem, BinaryNode* subTreePtr)
{

  if (subTreePtr->getLeftChildPtr()->getVal() == elem)
  {

    delete subTreePtr->getLeftChildPtr();

    subTreePtr->setLeftChildPtr(nullptr);

    return;
  }
  if (subTreePtr->getRightChildPtr()->getVal() == elem)
  {
    delete subTreePtr->getRightChildPtr();
    subTreePtr->setRightChildPtr(nullptr);
    return;
  }
  if (subTreePtr->getVal() == elem)
  {
    //cout << "HERE" << endl;
      delete m_root;
      m_root = nullptr;
      return;
  }

  if (subTreePtr->getLeftChildPtr()->getLeftChildPtr() != nullptr || subTreePtr->getLeftChildPtr()->getRightChildPtr() != nullptr)
  {
    deleteRecHelper(elem, subTreePtr->getLeftChildPtr());
  }

  if (subTreePtr->getRightChildPtr()->getRightChildPtr() != nullptr || subTreePtr->getRightChildPtr()->getLeftChildPtr() != nullptr)
  {

    deleteRecHelper(elem, subTreePtr->getRightChildPtr());

  }
  return;
}

bool BinaryTree::exists(int elem) {

  if (existRecHelper(elem, m_root) == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool BinaryTree::existRecHelper(int elem, BinaryNode* subTreePtr)
{
  if (subTreePtr->getVal() == elem)
  {
      cout << "I found the element you were looking for!" << endl;
      return true;
  }

  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    if (existRecHelper(elem, subTreePtr->getLeftChildPtr()) == true)
    {
      return true;
    }
  }

  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    if (existRecHelper(elem, subTreePtr->getRightChildPtr()) == true)
    {
      return true;
    }
  }

  return false;

}


int BinaryTree::inorderTraverse(int identity, int (*operation)(int, int)){
  IMPLEMENT_ME();
  return 0;
}

int BinaryTree::preorderTraverse(int identity, int (*operation)(int, int)){
  IMPLEMENT_ME();
  return 0;
}

int BinaryTree::postorderTraverse(int identity, int (*operation)(int, int)){
  IMPLEMENT_ME();
  return 0;
}

int BinaryTree::sum(){
  return m_sum;
}

void BinaryTree::print(int printType) {
  if(printType == 1){
    std::cout << "inorder traversal: " << std::endl;
    inorderTraverseLazyRecurse(m_root);
  }
  else if(printType == 2){
    std::cout << "preorder traversal: " << std::endl;
    preorderTraverseLazyRecurse(m_root);
  } else if(printType == 3){
    std::cout << "postorder traversal: " << std::endl;
    postorderTraverseLazyRecurse(m_root);
  } else {
    std::cout << "Error invalid print type. Please choose a correct option."
              << std::endl;
  }
}

void BinaryTree::inorderTraverseLazyRecurse(BinaryNode* subTreePtr)
{
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    inorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  //cout << subTreePtr->getVal() << endl;id BinaryTree::preorderTraverseLazyRecurse(BinaryNode* subTreePtr)
  cout << subTreePtr->getVal() << endl;

  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    inorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }
}

void BinaryTree::preorderTraverseLazyRecurse(BinaryNode* subTreePtr)
{
  cout << subTreePtr->getVal() << endl;
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    preorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    preorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }
}

void BinaryTree::postorderTraverseLazyRecurse(BinaryNode* subTreePtr)
{
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    postorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    postorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }
    cout << subTreePtr->getVal() << endl;
}
