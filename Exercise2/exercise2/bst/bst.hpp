
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : public virtual ClearableContainer, 
            public virtual DictionaryContainer<Data>,
            public virtual BinaryTree<Data>,
            public virtual BinaryTreeLnk<Data>{
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  using typename BinaryTreeLnk<Data>::NodeLnk;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;

public:
  using BinaryTreeLnk<Data>::Traverse;
  using BinaryTreeLnk<Data>::PreOrderTraverse;
  using BinaryTreeLnk<Data>::PostOrderTraverse;
  using BinaryTreeLnk<Data>::InOrderTraverse;
  using BinaryTreeLnk<Data>::BreadthTraverse;

public:

  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const TraversableContainer<Data>&); // A bst obtained from a TraversableContainer
  BST(MappableContainer<Data>&&) noexcept; // A bst obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST<Data>& bst) : BinaryTreeLnk<Data>(bst) {};

  // Move constructor
  BST(BST<Data>&& bst) noexcept : BinaryTreeLnk<Data>(std::move(bst)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST& operator=(const BST<Data>& bst){
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
  }

  // Move assignment
  BST& operator=(BST<Data>&& bst) noexcept{
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
  }

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST& ) const noexcept;
  bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Min() const; // (concrete function must throw std::length_error when empty)
  virtual Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  virtual void RemoveMin(); // (concrete function must throw std::length_error when empty)

  virtual const Data& Max() const; // (concrete function must throw std::length_error when empty)
  virtual Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  virtual void RemoveMax(); // (concrete function must throw std::length_error when empty)

  virtual const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when not found)
  virtual Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  virtual void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when not found)

  virtual const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when not found)
  virtual Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  virtual void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  using BinaryTreeLnk<Data>::Root; // Override BinaryTree member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override{
    BinaryTreeLnk<Data>::Clear();
  }; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

  virtual Data DataNDelete(NodeLnk*);

  virtual NodeLnk* Detach(NodeLnk*&) noexcept;

  virtual NodeLnk* DetachMin(NodeLnk*&) noexcept;
  virtual NodeLnk* DetachMax(NodeLnk*&) noexcept;

  virtual NodeLnk* Skip2Left(NodeLnk*&) noexcept;
  virtual NodeLnk* Skip2Right(NodeLnk*&) noexcept;

  virtual NodeLnk* const & FindPointerToMin(NodeLnk* const &) const noexcept;
  virtual NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept; // Both mutable & unmutable versions
  virtual NodeLnk* const & FindPointerToMax(NodeLnk* const &) const noexcept;
  virtual NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept; // Both mutable & unmutable versions

  virtual NodeLnk* const & FindPointerTo(NodeLnk* const &, const Data&) const noexcept;
  virtual NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept; // Both mutable & unmutable versions

  virtual NodeLnk* const * FindPointerToPredecessor(NodeLnk* const &, const Data&) const noexcept;
  virtual NodeLnk** FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept; // Both mutable & unmutable versions

  virtual NodeLnk* const * FindPointerToSuccessor(NodeLnk* const &, const Data&) const noexcept;
  virtual NodeLnk** FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept; // Both mutable & unmutable versions
  

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
