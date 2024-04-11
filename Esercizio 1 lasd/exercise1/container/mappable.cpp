#include "mappable.hpp"
namespace lasd {

/* ************************************************************************** */

template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFun fun) {
    PreOrderMap(fun);
}

template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFun fun) {
    PostOrderMap(fun);
}

// Specific member functions (InOrderMappableContainer)
template<typename Data>
void InOrderMappableContainer<Data>::Map(MapFun fun){
    InOrderMap(fun);
}

/* ************************************************************************** */
// Specific member functions (BreadthMappableContainer)
template<typename Data>
void BreadthMappableContainer<Data>::Map(MapFun fun){
    BreadthMap(fun);
}

/* ************************************************************************** */

}
