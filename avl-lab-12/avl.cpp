#include "avl.hpp"
#include "util.hpp"

AVL::AVL() {
  rootbeer = nullptr;
}

AVL::~AVL() {
  IMPLEMENT_ME();
}


bool AVL::isEmpty() {
  if (rootbeer == nullptr)
  {
    return true;
  }
  return false;
}


void AVL::addBook(Book* book) {

  addHelp(rootbeer, book);

}

BinaryNode* AVL::leftleftrotation(BinaryNode* subtree)
{
  BinaryNode* pmet = subtree->getLeftChildPtr();
  if (pmet == nullptr)
  {
    subtree->setLeftChildPtr(nullptr);
    return subtree;
  }
  else
  {
    subtree->setLeftChildPtr(pmet->getRightChildPtr());
    pmet->setRightChildPtr(subtree);
  }

  return pmet;
}

BinaryNode* AVL::rightrightrotation(BinaryNode* subtree)
{
  BinaryNode* pmet = subtree->getRightChildPtr();

  if (pmet == nullptr)
  {
    subtree->setRightChildPtr(nullptr);
    return subtree;
  }

  else
  {
    //cout << "HERHERHEHREHREHRHE" << endl;
    subtree->setRightChildPtr(pmet->getLeftChildPtr());
    pmet->setRightChildPtr(subtree);
  }

  return pmet;
}

BinaryNode* AVL::leftrightrotation(BinaryNode* subtree)
{
  BinaryNode* pmet = subtree->getLeftChildPtr();
  if (pmet == nullptr)
  {
    return subtree;
  }
  subtree->setLeftChildPtr(rightrightrotation(pmet));

  return leftleftrotation(subtree);
}

BinaryNode* AVL::rightleftrotation(BinaryNode* subtree)
{
  BinaryNode* pmet = subtree->getRightChildPtr();

  if (pmet == nullptr)
  {
    // subtree->setRightChildPtr()
  }

  subtree->setRightChildPtr(leftleftrotation(pmet));

  return rightrightrotation(subtree);
}

BinaryNode* AVL::addHelp(BinaryNode* subtree, Book* book){
  BinaryNode* newNode = new BinaryNode();
  newNode->setBook(book);
  if (isEmpty())
  {
    rootbeer = newNode;
    return rootbeer;
  }
  else if(subtree == nullptr)
  {
    subtree = newNode;
    return subtree;
  }
  else if (book->getId() < subtree->getBook()->getId())
  {
    subtree->setLeftChildPtr(addHelp(subtree->getLeftChildPtr(), book));
    int decision = heighthelp(subtree);

    if (decision > 1)
    {
      if (heighthelp(subtree->getRightChildPtr()) > 0)
      {
        subtree = rightleftrotation(subtree);
      }
      else
      {
        subtree = rightrightrotation(subtree);
      }
    }
    else if (decision < -1)
    {
      if (heighthelp(subtree->getLeftChildPtr()) > 0)
      {
        subtree = leftleftrotation(subtree);
      }
      else
      {
        subtree = leftrightrotation(subtree);
      }

    }

    else
    {

    }

    return subtree;

  }

  else if (book->getId() >= subtree->getBook()->getId())
  {
    subtree->setRightChildPtr(addHelp(subtree->getRightChildPtr(), book));

    //inorderTraverseLazyRecurse(rootbeer);

    int decision = heighthelp(subtree);

    if (decision > 1)
    {
      if (heighthelp(subtree->getRightChildPtr()) > 0)
      {
        subtree = rightleftrotation(subtree);
      }
      else
      {
        subtree = rightrightrotation(subtree);
      }
    }
    else if (decision < -1)
    {
      if (heighthelp(subtree->getLeftChildPtr()) > 0)
      {
        subtree = leftleftrotation(subtree);
      }
      else
      {
        subtree = leftrightrotation(subtree);
      }

    }

    else
    {

    }

    return subtree;
  }
  //return nullptr;
}

int AVL::heighthelp(BinaryNode* subtree)
{
  //bool right_higher;
  return heighthelpHELP(subtree->getRightChildPtr()) - heighthelpHELP(subtree->getLeftChildPtr());
}

int AVL::heighthelpHELP(BinaryNode* subtree)
{
  int counter = 0;
  int higher = 0;

  if (subtree != nullptr)
  {
    int rightheight = heighthelpHELP(subtree->getRightChildPtr());

    int leftheight = heighthelpHELP(subtree->getLeftChildPtr());

    if (rightheight > leftheight)
    {
      higher = rightheight;
    }

    else if (leftheight >= rightheight)
    {
      higher = leftheight;
    }

    counter = higher;

  }
  return counter;
}

Book* AVL::search(int id) {
  Book* result;
  if (isEmpty())
  {
    result == nullptr;
  }
  if (rootbeer == nullptr)
  {
    result = nullptr;
  }

  //inorderTraverseLazyRecurse(rootbeer);

  else
  {
    result = searchHelp(id, rootbeer);
  }

  return result;
}

Book* AVL::searchHelp(int id, BinaryNode* subtree)
{

  if (subtree->getBook()->getId() == id)
  {
    return subtree->getBook();
  }

  if (subtree->getLeftChildPtr() != nullptr)
  {
    return searchHelp(id, subtree->getLeftChildPtr());
  }
  //cout << subTreePtr->getVal() << endl;id BinaryTree::preorderTraverseLazyRecurse(BinaryNode* subTreePtr)


  if (subtree->getRightChildPtr() != nullptr)
  {
    return searchHelp(id, subtree->getRightChildPtr());
  }

    //cout << subtree->getBook()->getId() << endl;
}


void AVL::levelorderTraverse(BinaryNode* book) {
  inorderTraverseLazyRecurse(book);
}

void AVL::inorderTraverseLazyRecurse(BinaryNode* subTreePtr)
{


  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    inorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
  }
  //cout << subTreePtr->getVal() << endl;id BinaryTree::preorderTraverseLazyRecurse(BinaryNode* subTreePtr)


  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    inorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());
  }

    cout << subTreePtr->getBook()->getId() << endl;
}
