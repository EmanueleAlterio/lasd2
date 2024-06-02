
namespace lasd {

/* ************************************************************************** */

// Default Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = Vector<List<Data>> (MIN_TABLESIZE);
    tableSize = MIN_TABLESIZE;
}

/* ************************************************************************** */

// Specific Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim) {
    if(dim < MIN_TABLESIZE) {
        dim = MIN_TABLESIZE;
    }
    
    if(dim >= MAX_TABLESIZE) {
        dim = MAX_TABLESIZE;
    }

    tableSize = dim;
    table.Resize(dim);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container){
    unsigned long dim = 0;
    if(container.Size() < MIN_TABLESIZE) {
        dim = MIN_TABLESIZE;
    }
    
    if(container.Size() >= MAX_TABLESIZE) {
        dim = MAX_TABLESIZE;
    }

    tableSize = dim;
    table.Resize(dim);
    InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim, const TraversableContainer<Data>& container){
    if(dim < MIN_TABLESIZE) {
        dim = MIN_TABLESIZE;
    }
    
    if(dim >= MAX_TABLESIZE) {
        dim = MAX_TABLESIZE;
    }

    tableSize = dim;
    table.Resize(dim);
    InsertAll(container);
}


template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container){
    unsigned long dim = 0;
    if(container.Size() < MIN_TABLESIZE) {
        dim = MIN_TABLESIZE;
    }
    
    if(container.Size() >= MAX_TABLESIZE) {
        dim = MAX_TABLESIZE;
    }

    tableSize = dim;
    table.Resize(dim);
    InsertAll(std::move(container));
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long dim, MappableContainer<Data>&& container){
    if(dim < MIN_TABLESIZE) {
        dim = MIN_TABLESIZE;
    }
    
    if(dim >= MAX_TABLESIZE) {
        dim = MAX_TABLESIZE;
    }

    tableSize = dim;
    table.Resize(dim);
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
    HashTableClsAdr<Data>* tmp = new HashTableClsAdr(ht);
    std::swap(*this, *tmp);
    delete tmp;
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
    bool exists = true;

    if(size != ht.size){
        return false;
    }

    for(unsigned long i = 0; i < table.Size(); i++){
        for(unsigned long j = 0; j < table[i].Size() && table[i].Size() != 0; j++){
            for(unsigned long k = 0; k < ht.table.Size(); k++){
                exists &= ht.Exists(table[i].operator[](j));
            }
        }
    }

    return exists;
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
    
    if(newSize > MAX_TABLESIZE){
        newSize = MAX_TABLESIZE;
    }

    Vector<List<Data>> newtable(table);
    table.Clear();
    table.Resize(newSize);
    tableSize = newSize;
    size = 0;

    for(unsigned long i = 0; i < newtable.Size(); i++){
        for(unsigned long j = 0; j < newtable[i].Size() && newtable[i].Size() != 0; j++){
            Insert(newtable[i].operator[](j));
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




/* ************************************************************************** */

}