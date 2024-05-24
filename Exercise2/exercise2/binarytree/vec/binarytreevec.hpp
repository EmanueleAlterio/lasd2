
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using MutableBinaryTree<Data>::size;


public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:
  struct NodeVec : virtual MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    Data info;
    unsigned long curr = 0;
    Vector<NodeVec*> *tree = nullptr;

    //Default constructor
    NodeVec() = default;

    //Specific constructor
    NodeVec(const Data&, unsigned long, Vector<NodeVec*>*);

    //Destructor
    virtual ~NodeVec() = default;

    //Copy assignment
    NodeVec& operator=(const NodeVec&);

    //Move assignment
    NodeVec& operator=(NodeVec&&) noexcept;

    //Comparison operators
    bool operator==(const NodeVec& node) const noexcept{
      return BinaryTree<Data>::Node::opeartor==(node);
    }

    bool operator!=(const NodeVec& node) const noexcept{
      return BinaryTree<Data>::Node::opeartor!=(node);
    }

    //Functions
    const Data& Element() const noexcept override;
    Data& Element() noexcept override;
    bool isLeaf() const noexcept override;
    bool HasRightChild() const noexcept override;
    bool HasLeftChild() const noexcept override;
    virtual const Node& LeftChild() const override;
    virtual const Node& RightChild() const override;
    virtual MutableNode& LeftChild() override;
    virtual MutableNode& RightChild() override;

  };

  Vector<NodeVec*> *vec = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(MappableContainer<Data>&&) noexcept; // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec<Data>& bt) const noexcept{
    return MutableBinaryTree<Data>::operator==(bt);
  }

  bool operator!=(const BinaryTreeVec<Data>& bt) const noexcept{
    return MutableBinaryTree<Data>::operator!=(bt);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  using typename BreadthTraversableContainer<Data>::TraverseFun;

  void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  using typename BreadthMappableContainer<Data>::MapFun;

  void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
