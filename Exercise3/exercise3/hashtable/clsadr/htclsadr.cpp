#include "htclsadr.hpp"
#include "../../zmytest/test.hpp"
#include <iostream>
namespace lasd {

/* ************************************************************************** */

// Default Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = Vector<List<Data>> (MIN_TABLESIZE);
}

/* ************************************************************************** */

// Specific Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize) {
    if(givenSize < MIN_TABLESIZE) {
        givenSize = MIN_TABLESIZE;
    }
    else if(givenSize >= MAX_TABLESIZE) {
        givenSize = MAX_TABLESIZE;
    }
    else{
        givenSize = FindNextPrime(givenSize);   
    }
    tableSize = givenSize;
    table.Resize(givenSize);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container){
    unsigned long givenSize = 0;
    if(container.Size() < MIN_TABLESIZE) {
        givenSize = MIN_TABLESIZE;
    }
    else if(container.Size() >= MAX_TABLESIZE) {
        givenSize = MAX_TABLESIZE;
    }
    else{
        givenSize = FindNextPrime(container.Size());   
    }
    tableSize = givenSize;
    table.Resize(givenSize);
    InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, const TraversableContainer<Data>& container){
    if(givenSize < MIN_TABLESIZE) {
        givenSize = MIN_TABLESIZE;
    }
    else if(givenSize >= MAX_TABLESIZE) {
        givenSize = MAX_TABLESIZE;
    }
    else{
        givenSize = FindNextPrime(givenSize);   
    }
    tableSize = givenSize;
    table.Resize(givenSize);
    InsertAll(container);
}


template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container){
    unsigned long givenSize = 0;
    if(container.Size() < MIN_TABLESIZE) {
        givenSize = MIN_TABLESIZE;
    }
    else if(container.Size() >= MAX_TABLESIZE) {
        givenSize = MAX_TABLESIZE;
    }
    else{
        givenSize = FindNextPrime(container.Size());   
    }
    tableSize = givenSize;
    table.Resize(givenSize);
    InsertAll(std::move(container));
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, MappableContainer<Data>&& container){
    if(givenSize < MIN_TABLESIZE) {
        givenSize = MIN_TABLESIZE;
    }
    else if(givenSize >= MAX_TABLESIZE) {
        givenSize = MAX_TABLESIZE;
    }
    else{
        givenSize = FindNextPrime(givenSize);   
    }
    tableSize = givenSize;
    table.Resize(givenSize);
    InsertAll(std::move(container));
}

/* ************************************************************************** */

// Copy and Move Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht){
    size = ht.size;
    tableSize = ht.tableSize;
    acoeff = ht.acoeff;
    bcoeff = ht.bcoeff;
    table = ht.table;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);
    std::swap(table, ht.table);
}

/* ************************************************************************** */

// Copy and Move Assigments - HashTableClsAdr

template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht){
    HashTableClsAdr<Data>* tmpht = new HashTableClsAdr(ht);
    std::swap(*this, *tmpht);
    delete tmpht;
    return *this;
}

template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(table, ht.table);
    std::swap(tableSize, ht.tableSize);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);
    return *this;
}

/* ************************************************************************** */

// Copy and Move Assigments - HashTableClsAdr

template<typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept{
    if(size == ht.size){

        for(unsigned long i = 0; i < table.Size(); i++){
            if(table[i].Size() == ht.table[i].Size()){
                for(unsigned long j = 0; j < table[i].Size() && table[i].Size() != 0; j++){
                    unsigned long index = ht.HashKey(table[i].operator[](j));
                    if(!table[index].Exists(table[i].operator[](j))){
                        return false;
                    }
                }
            }
            else{
                return false; 
            }
        }
        return true;

    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept{
    return !(*this == ht);
}

/* ************************************************************************** */

// Specific Member Functions - HashTableClsAdr

template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    unsigned long index = HashKey(data);
    if(table[index].Insert(data)){
        size++;
        return true;
    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept{
    unsigned long index = HashKey(std::move(data));
    if(table[index].Insert(std::move(data))){
        size++;
        return true;
    }
    return false;
} 

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    unsigned long index = HashKey(data);
    if(table[index].Remove(data)){
        size--;
        return true;
    }
    return false;
}


template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    unsigned long index = HashKey(data);
    return table[index].Exists(data);
}


template<typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newSize){
    if(newSize < MIN_TABLESIZE){        
        newSize = MIN_TABLESIZE;
    }
    else if(newSize > MAX_TABLESIZE){
        newSize = MAX_TABLESIZE;
    }
    else{
        newSize = FindNextPrime(newSize);
    }
    Vector<List<Data>> table2(table);
    table.Clear();
    table.Resize(newSize);
    tableSize = newSize;
    size = 0;
    // for (unsigned long i = 0; i < table2.Size(); i++){
    //     for (Node* it = table[i].Front(); it != nullptr; it = it->next){
    //         Insert(*(it)->data);
    //     }
    // }
    for(unsigned long i = 0; i < table2.Size(); i++){
        for(unsigned long j = 0; j < table2[i].Size() && table2[i].Size() != 0; j++){
            Insert(table2[i].operator[](j));
        }
    }
}


template<typename Data>
void HashTableClsAdr<Data>::Clear() {
    table.Clear();
    table.Resize(MIN_TABLESIZE);
    tableSize = MIN_TABLESIZE;
    size = 0;
}


template <typename Data>
unsigned long HashTableClsAdr<Data>::FindNextPrime(unsigned long val) const noexcept {
    for (ulong i = 2; i <= val/2; ++i) {
        if (val % i == 0) {
            val+=1;
            i = 2;
        }
    }
    return val;
}

/* ************************************************************************** */

}