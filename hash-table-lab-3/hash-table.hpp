#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "list.hpp"
#include "doubleNode.hpp"

#include <iostream>
#include <fstream>

////////////////////////////////////////////////
// PLEASE DO NOT CHANGE THE METHOD SIGNATURES //
//          OR THE NAME OF THE CLASS          //
////////////////////////////////////////////////


class HashTable {
private:
  float currentLoad;
  float loadFactor;
  DoublyLinkedList** DoubListPtr;
  int newHashIndex;
  //Add private methods or fields here

  /**
   * This will be the size of the bucket collection
   * It will also be used by the hash function
   * _Requirement: It should always be a prime number_
   */
  int size;

  /**
   * Hashes the string value to find the correct bucket value
   * Recall that a hash function transforms the key value to an integer value
   * https://en.wikipedia.org/wiki/Hash_function
   */
  int hash(std::string);

  /**
   * This is called when the load factor is > 0.5 for the hashtable.
   * The resize function increases the size of the bucket array to the nearest
   * prime number greater than the current size.
   */
  void rehash();

public:
  /**
   * Creates an empty hash table with the bucket collection of
   * size equal to the given argument
   */
  HashTable(int size);

  /**
   * adds an element into the hash table
   * If necessary resizes the value store, if the load factor is more than 0.5
   **/
  void putValue(std::string);

  /**
   * searches for the passed argument and returns true if found,
   * false if not found.
   */
  bool searchValue(std::string);

  /**
   * deletes the string from the hash table if it exists.
   * Does not affect the state of the hash table if the element does not exist
   */
  void deleteValue(std::string);

  /**
   * prints the buckets and the chained data for each buckets
   * Eg:
   * ```
   * 1 -> "a" "d"
   * 2 -> "b" "e"
   * 3 -> "c" "j"
   * ```
   *
   * Essentially the logic will be:
   * For each of the buckets print:
   *    - bucket number
   *    - the arrow ->
   *    - all the elements in quotes and white space separated with the chain
   */
  void print();
};

#endif //HASH_TABLE_HPP
