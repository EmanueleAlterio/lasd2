
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual protected List<Data>{
  // Must extend Queue<Data>,
  //             List<Data>

private:

  // ...

protected:

  // ...

public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const TraversableContainer<Data> & container) : List<Data>(container){}; // A stack obtained from a TraversableContainer
  QueueLst(MappableContainer<Data> && container) : List<Data>(std::move(container)){}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst &queueLst) : List<Data>(queueLst){};

  // Move constructor
  QueueLst(QueueLst &&queueLst) : List<Data>(std::move(queueLst)){};

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator=(const QueueLst &);

  // Move assignment
  QueueLst& operator=(QueueLst &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst &) const noexcept;
  bool operator!=(const QueueLst &) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data &) override; // Override Queue member (copy of the value)
  void Enqueue(Data &&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
