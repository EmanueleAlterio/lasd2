
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;

  unsigned long acoeff = 1;
  unsigned long bcoeff = 0;

  static const unsigned long prime = 1000000016531;

  static const Hashable<Data> enchash;

  std::default_random_engine  gen = std::default_random_engine(std::random_device {}());
  std::uniform_int_distribution<ulong> dista = std::uniform_int_distribution<ulong>(1, prime-1);
  std::uniform_int_distribution<ulong> distb = std::uniform_int_distribution<ulong>(1, prime-1);


  unsigned long tableSize = 128;

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

protected:

  //Default Connstructor 
  HashTable(){
    acoeff = dista(gen);
    bcoeff = distb(gen);
  }

  //Copy Constructor
  HashTable(const HashTable& otherht){
    size = otherht.size;
    acoeff = otherht.acoeff;
    bcoeff = otherht.bcoeff;
    tableSize = otherht.tableSize;
  }

  // Move Constructor
  HashTable(HashTable&& otherht){
    std::swap(size, otherht.size);
    std::swap(acoeff, otherht.acoeff);
    std::swap(bcoeff, otherht.bcoeff);
    std::swap(tableSize, otherht.tableSize);
  }

  //Copy assignment
  HashTable& operator=(const HashTable& otherht){
    size = otherht.size;
    acoeff = otherht.acoeff;
    bcoeff = otherht.bcoeff;
    tableSize = otherht.tableSize;
    
    return *this;
  }

  //Move assignment
  HashTable& operator=(HashTable&& otherht){
    std::swap(size, otherht.size);
    std::swap(acoeff, otherht.acoeff);
    std::swap(bcoeff, otherht.bcoeff);
    std::swap(tableSize, otherht.tableSize);

    return *this;
  }



  virtual unsigned long HashKey(const Data&) const noexcept;

  virtual unsigned long HashKey(unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
