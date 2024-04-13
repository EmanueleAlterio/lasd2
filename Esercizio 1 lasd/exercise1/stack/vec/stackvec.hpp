
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual protected Vector<Data> {
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  
  using Vector<Data>::size;
  using Vector<Data>::elements;
  using long index = 0;

  // ...

public:

  // Default constructor
  StackVec() : Vector<Data>(10){};
  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data>&); // A stack obtained from a TraversableContainer
  StackVec(MappableContainer<Data>&&); // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec &stackVec) : Vector<Data>(stackVec){
      index = stackVec.index;
  };

  // Move constructor
   StackVec(StackVec &&stackVec) noexcept : Vector<Data>(std::move(stackVec)){
      std::swap(index, stackVec.index);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec &);
 

  // Move assignment
  StackVec& operator=(StackVec &&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec &) const noexcept;
  bool operator!=(const StackVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data &) override; // Override Stack member (copy of the value)
  void Push(Data &&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override; // Override Container member

  inline unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  void Expand();
  void Reduce();
};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
