#include "bst.hpp"
#include "util.hpp"

BST::BST(){
  rootPtr = nullptr;

}

BST::~BST() {
  Isengard(rootPtr); //destroys entire tree
}

void BST::Isengard(BinaryNode* subTreePtr)
{
  if (subTreePtr->getLeftChildPtr() != nullptr)
  {
    Isengard(subTreePtr->getLeftChildPtr());
  }
  if (subTreePtr->getRightChildPtr() != nullptr)
  {
    Isengard(subTreePtr->getRightChildPtr());
  }
  else
  {
    delete subTreePtr;
  }
}

bool BST::isEmpty() {
  if (rootPtr == nullptr)
  {
    return true;
  }
  return false;
}

BinaryNode* BST::getRootbeer()
{
  return rootPtr;
}

void BST::addElem(int elem) {
  if (rootPtr == nullptr)
	{
		rootPtr = new BinaryNode();
    rootPtr->setVal(elem);
	}
	else
	{
		BinaryNode* newItem = new BinaryNode();
    newItem->setVal(elem);
		insertInorder(rootPtr, newItem);
	}

}

BinaryNode* BST::insertInorder(BinaryNode* subTreePtr, BinaryNode* newNodePtr)
{
	if (newNodePtr->getVal() < subTreePtr->getVal())  //going left
	{
		if (subTreePtr->getLeftChildPtr() == nullptr)
		{
			subTreePtr->setLeftChildPtr(newNodePtr);
			return nullptr;
		}
		else
		{
			insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
		}
	}
	else //going right
	{
		if (subTreePtr->getRightChildPtr() == nullptr)
		{
			subTreePtr->setRightChildPtr(newNodePtr);
			return nullptr;
		}
		else
		{
			insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
		}
	}
  return nullptr;
}

void BST::deleteElem(int elem) {
  deleteAndReorderRecursive(rootPtr, elem);
}

void BST::deleteAndReorderRecursive(BinaryNode* subTreePtr, int target)
{
	//cout << "Examining " << subTreePtr->getVal() << endl;
	if (subTreePtr == nullptr)
	{
		//cout << "NULL POINTER FOUND " << endl;
		return;
	}
	//cout << " - Comparing " << subTreePtr->getItem() << endl;

	if (subTreePtr->getVal() == target)
	{
		//cout << "I think we're deleting the head...";
		if (rootPtr->getLeftChildPtr() != nullptr)
		{
			//cout << "Root has a left child, that will be the new root" << endl;
			BinaryNode *holder = rootPtr->getLeftChildPtr(); //get the child that will beocme the new root
			BinaryNode *holderRight = holder->getRightChildPtr(); //hold onto the left childs right children (holder takes roots right children)
			holder->setRightChildPtr(rootPtr->getRightChildPtr()); //holder takes responsibility for root's right children (but keeps its left children)
			rootPtr = holder;
			//cout << "Checking to re-add recursively" << endl; //do a recursive add for the holderRight, and all its children
			if (holderRight != nullptr)
			{
        //std::cout << "CHECKING RIGHT" << endl;
				addElem(holderRight->getVal());
				addToRootRecursive(holderRight);
			}

			return;
		}
		else if (rootPtr->getRightChildPtr() != nullptr)
		{
			//cout << "Root has a Right child, that will be the new root" << endl;
			BinaryNode *holder = rootPtr->getRightChildPtr(); //get the child that will beocme the new root
			BinaryNode *holderLeft = holder->getLeftChildPtr(); //hold onto the left childs right children (holder takes roots right children)
			holder->setLeftChildPtr(rootPtr->getLeftChildPtr()); //holder takes responsibility for root's right children (but keeps its left children)
			rootPtr = holder;
			//cout << "Checking to re-add recursively" << endl; //do a recursive add for the holderRight, and all its children
			if (holderLeft != nullptr)
			{
        //std::cout << "CHECKING LEFT" << endl;
				addElem(holderLeft->getVal());
				addToRootRecursive(holderLeft);
			}


			return;
		}


		return;
	}

	if (subTreePtr->getLeftChildPtr() != nullptr)
	{
		if (subTreePtr->getLeftChildPtr()->getVal() == target)
		{
			//cout << "Found as the left child of " << subTreePtr->getVal() << " is " << subTreePtr->getLeftChildPtr()->getVal() << endl;
			BinaryNode *holder = subTreePtr->getLeftChildPtr();
			subTreePtr->setLeftChildPtr(nullptr);

			//cout << "Checking to re-add recursively" << endl;
      if (holder->getLeftChildPtr() != nullptr)
      {
         addToRootRecursive(holder->getLeftChildPtr());
      }

			return;
		}
	}


	if (subTreePtr->getRightChildPtr() != nullptr)
	{
		if (subTreePtr->getRightChildPtr()->getVal() == target)
		{
			//cout << "Found as the right child of " << subTreePtr->getVal() << " is " << subTreePtr->getRightChildPtr()->getVal() << endl;
			BinaryNode *holder = subTreePtr->getRightChildPtr();
			subTreePtr->setRightChildPtr(nullptr);

			//cout << "Checking to re-add recursively" << endl;
      if (holder->getRightChildPtr() != nullptr)
      {
         addToRootRecursive(holder->getRightChildPtr());
      }
			return;
		}
	}

	if (subTreePtr->getVal() < target) //item less than target (pokemon < string, searching as it was sorted with pokemon < pokemon)
	{
		//cout << "Going right from " << subTreePtr->getVal() << endl;
		if (subTreePtr->getRightChildPtr() == nullptr) //if the left child is null, we didnt find it.
		{
			return; //return nullptr
		}
		deleteAndReorderRecursive(subTreePtr->getRightChildPtr(), target); //recurse onto the left child (returning whatever the recurse finds, on up the chain)
		return;
	}

	//cout << "Going left from " << subTreePtr->getVal() << endl;

	if (subTreePtr->getLeftChildPtr() == nullptr) //nothing right
	{
		return;
	}

	deleteAndReorderRecursive(subTreePtr->getLeftChildPtr(), target); //recurse right
	return;
}

