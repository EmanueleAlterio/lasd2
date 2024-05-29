
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>

/* ************************************************************************** */

void mytest();

template <typename Data>
void TraversePrint(const Data& dat) {
  std::cout << dat << " ";
}

/* ************************************************************************** */

#endif
