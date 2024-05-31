
#include "htclsadr.hpp"
namespace lasd {



template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){
    table = Vector<List<Data>>(MIN_TABLESIZE);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim){
    if(dim < MIN_TABLESIZE){
        dim = MIN_TABLESIZE;
    }

    if(dim > MAX_TABLESIZE){
        dim = MAX_TABLESIZE;
    }

    tableSize = dim;
    table = Vector<List<Data>>(tableSize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& con) : HashTableClsAdr(){
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim, const TraversableContainer<Data>& con) : HashTableClsAdr(dim) {
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& con): HashTableClsAdr(){
    InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim, MappableContainer<Data>&& con) : HashTableClsAdr(dim){
    InsertAll(std::move(con));
}


//Copy Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) : HashTable<Data>(ht){
    table.Resize(ht.tableSize);
    for (unsigned long i = 0; i < ht.tableSize; i++){
        table[i] = ht.table[i];
    }
}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept : HashTable<Data>(ht){
    std::swap(tableSize, ht.tableSize);
    std::swap(table, ht.table);
}


//Copy assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> & ht) {
    HashTableClsAdr<Data>* tmp = new HashTableClsAdr(ht);
    std::swap(*this, *tmp);
    acoeff = ht.acoeff;
    bcoeff = ht.bcoeff;
    delete tmp;

    return *this;
}


//Move assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize);
    std::swap(table, ht.table);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);

    return *this;
}


//Comparison Operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept{
    if (size != ht.size || tableSize != ht.tableSize){
        return false;
    }

    for (unsigned long i = 0; i < tableSize; i++) {
        for(unsigned long j = 0; j < table[i].Size(); j++){
            if(table[i].Size()!=0){
                
                unsigned long key = HashKey(table[i].operator[](j));
                if(!table[key].Exists(table[i].operator[](j))){
                    return false;
                }
                    
            }
        }
            
    }
    
    return true;
}

template<typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}


//Insert
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    unsigned long key = HashTable<Data>::HashKey(enchash(data));
    
    if(table[key].Insert(data)){
        size++;
        return true;
    }    
    
    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept{
    unsigned long key = HashTable<Data>::HashKey(enchash(data));
    
    if(table[key].Insert(std::move(data))){
        size++;
        return true;
    }    
    
    return false;
}

//Remove
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    unsigned long key = HashKey(enchash(data));

    if(table[key].Remove(data)){
        size--;
        return true;
    }

    return false;
}


//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept{
    unsigned long key = HashKey(enchash(data));
    return table[key].Exists(data);
}


//Resize
template <typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newsize){
    if(newsize < MIN_TABLESIZE || newsize > MAX_TABLESIZE){
        return;
    }

    HashTableClsAdr<Data>* tmp = new HashTableClsAdr<Data>(newsize);
    for(unsigned long i = 0; i < tableSize; i++){
        for(unsigned long j = 0; j < table[i].Size(); j++){
            if(table[i].Size() != 0){
                tmp->Insert(table[i].operator[](j));
            }
        }
    }

    std::swap(*this, *tmp);
    delete tmp;
}

//Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear(){
    size = 0;
    
    for(unsigned long i = 0; i < tableSize; i++){
        if(table[i].Size() != 0){
            table[i].Clear();
        }
    }
    
}



}
