#ifndef BOOK_HPP
#define BOOK_HPP

#include<string>

/**
 * Models a book object for library catalog
 */
class Book {
  /**
   * identifier for the book. It will be unique across the catalog.
   */
  int id;

  /**
   * Name of the book
   */
  std::string name;

  /**
   * Publisher of the book
   */
  std::string publisher;

  /**
   * number of copies available for the book
   */
  int currentCount;

  /**
   * total number of copies owned by the library
   */
  int totalCount;

public:
  /**
   * Constructor for book
   */
  Book(int id, std::string name, std::string publisher, int numberOfCopies);


  /**
   * Get id for the book
   */
  int getId();

  /**
   * get name for the book
   */
  std::string getName();

  /**
   * get publisher name for the book
   */
  std::string getPublisher();

  /**
   * get the current number of copies available in the library
   */
  int getCurrentCount();

  /**
   * set the copy count
   */
  void setCurrentCount(int count);

  /**
   * get the total number of copies owned by the library
   */
  int getTotalCount();

  /**
   * set the total number of copies owned by the library
   */
  void setTotalCount(int count);

};

#endif // BOOK_HPP defined
