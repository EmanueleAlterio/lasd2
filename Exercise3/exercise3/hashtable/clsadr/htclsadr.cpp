#include "htclsadr.hpp"
namespace lasd {

/* ************************************************************************** */

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){
    table = Vector<BST<Data>>(tableSize);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim){
    if(dim < MIN_TABLESIZE){
        dim = MIN_TABLESIZE;
    }

    if(dim > MAX_TABLESIZE){
        dim = MAX_TABLESIZE;
    }

    tableSize = con.Size();
    table = Vector<BST<Data>>(tableSize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& con){
    table = Vector<BST<Data>>(tableSize);
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim, const TraversableContainer<Data>& con) : HashTableClsAdr(dim) {
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& con){
    table = Vector<BST<Data>>(tableSize);
    InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim, MappableContainer<Data>&& con) : HashTableClsAdr(dim){
    InsertAll(std::move(con));
}


//Copy Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) : HashTable<Data>(ht){
    if(ht.size == 0){
        Clear();
        return;
    }

    table = Vector<BST<Data>>(tableSize);
    for(unsigned long i=0; i < ht.tableSize; i++){
        if(ht.table[i].Size()!=0){
            BTInOrderIterator<Data> it(ht.table[i]);
            while(!it.Terminated()){
                Insert(it.operator*());
                it.operator++;
            }
        }
    }
}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(tableSize, ht.tableSize);
    std::swap(table, ht.table);
    std::swap(acoeff, ht.acoeff);
    std::swap(bcoeff, ht.bcoeff);

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
    if (size != ht.size || tablesize != ht.tablesize){
        return false;
    }

    for (ulong i = 0; i < tableSize; i++) {
            if(table[i].Size()!=0){
                BTInOrderIterator<Data> it(table[i]);
                while (!it.Terminated()) {
                    if (!ht.Exists(it.operator*())){
                        return false;
                    }
                    it.operator++();
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
bool HashTableClsAdr<Data>::Insert(Data&& data){
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
        if(table[i].Size() != 0){
            BTInOrderIterator<Data> it(table[i]);
            while (!(it.Terminated())){
                Data dat = it.operator*();
                tmp->Insert(dat);
                it.operator++;
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
/* ************************************************************************** */

}
