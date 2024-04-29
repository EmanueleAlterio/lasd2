
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP


#include <functional>
#include "testable.hpp"


namespace lasd {

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data>{

public:

  // Destructor
  virtual ~TraversableContainer() = default;


  // Copy assignment of abstract types is not possible.
  TraversableContainer& operator=(const TraversableContainer&) = delete;

  // Move assignment of abstract types is not possible.
  TraversableContainer& operator=(TraversableContainer&&) noexcept = delete;


  // Comparison of abstract types might be possible.
  bool operator==(const TraversableContainer&) const noexcept = delete;
  bool operator!=(const TraversableContainer&) const noexcept = delete;


  // Specific member function
  using TraverseFun = std::function<void(const Data &)>;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data&, const Accumulator&)>;

  virtual void Traverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;


  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override;
};
/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data>{

public:

  // Destructor
  virtual ~PreOrderTraversableContainer() = default;


  // Copy assignment of abstract types is not possible.
  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&) = delete;
  // Move assignment of abstract types is not possible.
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&) noexcept = delete;
 

  // Comparison operators of abstract types might be possible.
  bool operator==(const PreOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderTraversableContainer&) const noexcept = delete;


  // Specific member function
  using typename TraversableContainer<Data>::TraverseFun;
  
  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  virtual void PreOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;


  // Specific member function (inherited from TraversableContainer)
  void Traverse(TraverseFun) const override;
};


template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data>{

public:

  // Destructor
  virtual ~PostOrderTraversableContainer() = default;


  // Copy assignment of abstract types is not possible.
  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&) = delete;

  // Move assignment of abstract types is not possible.
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&) noexcept = delete;
 

  // Comparison operators of abstract types might be possible.
  bool operator==(const PostOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const PostOrderTraversableContainer&) const noexcept = delete;


  // Specific member function
  using typename TraversableContainer<Data>::TraverseFun;
  
  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  virtual void PostOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;


  // Specific member function (inherited from TraversableContainer)
  void Traverse(TraverseFun) const override;
};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer : virtual public TraversableContainer<Data>{

public:

  // Destructor
  virtual ~InOrderTraversableContainer() = default;


  // Copy assignment of abstract types is not possible.
  InOrderTraversableContainer& operator=(const InOrderTraversableContainer&) = delete;

  // Move assignment of abstract types is not possible.
  InOrderTraversableContainer& operator=(InOrderTraversableContainer&&) noexcept = delete;


  // Comparison operators of abstract types might be possible.
  bool operator==(const InOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const InOrderTraversableContainer&) const noexcept = delete;


  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  virtual void InOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator InOrderFold(FoldFun<Accumulator>, Accumulator) const;


  // Specific member function (inherited from TraversableContainer)
  void Traverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer : virtual public TraversableContainer<Data>{

public:

  // Destructor
  virtual ~BreadthTraversableContainer() = default;


  // Copy assignment of abstract types is not possible.
  BreadthTraversableContainer& operator=(const BreadthTraversableContainer&) = delete;

  // Move assignment of abstract types is not possible.
  BreadthTraversableContainer& operator=(BreadthTraversableContainer&&) noexcept = delete;


  // Comparison operators of abstract types might be possible.
  bool operator==(const BreadthTraversableContainer&) const noexcept = delete;
  bool operator!=(const BreadthTraversableContainer&) const noexcept = delete;


  // Specific member function
  using typename TraversableContainer<Data>::TraverseFun;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  inline virtual void BreadthTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator BreadthFold(FoldFun<Accumulator>, Accumulator) const;


  // Specific member function (inherited from TraversableContainer)
  void Traverse(TraverseFun) const override;
};

}

#include "traversable.cpp"

#endif