#include "linear.hpp"
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool LinearContainer<Data> :: operator==(const LinearContainer<Data> & other) const noexcept{
    if(size != other.size)
        return false;
    
    for (unsigned long i = 0; i<size; i++){
        if(operator[](i) != other.operator[](i))
            return false;
    }

    return true;
}

template<typename Data>
bool LinearContainer<Data> :: operator!=(const LinearContainer<Data> & other) const noexcept{
    return !(*this == other);
}

template<typename Data>
const Data& LinearContainer<Data> :: Front() const{

    if (size > 0){
        return operator[](0);
    }

    throw std::length_error("[EXCEPTION] Linear container is empty");
}

template<typename Data>
Data& LinearContainer<Data> :: Front(){
    
    if (size > 0){
        return operator[](0);
    }

    throw std::length_error("[EXCEPTION] Linear container is empty");
}

template<typename Data>
const Data& LinearContainer<Data> :: Back() const{

    if (size > 0){
        return operator[](size-1);
    }

    throw std::length_error("[EXCEPTION] Linear container is empty");
}

template<typename Data>
Data& LinearContainer<Data> :: Back(){

    if (size > 0){
        return operator[](size-1);
    }

    throw std::length_error("[EXCEPTION] Linear container is empty");
}

template<typename Data>
void LinearContainer<Data> :: Traverse(TraverseFun TraverseFun) const{

    PreOrderTraverse(TraverseFun);

}

template<typename Data>
void LinearContainer<Data> :: PreOrderTraverse(TraverseFun TraverseFun) const{
    
    for(unsigned long i=0; i<size; i++){
        TraverseFun(operator[](i));
    }

}

template<typename Data>
void LinearContainer<Data> :: PostOrderTraverse(TraverseFun TraverseFun) const{
    
    for(unsigned long i=size; i>0; i--){
        TraverseFun(operator[](i-1));
    }

}

template<typename Data>
void LinearContainer<Data> :: Map(MapFun MapFun){

    PreOrderMap(MapFun);

}


template<typename Data>
void LinearContainer<Data> :: PreOrderMap(MapFun MapFun){
    for(unsigned long i = 0; i=size; i++){
        MapFun(operator[](i));
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFun MapFun) {
        for(unsigned long i = size - 1; i >= 0; i--){
            MapFun(operator[](i));
        }
}

template<typename Data>
bool SortableLinearContainer<Data> :: operator==(const SortableLinearContainer<Data> & container) const noexcept{
    return LinearContainer<Data> :: operator==(container);
}

template<typename Data>
bool SortableLinearContainer<Data> :: operator!=(const SortableLinearContainer<Data> & container) const noexcept{
    return !(SortableLinearContainer<Data> :: operator == (container));
}

template<typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept{
        QuickSort(0, size-1);
    }

template<typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long p, unsigned long r) noexcept {
        if (p < r) {
            unsigned long q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q + 1, r);
        }
    }

template<typename Data>
unsigned long SortableLinearContainer<Data>::Partition(unsigned long p, unsigned long r) noexcept{
        const Data& x = operator[](p);
        int i = p - 1;
        int j = r + 1;

        do {
            do {
                 j--; 
            } while( x < operator[](j) );

            do { 
                i++; 
            } while ( operator[](i) < x );

            if (i < j) { 
                std::swap(operator[](i) , operator[](j)); 
            }

        } while (i < j);

        return j;
    }
/* ************************************************************************** */

}
