#include "stackvec.hpp"
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data> :: StackVec(const TraversableContainer<Data>& container){
    try{
        index = 0;
        size = container.Size();
        elements = new Data[size];
        
        container.Traverse(
            [this](const Data &data){
                Push(data);
            }
        );
   }catch(std::bad_alloc &exception){
            std::cerr << "[EXCEPTION] Cannot allocate memory for Vector: " <<  exception.what();
    }
}


template<typename Data>
StackVec<Data> :: StackVec(MappableContainer<Data> && container){
    try{
        index = 0;
        size = container.Size();
        elements = new Data[size];
        
        container.Traverse(
            [this](const Data &data){
                Push(std::move(data));
            }
        );
    }catch(std::bad_alloc &exception){
            std::cerr << "[EXCEPTION] Cannot allocate memory for Vector: " <<  exception.what();
    }  
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec &stackVec){
    if(this != &stackVec){
        index = stackVec.index;
        Vector<Data>::operator=(stackVec);
    }

    return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec &&stackVec) noexcept{
    if(this != &stackVec){
        index = stackVec.index;
        Vector<Data>::operator=(std::move(stackVec));
    }

    return *this;
}

template<typename Data>
bool StackVec<Data> :: operator==(const StackVec &stackVec) const noexcept{
    if(this != &stackVec){
        return false;
    }

    return Vector<Data> :: operator==(stackVec);
}

template<typename Data>
bool StackVec<Data> :: operator!=(const StackVec &stackVec) const noexcept{
    return !(*this == stackVec);
}



// Specific member functions (inherited from Stack)

template<typename Data>
const Data& StackVec<Data> :: Top() const{
    if(Empty())
        throw std::length_error("[EXCEPTION] Stack is empty.");
    
    return elements[index-1];
}

template<typename Data>
Data& StackVec<Data> :: Top(){
    if(Empty())
        throw std::length_error("[EXCEPTION] Stack is empty.");
    
    return elements[index-1];
}


template<typename Data>
void StackVec<Data> :: Pop(){
    if(Empty())
        throw std::length_error("[EXCEPTION] Stack is empty.");

    Reduce();
    index--;
}

template<typename Data>
Data StackVec<Data>::TopNPop(){
    if(Empty())
        throw std::length_error("[EXCEPTION] Stack is empty.");

    Reduce();
    return std::move(elements[--index]);
    
}

template<typename Data>

void StackVec<Data>:: Push(const Data & data){
    Expand();
    elements[index++] = data;
}

template<typename Data>
void StackVec<Data>::Push(Data && data) noexcept{
    Expand();
    elements[index++] = std::move(data);
}


// Specific member functions (inherited from Container)

template<typename Data>
bool StackVec<Data>::Empty() const noexcept{
    return (index == 0);
}

template<typename Data>
unsigned long StackVec<Data>::Size() const noexcept{
    return index;
}

template<typename Data>
void StackVec<Data>::Clear(){
    index = 0;
    Vector<Data>::Resize(1);
}


// Auxiliary member functions

template<typename Data>
void StackVec<Data>::Expand(){
    if(index == size){
        Vector<Data>::Resize(size * 2);
    }
}

template<typename Data>
void StackVec<Data>::Reduce(){
    if(index == (size / 4))
        Vector<Data>::Resize(size/2);
    
}
/* ************************************************************************** */


}
