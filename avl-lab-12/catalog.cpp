#include "catalog.hpp"
#include "util.hpp"

Catalog::Catalog(){
  AVLanche = new AVL();
}


Catalog::~Catalog(){
  delete AVLanche->rootbeer;
}



void Catalog::addBook(int id, std::string bookName, std::string pub, int copyCount){
  // cout << id << endl;
  // cout << bookName << endl;
  // cout << pub << endl;
  // cout << copyCount << endl;

  Book* inCurrCat = AVLanche->search(id);

  Book* newBook = new Book(id, bookName, pub, copyCount);

  if (inCurrCat != nullptr)
  {
    if (inCurrCat->getId() == newBook->getId())
    {
      inCurrCat->setCurrentCount(newBook->getCurrentCount() + inCurrCat->getCurrentCount());
      if (inCurrCat->getCurrentCount() > inCurrCat->getTotalCount())
      {
        inCurrCat->setTotalCount(inCurrCat->getCurrentCount());
      }

    }
  }
  // cout << newBook->getId() << endl;
  // cout << newBook->getName() << endl;
  // cout << newBook->getPublisher() << endl;
  // cout << newBook->getCurrentCount() << endl;
  else
  {
    AVLanche->addBook(newBook);
  }
}


Book* Catalog::checkoutBook(int id){
  Book* searchedBook = AVLanche->search(id);
  if (searchedBook != nullptr)
  {
    int ct = searchedBook->getCurrentCount();
    if (ct > 0)
    {
      searchedBook->setCurrentCount(ct-1);
      cout << "Check out book details" << endl;
      cout << "Book name: " << searchedBook->getName() << endl;
      cout << "Book publisher: " << searchedBook->getPublisher() << endl;
      cout << "Book ID: " << searchedBook->getId() << endl;
      cout << "Availability count: " << searchedBook->getCurrentCount() << "/" << searchedBook->getTotalCount() << endl;
      return searchedBook;
    }
    else
    {
      std::cout << "Sorry, but that book is currently out of stock!" << endl;
      return nullptr;
    }
  }
  else
  {
    std::cout << "Sorry, but that book isn't in our catalog!" << endl;
    return nullptr;
  }
}


void Catalog::returnBook(int id){
  Book* returnedBook = AVLanche->search(id);
  if (returnedBook != nullptr)
  {
    int ct = returnedBook->getCurrentCount();
    returnedBook->setCurrentCount(ct+1);
  }
  else
  {
    std::cout << "Sorry, but that book isn't in our catalog!" << std::endl;
  }
}
