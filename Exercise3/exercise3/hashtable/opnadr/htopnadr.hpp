
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::size;
  using HashTable<Data>::enchash;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::dista;
  using HashTable<Data>::distb;
  using HashTable<Data>::generator;
  using HashTable<Data>::tablesize;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::Insert;
  using HashTable<Data>::InsertAll;

  #define MIN_SIZE 128
  #define MAX_SIZE 2097152

  Vector<Data> table;
  Vector<char> flags;

public:

  // Default constructor
  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const unsigned long); // A hash table of a given size
  HashTableOpnAdr(const TraversableContainer<Data>&); // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(unsigned long, const TraversableContainer<Data>&); // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(MappableContainer<Data>&&); // A hash table obtained from a MappableContainer
  HashTableOpnAdr(unsigned long, MappableContainer<Data>&&); // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr<Data>&);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr<Data>&&);

  /* ************************************************************************ */

  // Destructor
  virutal ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr<Data>&);

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr<Data>&) const noexcept;
  bool operator!=(const HashTableOpnAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(unsigned long) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
