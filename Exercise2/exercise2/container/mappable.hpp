
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>
#include "traversable.hpp"

namespace lasd {

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data>{

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy and Move assignment of abstract types is not possible.
  MappableContainer operator=(const MappableContainer&) = delete;
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators of abstract types is not possible.
  bool operator==(const MappableContainer&) const noexcept = delete;
  bool operator!=(const MappableContainer&) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member function
  using MapFun = std::function<void(Data &)>;
  virtual void Map(MapFun) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>, 
                                  virtual public PreOrderTraversableContainer<Data>{

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy and Move assignment of abstract types is not possible.
  PreOrderMappableContainer operator=(const PreOrderMappableContainer&) = delete;
  PreOrderMappableContainer operator=(PreOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators of abstract types is not possible.
  bool operator==(const PreOrderMappableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFun;
  virtual void PreOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  virtual void Map(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>, 
                                   virtual public PostOrderTraversableContainer<Data>{
public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy and Move assignment of abstract types is not possible.
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators of abstract types is not possible.
  bool operator==(const PostOrderMappableContainer&) const noexcept = delete;
  bool operator!=(const PostOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFun;
  virtual void PostOrderMap(MapFun) = 0;


  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  virtual void Map(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>, 
                                virtual public InOrderTraversableContainer<Data>{

public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy and Move assignment of abstract types is not possible.
  InOrderMappableContainer& operator=(const InOrderMappableContainer&) = delete;
  InOrderMappableContainer& operator=(InOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators of abstract types is not possible.
  bool operator==(const InOrderMappableContainer&) const noexcept = delete;
  bool operator!=(const InOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFun;
  virtual void InOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  virtual void Map(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>, virtual public BreadthTraversableContainer<Data>{

public:

  // Destructor
  virtual ~BreadthMappableContainer() = default;


  // Copy assignment of abstract types is not possible.
  BreadthMappableContainer& operator=(const BreadthMappableContainer&) = delete;

  // Move assignment of abstract types is not possible.
  BreadthMappableContainer& operator=(BreadthMappableContainer&&) noexcept = delete;


  // Comparison operators of abstract types is not possible.
  bool operator==(const BreadthMappableContainer&) const noexcept = delete;
  bool operator!=(const BreadthMappableContainer&) const noexcept = delete;


  // Specific member function
  using typename MappableContainer<Data>::MapFun;
  virtual void BreadthMap(MapFun) = 0;


  // Specific member function (inherited from MappableContainer)
  virtual void Map(MapFun) override;
};

}

#include "mappable.cpp"

#endif