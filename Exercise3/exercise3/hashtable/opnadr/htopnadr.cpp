#include "htopnadr.hpp"
namespace lasd {

/* ************************************************************************** */

//Default constructor
template <typename Data>
HashTableOpnAdr<Data>:: HashTableOpnAdr(){
    tableSize = MIN_SIZE;
    size = 0;
    acoeff = 2*(dista(generator))+1;
    bcoeff = 2*(distb(generator));
    table.Resize(tableSize);
    flags.Resize(tableSize);

    for(unsigned long i=0; i<tableSize; i++){
        flags[i] = 'E';
    }

    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
}

//Specific constructors
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long dim){
        size = 0;
    a = 2*(dista(generator))+1;
    b = 2*(distb(generator));
    tablesize = FindNext2Pow(dim);
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E'; // Empty, Full, Removed
    }
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& con) : HashTableOpnAdr(){
    InsertAll(con);
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long dim, const TraversableContainer<Data>& con) : HashTableOpnAdr(dim){
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& con) : HashTableOpnAdr(){
    InsertAll(std::move(con));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long dim, MappableContainer<Data>&& con) : HashTableOpnAdr(dim){
    InsertAll(std::move(con));
}

//Copy constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht){
    size = ht.size;
    tableSize = ht.tableSize;
    acoeff = ht.acoeff;
    bcoeff = ht.bcoeff;
    table = ht.table;
    flags = ht.flags;
    capacity = ht.capacity;
}

//Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);
    std::swap(table, ht.table);
    std::swap(flags, ht.flags);
    std::swap(capacity, ht.capacity);
}

//Copy assigment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht){
    HashTableOpnAdr<Data>* tmp = new HashTableOpnAdr(ht);
    std::swap(*this, *tmp);
    delete tmp;

    return *this;
}


//Move assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>:: operator=(HashTableOpnAdr&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);
    std::swap(table, ht.table);
    std::swap(flags, ht.flags);
    std::swap(capacity, ht.capacity);

    return *this;
}


//Comparison operators
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept{
    if(size != ht.size){
        return false;
    }

    for(unsigned long i=0; i<tableSize; i++){
        if(flags[i] == 'F'){
            if(!(ht.Exists(table[i]))){
                return false;
            }
        }
    }
    return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}
/* ************************************************************************** */

}
