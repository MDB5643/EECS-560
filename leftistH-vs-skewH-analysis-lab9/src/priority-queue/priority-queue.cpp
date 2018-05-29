#include "priority-queue/priority-queue.hpp"
#include "util/util.hpp"
//#include "priority-queue.hpp"
#include "simulator/task.hpp"


///////////////////////////////////
// Private Functions Definitions //
///////////////////////////////////

//////////////////////////////////
// Public functions Definitions //
//////////////////////////////////

PriorityQueue::PriorityQueue(){
  rootbeer = nullptr;
}

PriorityQueue::PriorityQueue(Task* tasks, int taskSize){
   int niceToAdd = tasks->getNice();
   int IDtoAdd = tasks->getTid();
   BinaryNode* newNode = new BinaryNode();
   newNode->settidvalue(IDtoAdd);
   newNode->setniceval(niceToAdd);
   newNode->setTask(tasks);
   rootbeer = newNode;
}

PriorityQueue::~PriorityQueue() {
  postorderHeapDestroyer(rootbeer);
}


void PriorityQueue::concat(PriorityQueue* that){
  //if root is null, added queue will be root
  if (this->rootbeer == nullptr)
  {
    this->rootbeer = that->rootbeer;
  }
  //if not, go into the forst helper function to check children
  else
  {
    rootbeer = concatAgain(rootbeer, that->rootbeer);

    // MOVED TO HELPER concatAgain
    // if (rootbeer == nullptr)
    //    {
    //      rootbeer = that->rootbeer;
    //    }
    //    //if the queue being added is null, original root stays the same
    //    if (that->rootbeer == nullptr)
    //    {
    //      rootbeer = rootbeer;
    //    }
    //
    //    //priority check
    //   if (rootbeer->getniceval() < that->rootbeer->getniceval())
    //   {
    //     rootbeer = kittyHelper(rootbeer, that->rootbeer);
    //   }
    //
    //   else
    //   {
    //     rootbeer = kittyHelper(that->rootbeer, rootbeer);
    //   }

  }
}

BinaryNode* PriorityQueue::concatAgain(BinaryNode* orig, BinaryNode* added)
{
  //redundant
  if (orig == nullptr)
  {
    return added;
  }
  //if the queue being added is null, original root stays the same
  if (added == nullptr)
  {
    return orig;
  }

  //priority check
  if (orig->getniceval() <= added->getniceval())
  {
    return kittyHelper(orig, added);
  }

  else
  {
    return kittyHelper(added, orig);
  }
}

BinaryNode* PriorityQueue::kittyHelper(BinaryNode* orig, BinaryNode* added)
{
  //if the root of the left child of the heap being added to is null, go ahead and put
  //the root of the new heap there
  if (orig->getLeftChildPtr() == nullptr)
  {
    orig->setLeftChildPtr(added);
  }

  //if not, set the right child of the higher priority root equal to the root of the
  //lower priority heap, or leave it as is if the current right child has a higher priority
  //than that of added lower priority heap's root. Then, if the left child of the higher
  //priority heap's rank is less than that of its sibling, swap the two. Increment the rank.
  else
  {
    orig->setRightChildPtr(concatAgain(orig->getRightChildPtr(), added));
    //concatAgain(orig->getRightChildPtr(), added);

    if (orig->getLeftChildPtr()->getRank() < orig->getRightChildPtr()->getRank())
    {
      BinaryNode* temp = orig->getLeftChildPtr();
      orig->setLeftChildPtr(orig->getRightChildPtr());
      orig->setRightChildPtr(temp);
    }
    orig->setRank(orig->getRightChildPtr()->getRank() + 1);

  }
  return orig;

}

void PriorityQueue::addElem(Task* task) {
  // int niceToAdd = task->getNice();
  // int IDtoAdd = task->getTid();
  // PriorityQueue AddQueue = new PriorityQueue(task, 4);
    PriorityQueue* nueuQueue = new PriorityQueue(task, 4);
    this->concat(nueuQueue);

}

Task* PriorityQueue::deleteMinElem(){
  BinaryNode* toDelete = rootbeer;
  Task* taskReturn = toDelete->getTask();
  rootbeer = concatAgain(rootbeer->getLeftChildPtr(), rootbeer->getRightChildPtr());
  delete toDelete;
  return taskReturn;
}

BinaryNode* PriorityQueue::getRoot()
{
  return rootbeer;
}

int PriorityQueue::inorderTraversal(int identity, int (*op)(Task*)){
  inorderTraverseLazyRecurse(rootbeer);
  return 0;
}

int PriorityQueue::postorderTraversal(int identity, int (*op)(Task*)){
  postorderTraverseLazyRecurse(rootbeer);
  return 0;
}

void PriorityQueue::postorderTraverseLazyRecurse(BinaryNode* subTreePtr)
{
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    postorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    postorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }
    cout << subTreePtr->gettidvalue() << endl;
}

void PriorityQueue::inorderTraverseLazyRecurse(BinaryNode* subTreePtr)
{
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    inorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  //cout << subTreePtr->getVal() << endl;id BinaryTree::preorderTraverseLazyRecurse(BinaryNode* subTreePtr)
  //cout << subTreePtr->gettidvalue() << endl;

  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    inorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }
}

void PriorityQueue::postorderHeapDestroyer(BinaryNode* subTreePtr)
{
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    postorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    postorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }
    delete subTreePtr;
}
