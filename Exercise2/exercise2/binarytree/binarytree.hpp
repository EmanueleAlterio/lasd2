
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : public virtual PreOrderTraversableContainer<Data>,
                   public virtual PostOrderTraversableContainer<Data>,
                   public virtual InOrderTraversableContainer<Data>,
                   public virtual BreadthTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>,
  //             InOrderTraversableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  struct Node {

  protected:

    // Comparison operators
    bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but is not visible.
    bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but is not visible.

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    Node& operator=(Node&&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool isLeaf() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual const Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  void Traverse(TraverseFun) const override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  void InOrderTraverse(TraverseFun) const override; // Override InOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

protected:

  // Auxiliary functions, if necessary!

  void PreOrderTraverse(TraverseFun, const Node*) const;

  void PostOrderTraverse(TraverseFun, const Node*) const;

  void InOrderTraverse(TraverseFun, const Node*) const;

  void BreadthTraverse(TraverseFun, const Node*) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : public virtual ClearableContainer,
                          public virtual BinaryTree<Data>,
                          public virtual PreOrderMappableContainer<Data>,
                          public virtual PostOrderMappableContainer<Data>,
                          public virtual InOrderMappableContainer<Data>,
                          public virtual BreadthMappableContainer<Data> {
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;
  using typename BinaryTree<Data>::Node;

public:

  struct MutableNode : virtual Node{
    // Must extend Node

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode& operator=(const MutableNode&) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    MutableNode& operator=(MutableNode&&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)

    virtual MutableNode& LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  MutableBinaryTree& operator=(MutableBinaryTree&&) noexcept = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual MutableNode& Root() = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions, if necessary!

  void PreOrderMap(MapFun, MutableNode*);

  void PostOrderMap(MapFun, MutableNode*);

  void InOrderMap(MapFun, MutableNode*);

  void BreadthMap(MapFun, MutableNode*);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : public virtual ForwardIterator<Data>,
                           public virtual ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  const typename BinaryTree<Data>::Node* curr = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>& bt){
    if(bt.Size() != 0){
      root = curr = &bt.Root();
    }
  }; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator& iterator) : root(iterator.root), curr(iterator.curr), stk(iterator.stk) {};

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(stk, iterator.stk);
  };

  /* ************************************************************************ */

  // Destructor
  ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator& iterator){
    root = iterator.root;
    curr = iterator.curr;
    stk = iterator.stk;
    return *this;
  };

  // Move assignment
  BTPreOrderIterator& operator=(BTPreOrderIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(stk, iterator.stk);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator&) const noexcept = default;
  bool operator!=(const BTPreOrderIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override{
    if(curr != nullptr){
      return curr->Element();
    } else {
      throw std::out_of_range("Iterator out of bounds!");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override{
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override{
    stk.Clear();
    curr = root;
  }; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : public virtual MutableIterator<Data>,
                                  public virtual BTPreOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  using BTPreOrderIterator<Data>::curr;

public:

  // Specific constructors
  BTPreOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPreOrderIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator& iterator) : BTPreOrderIterator<Data>(iterator) {};

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&& iterator) : BTPreOrderIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& iterator){
    BTPreOrderIterator<Data>::operator=(iterator);
  };

  // Move assignment
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& iterator) noexcept{
    BTPreOrderIterator<Data>::operator=(std::move(iterator));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderMutableIterator&) const noexcept = default;
  bool operator!=(const BTPreOrderMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override{
    if(curr != nullptr){
      return const_cast<Data&>(curr->Element());
    } else {
      throw std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : public virtual ForwardIterator<Data>,
                            public virtual ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  const typename BinaryTree<Data>::Node* curr = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator& iterator) : root(iterator.root), curr(iterator.curr), stk(iterator.stk) {};

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(stk, iterator.stk);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator& iterator){
    root = iterator.root;
    curr = iterator.curr;
    stk = iterator.stk;
    return *this;
  };

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(stk, iterator.stk);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept = default;
  bool operator!=(const BTPostOrderIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override{
    if(curr != nullptr){
      return curr->Element();
    }else{
      throw std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override{
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

protected:

  void getLeftMostLeaf();
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>,
                                    virtual public BTPostOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  using BTPostOrderIterator<Data>::curr;

public:

  // Specific constructors
  BTPostOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPostOrderIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& iterator) : BTPostOrderIterator<Data>(iterator) {};

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&& iterator) : BTPostOrderIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& iterator) {
    BTPostOrderIterator<Data>::operator=(iterator);
  };

  // Move assignment
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& iterator) noexcept{
    BTPostOrderIterator<Data>::operator=(std::move(iterator));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderMutableIterator&) const noexcept = default;
  bool operator!=(const BTPostOrderMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override{
    if(curr != nullptr){
      return const_cast<Data&>(curr->Element());
    }else{
      std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  const typename BinaryTree<Data>::Node* curr = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator& iterator) : root(iterator.root), curr(iterator.curr), stk(iterator.stk) {};

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(stk, iterator.stk);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator& iterator){
    root = iterator.root;
    curr = iterator.curr;
    stk = iterator.stk;
    return *this;
  };

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(stk, iterator.stk);
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator&) const noexcept;
  bool operator!=(const BTInOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override{
    if(curr != nullptr){
      return curr->Element();
    }else{
      throw std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override{
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

  void getLeftMostNode();
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>,
                                  virtual public BTInOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  using BTInOrderIterator<Data>::curr;

public:

  // Specific constructors
  BTInOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTInOrderIterator<Data>(bt) {}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& iterator) : BTInOrderIterator<Data>(iterator) {};

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& iterator) : BTInOrderIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator<Data>& iterator){
      BTInOrderIterator<Data>::operator=(iterator);
  };

  // Move assignment
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator<Data>&& iterator) noexcept{
      BTInOrderIterator<Data>::operator=(std::move(iterator));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderMutableIterator&) const noexcept = default;
  bool operator!=(const BTInOrderMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override{
    if(curr != nullptr){
      return const_cast<Data&>(curr->Element());
    }else{
      std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  const typename BinaryTree<Data>::Node* curr = nullptr;
  QueueVec<const typename BinaryTree<Data>::Node*> que;

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>& bt){
    if(bt.Size() != 0){
      curr = root = &bt.Root();
    }
  }; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator& iterator) : root(iterator.root), curr(iterator.root), que(iterator.que) {};

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.curr);
    std::swap(que, iterator.que);
  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator& iterator){
    root = iterator.root;
    curr = iterator.curr;
    que = iterator.que;
    return *this;
  };

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator&& iterator) noexcept{
    std::swap(root, iterator.root);
    std::swap(curr, iterator.root);
    std::swap(que, iterator.que);
    return *this;
  };


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator&) const noexcept = default;
  bool operator!=(const BTBreadthIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override{
    if(curr != nullptr){
      return curr->Element();
    }else{
      throw std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override{
    return (curr == nullptr);
  }; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override{
    curr = root;
    que.Clear();
  }; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                  virtual public BTBreadthIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  using BTBreadthIterator<Data>::curr;

public:

  // Specific constructors
  BTBreadthMutableIterator(BinaryTree<Data>& bt) : BTBreadthIterator<Data>(bt){}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator& iterator) : BTBreadthIterator<Data>(iterator) {};

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator&& iterator) : BTBreadthIterator<Data>(std::move(iterator)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& iterator){
    BTBreadthIterator<Data>::operator=(iterator);
  };

  // Move assignment
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& iterator){
    BTBreadthIterator<Data>::operator=(std::move(iterator));
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthMutableIterator&) const noexcept = default;
  bool operator!=(const BTBreadthMutableIterator&) const noexcept = default;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override{
    if(curr != nullptr){
      return const_cast<Data&>(curr->Element());
    }else{
      std::out_of_range("Iterator out of bounds");
    }
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
