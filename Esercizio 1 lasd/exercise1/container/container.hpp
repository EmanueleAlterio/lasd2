
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  unsigned long size;
  // ...

  /* ************************************************************************ */

  //Default Constructor
  Container() = default;

public:

 
  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Container& operator=(Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  bool Empty() const noexcept{
    return (size==0);
  }// (concrete function should not throw exceptions)

  unsigned long  Size() const noexcept{
    return size;
  }; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&) const noexcept = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer&) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer&) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&) const noexcept = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer&) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer&) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(unsigned long new_size) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override{
    Resize(0);
  }

};

/* ************************************************************************** */

}

#endif