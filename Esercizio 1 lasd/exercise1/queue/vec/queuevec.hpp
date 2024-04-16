
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data> , virtual protected Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>:: elements;
  using Vector<Data>:: size;
  unsigned long head = 0;
  unsigned long tail = 0;

  // ...

public:

  // Default constructor
  QueueVec() : Vector<Data>(5){};

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const TraversableContainer<Data> &); // A stack obtained from a TraversableContainer
  QueueVec(MappableContainer<Data> &&); // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec &queueVec) : Vector<Data>(queueVec){
    head = queueVec.head;
    tail = queueVec.tail;
  };

  // Move constructor
  QueueVec(QueueVec &&queueVec): Vector<Data>(std::move(queueVec)){
    std::swap(head, queueVec.head);
    std::swap(tail, queueVec.tail);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator=(const QueueVec &);

  // Move assignment
  QueueVec& operator=(QueueVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec &) const noexcept;
  bool operator!=(const QueueVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)

  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)

  void Enqueue(const Data &) override; // Override Queue member (copy of the value)
  void Enqueue(Data &&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  void Expand();
  void Reduce();
  void Resize(unsigned long, unsigned long);  

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
