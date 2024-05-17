

#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>,
                virtual protected List<Data>{

public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const TraversableContainer<Data> &container) : List<Data>(container){};
  StackLst(MappableContainer<Data> &&container) : List<Data>(std::move(container)){};

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst &stackLst) : List<Data>(stackLst){};

  // Move constructor
  StackLst(StackLst &&stackLst) noexcept : List<Data>(std::move(stackLst)){};

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator=(const StackLst&);

  // Move assignment
  StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst&) const noexcept;
  bool operator!=(const StackLst&) const noexcept;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)
  const Data& Top() const override;
  Data& Top() override;
  
  void Pop() override;
  Data TopNPop() override;
  
  void Push(const Data&) override;
  void Push(Data&&) noexcept override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  using List<Data>::Clear;
};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif