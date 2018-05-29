#include "book.hpp"
#include "util.hpp"


Book::Book(int bid, std::string bname, std::string bpublisher, int bcopyCount) {
  id = bid;
  name = bname;
  publisher = bpublisher;
  currentCount = bcopyCount;
  totalCount = bcopyCount;
}


int Book::getId() {
  return id;
}


std::string Book::getName(){
  return name;
}


std::string Book::getPublisher(){
  return publisher;
}


int Book::getCurrentCount(){
  return currentCount;
}


void Book::setCurrentCount(int count){
  currentCount = count;
}


int Book::getTotalCount(){
  return totalCount;
}


void Book::setTotalCount(int count){
  totalCount = count;
}
