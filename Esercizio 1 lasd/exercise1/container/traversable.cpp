#include "traversable.hpp"
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
bool TraversableContainer<Data>::Exists(const Data& val) const noexcept{
    bool exists = false;
    Traverse( //lambda function
        [val, &exists](const Data & dat){
            exists |= (dat == val);
        }
    );
    return exists;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFunction, Accumulator initialValue) const
    {
        Accumulator acc = initialValue;
        Traverse(
            [&acc,foldFunction](const Data &data) {
                acc = foldFunction(data, acc);
            }
        );
        return acc;
    }

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const{
    PreOrderTraverse(
        [fun, &acc](const Data & dat){
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const{
    PostOrderTraverse(
        [fun, &acc](const Data & dat){
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const{
    PreOrderTraverse(fun);
}

template <typename Data>
inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const{
    PostOrderTraverse(fun);
}

// Specific member functions (InOrderTraversableContainer)
template<typename Data>
template<typename Accumulator>
Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const{
    InOrderTraverse(
        [fun, &acc](const Data &data){
            acc = fun(data, acc);
        }
    );

    return acc;
}

template<typename Data>
void InOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const{
    OrderTraverse(fun);
}

/* ************************************************************************** */
// Specific member functions (BreadthTraversableContainer)
template<typename Data>
template<typename Accumulator>
Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> fun, Accumulator acc) const{
    BreadthTraverse(
        [fun, &acc](const Data &data){
            acc = fun(data, acc);
        }
    );

    return acc;
}

template<typename Data>
void BreadthTraversableContainer<Data>::Traverse(TraverseFun fun) const{
    BreadthTraverse(fun);
}
    
}
