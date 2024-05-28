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

    capacity = (static_cast<double>(size)/static_cast<double>(tableSize))*100;
}

//Specific constructors
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long dim){
    size = 0;
    acoeff = 2*(dista(generator))+1;
    bcoeff = 2*(distb(generator));
    tableSize = FindNext2Pow(dim);
    table.Resize(tableSize);
    flags.Resize(tableSize);
    for(unsigned long i=0; i<tableSize; i++) {
        flags[i] = 'E'; // Empty, Full, Removed
    }
    capacity = (static_cast<double>(size)/static_cast<double>(tableSize))*100;
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

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data){
    capacity = (static_cast<double>(size)/static_cast<double>(tableSize))*100;
    if(capacity > 75){
        Resize(2*tableSize+1);
    }

    if(!Exists(data)){
        unsigned long key = FindEmpty(data, 0);
        
        if(key < tableSize){
            table[key] = data;
            flags[key] = 'F';
            size++;
            return true;
        }
    }

    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) noexcept{
    capacity = (static_cast<double>(size)/static_cast<double>(tableSize))*100;
    if(capacity > 75){
        Resize(2*tableSize+1);
    }

    if(!Exists(data)){
        unsigned long key = FindEmpty(data, 0);
        
        if(key < tableSize){
            table[key] = std::move(data);
            flags[key] = 'F';
            size++;
            return true;
        }
    }

    return false;
}

//Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data) {
    capacity = (static_cast<double>(size)/static_cast<double>(tableSize))*100;
    bool res = Remove(data, 0);
    if(capacity < 10) {
        Resize((tableSize/2)-1);
    }
    return res;
}


template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept{
    
    if(size == 0){
        return false;
    }

    unsigned long key = Find(data, 0);
    if(key < tableSize){
        return true;
    }

    return false;
}

//Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(unsigned long dim) {
    unsigned long newSize;
    if(!IsResizable(dim)) {
        return;
    }
    newSize = FindNext2Pow(dim);
    if(newSize == tableSize) {
        return;
    }
    HashTableOpnAdr<Data>* tmp = new HashTableOpnAdr<Data>(newSize);
    for(unsigned long i=0; i<tableSize; i++) {
        if(flags[i] == 'F') {
            tmp->Insert(table[i]);
        }
    }
    std::swap(*this, *tmp);
    delete tmp;
}

//Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    tableSize = MIN_SIZE;
    size = 0;
    table.Clear();
    table.Resize(tableSize);
    flags.Resize(tableSize);
    for(unsigned long i = 0; i<tableSize; i++) {
        flags[i] = 'E';
    }  
}

//HashKey
template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& data, unsigned long index) const noexcept {
    unsigned long key = enchash(data);
    return ((HashKey(key)+((index*index)+index)/2)%tableSize); //quadratic probing
}

//Find
template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& data, unsigned long index) const noexcept {
    unsigned long start = HashKey(data, index);
    while(index < tableSize) {
        if(table[start] == data) {
            return start;
        }
        if(flags[start] =='E') {
            return tableSize;
        }
        index++; 
        start = HashKey(data, index);
    }
    return index;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& data, unsigned long index) const noexcept {
    unsigned long start = HashKey(data, index);
    while(index < tableSize) {
        if(flags[start] == 'E' || flags[start] == 'R') {
            return start;
        }
        index++;
        start = HashKey(data, index);
    }
    return index;
}    


//Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data, unsigned long index) {
    if(size > 0) {
        unsigned long i = Find(data, index);
        if(i < tableSize) {
            unsigned long pos = HashKey(data, i);  
                if(flags[pos] == 'F' && table[pos] == data) {
                flags[pos] = 'R';
                size--;
                return true;
            }
        }
    }
    return false;
}

//FindNext2Pow
template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindNext2Pow(unsigned long dim) const noexcept {
    unsigned long newSize = MIN_SIZE;
    while(newSize < dim) {
        if(newSize >= MAX_SIZE) {
            break;   
        }
        newSize = newSize << 1;
    } 
    return newSize;
}

//isResizable
template <typename Data>
bool HashTableOpnAdr<Data>::IsResizable(unsigned long dim) const noexcept {
    if(dim > tableSize) {
        return true;
    } else {
        if(dim == tableSize) {
            return false;
        }
        ulong cap = (static_cast<double>(size)/static_cast<double>(dim))*100;
        if(cap < 75) {
            return true;
        }
        return false;
    } 

}

/* ************************************************************************** */

}