void BST::addToRootRecursive(BinaryNode* otherSubTreePtr)
{
	if (otherSubTreePtr->getLeftChildPtr() != nullptr)
	{
		addElem(otherSubTreePtr->getLeftChildPtr()->getVal());
		addToRootRecursive(otherSubTreePtr->getLeftChildPtr());
	}

	if (otherSubTreePtr->getRightChildPtr() != nullptr)
	{
		addElem(otherSubTreePtr->getRightChildPtr()->getVal());
		addToRootRecursive(otherSubTreePtr->getRightChildPtr());
	}
}

bool BST::exists(int elem) {
  if (existRecHelper(elem, rootPtr) == true)
  {
    return true;
  }
  else
  {
    return false;
  }
  return false;
}

bool BST::existRecHelper(int elem, BinaryNode* subTreePtr)
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

int BST::inorderTraverse(int identity, int (*operation)(int, int)){
  inorderTraverseLazyRecurse(rootPtr);
  return 0;
}

int BST::postorderTraverse(int identity, int (*operation)(int, int)){
  postorderTraverseLazyRecurse(rootPtr);
  return 0;
}

int BST::preorderTraverse(int identity, int (*operation)(int, int)){
  preorderTraverseLazyRecurse(rootPtr);
  return 0;
}

int BST::levelorderTraverse(int identity, int (*operation)(int, int)){
  inorderTraverseLazyRecurse(rootPtr);
  return 0;
}

int BST::height(){

  return heightRecHelper(rootPtr) - 1;

}

int BST::heightRecHelper(BinaryNode* subTreePtr)
{

  int leftCount;
  int rightCount;

  if (subTreePtr == nullptr)
  {
    return 0;
  }

  leftCount = heightRecHelper(subTreePtr->getLeftChildPtr());
  rightCount = heightRecHelper(subTreePtr->getRightChildPtr());

  if( leftCount > rightCount || leftCount == rightCount)
  {
    return (leftCount + 1);
  }
  else
  {
    return (rightCount + 1);
  }

}

void BST::print(int printType){
    if(printType == 1){
	std::cout << "inorder traversal: " << std::endl;
	inorderTraverse(0, &dummy);
    }
    else if(printType == 2){
	std::cout << "preorder traversal: " << std::endl;
	preorderTraverse(0, &dummy);

    } else if(printType == 3){
	std::cout << "postorder traversal: " << std::endl;
	postorderTraverse(0, &dummy);
    } else if(printType == 4){
	std::cout << "levelorder traversal: " << std::endl;
	levelorderTraverse(0, &dummy);
    }	else {
	std::cout << "Error invalid print type. Please choose a correct option."
		  << std::endl;
    }
}

void BST::inorderTraverseLazyRecurse(BinaryNode* subTreePtr)
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

void BST::preorderTraverseLazyRecurse(BinaryNode* subTreePtr)
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

void BST::postorderTraverseLazyRecurse(BinaryNode* subTreePtr)
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
