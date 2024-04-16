
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data>, 
                            virtual public MappableContainer<Data>{
 
public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy and Move assignment of abstract types is not possible.
  DictionaryContainer& operator=(const DictionaryContainer&) = delete;
  DictionaryContainer& operator=(DictionaryContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer&) const noexcept = delete;
  bool operator!=(const DictionaryContainer&) const noexcept = delete;
  
  /* ************************************************************************ */

  // Specific member functions
  
  virtual bool Insert(const Data&) = 0;
  virtual bool Insert(Data&&) = 0;
  virtual bool Remove(const Data&) = 0;

  bool InsertAll(const TraversableContainer<Data>&);
  bool InsertAll(MappableContainer<Data>&&);
  bool RemoveAll(const TraversableContainer<Data>&);

  bool InsertSome(const TraversableContainer<Data>&);
  bool InsertSome(MappableContainer<Data>&&);
  bool RemoveSome(const TraversableContainer<Data>&);
};

}

#include "dictionary.cpp"

#endif