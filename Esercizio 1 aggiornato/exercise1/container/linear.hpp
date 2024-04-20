
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>{

protected:

  using Container::size;

public:

  // Destructor
  virtual ~LinearContainer() = default;


  // Copy assignment of abstract types is not possible.
  LinearContainer& operator=(const LinearContainer&) = delete;

  // Move assignment of abstract types is not possible.
  LinearContainer& operator=(LinearContainer&&) noexcept = delete;


  // Comparison operators
  bool operator==(const LinearContainer&) const noexcept;
  bool operator!=(const LinearContainer&) const noexcept;


  // Specific member functions

  virtual const Data& operator[](const unsigned long) const = 0;
  virtual Data& operator[](const unsigned long) = 0;

  virtual const Data& Front() const;
  virtual Data& Front();

  virtual const Data& Back() const;
  virtual Data& Back();
  

  // Specific member function (inherited from TraversableContainer, PreOrderTraversableContainer, PostOrderTraversableContainer)
  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun) const override;
  void PreOrderTraverse(TraverseFun) const override;
  void PostOrderTraverse(TraverseFun) const override;


  // Specific member function (inherited from MappableContainer, PreOrderMappableContainer, PostOrderMappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun);
  void PreOrderMap(MapFun) override;
  void PostOrderMap(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data>{

protected:
  using Container::size;
  using LinearContainer<Data>::operator[];

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  // Copy assignment of abstract types is not possible.
  SortableLinearContainer& operator=(const SortableLinearContainer&) = delete;
  // Move assignment of abstract types is not possible.
  SortableLinearContainer& operator=(SortableLinearContainer&&) noexcept = delete;


  // Comparison operators of abstract types is possible.
  bool operator==(const SortableLinearContainer&) const noexcept;
  bool operator!=(const SortableLinearContainer&) const noexcept;
  
  
  // Specific member function
  virtual void Sort() noexcept;

  protected:
  // Auxiliary functions, if necessary!
  void QuickSort(unsigned long, unsigned long) noexcept;
  unsigned long Partition(unsigned long, unsigned long) noexcept;
};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif