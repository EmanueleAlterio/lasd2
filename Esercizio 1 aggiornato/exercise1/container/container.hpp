#ifndef CONTAINER_HPP
#define CONTAINER_HPP


namespace lasd {

class Container {

protected:

  unsigned long size = 0;

  // Default constructor
  Container() = default;

public:

  // Destructor
  virtual ~Container() = default;

  /* ******************************** */

  // Copy and Move assignment of abstract types is not possible.
  Container& operator=(const Container&) = delete;
  Container& operator=(Container&&) noexcept = delete;

  /* ******************************** */

  // Comparison operators of abstract types is not possible
  bool operator==(const Container&) const noexcept = delete;
  bool operator!=(const Container&) const noexcept = delete;

  /* ******************************** */

  // Specific member functions
  virtual bool Empty() const noexcept{
    return (size == 0);
  }

  virtual unsigned long Size() const noexcept{
    return size;
  }
};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
  
public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ******************************** */

  // Copy and Move assignment of abstract types is not possible.
  ClearableContainer& operator=(const ClearableContainer&) = delete;
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete;

  /* ******************************** */

  // Comparison operators of abstract types is not possible
  bool operator==(const ClearableContainer&) const noexcept = delete;
  bool operator!=(const ClearableContainer&) const noexcept = delete;
  
  /* ******************************** */

  // Specific member functions
  virtual void Clear() = 0;
};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer{

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ******************************** */

  // Copy and Move assignment of abstract types is not possible.
  ResizableContainer& operator=(const ResizableContainer&) = delete;
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete;

  /* ******************************** */

  // Comparison operators of abstract types is not possible
  bool operator==(const ResizableContainer&) const noexcept = delete;
  bool operator!=(const ResizableContainer&) const noexcept = delete;
  
  /* ******************************** */

  // Specific member functions
  virtual void Resize(unsigned long) = 0;

  /* ******************************** */

  // Specific member function (inherited from ClearableContainer)
  virtual void Clear() override {
    Resize(0);
  }
};

}

#endif