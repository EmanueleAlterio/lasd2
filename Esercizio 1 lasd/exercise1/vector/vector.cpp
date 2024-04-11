
#include "vector.hpp"

namespace lasd {

/* ************************************************************************** */
/*vector*/

//Specific Constructor
template<typename Data>
Vector<Data> :: Vector(const unsigned long initialSize){
    try{
        size = initialSize;
        elements = new Data[size];

    }catch(std::bad_alloc){

        delete[] elements;
        elements = nullptr;

        std::cerr << "[EXCEPTION] Cannot allocate memory for Vector.";
    }
}

template<typename Data>
Vector<Data> :: Vector(const TraversableContainer<Data> & traversableCon){
    try{
        size = traversableCon.size;
        elements = new Data[size];

        unsigned long i = 0;
        traversableCon.Traverse(
            [this, &i](const Data & data){
                elements[i++] = data;
            }
        );

    }catch(std::bad_alloc){

        delete[] elements;
        elements = nullptr;

        std::cerr << "[EXCEPTION] Cannot allocate memory for Vector.";
    }
}

template<typename Data>
Vector<Data> :: Vector(MappableContainer<Data> && mappableCon){
    try{
        size = mappableCon.size;
        elements = new Data[size];

        unsigned long i = 0;
        mappableCon.Map(
            [this, &i](Data & data){
                elements[i++] = std::move(data);
            }
        );
    }catch(std::bad_alloc){

        delete[] elements;
        elements = nullptr;

        std::cerr << "[EXCEPTION] Cannot allocate memory for Vector.";
    }
}


//Copy Constructor
template<typename Data>
Vector<Data>::Vector(const Vector & other){
    try{
        size = other.size;
        elements = new Data[size];

        std::copy(other.elements, other.elements + size, elements);

    }catch(std::bad_alloc){

        delete[] elements;
        elements = nullptr;

        std::cerr << "[EXCEPTION] Cannot allocate memory for Vector";
    }
}


//Move Constructor
template<typename Data>
Vector<Data>::Vector(Vector && other) noexcept{
        std::swap(elements, other.elements); //Scambia i puntatori agli elementi 
        std::swap(size, other.size); //Scambia i valori delle size degli oggetti
}


//Destructor
template<typename Data>
Vector<Data> :: ~Vector(){
    delete[] elements;
    elements = nullptr;
}

//Copy Assignment
 template<typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector &vec){
        if(this != &vec){
            try{
                Vector<Data> tmp = new Vector<Data>(vec);
                std::swap(*tmp, *this);

                delete tmp;
            }catch(std::bad_alloc){
                std::cerr << "[EXCEPTION] Cannot allocate memory for Vector";
            }
        }

        return *this;
    }

//Move Assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector &&other) noexcept{

    std::swap(elements, other.elements); //Scambia i puntatori agli elementi
    std::swap(size, other.size);//Scambia le dimensioni dei vettori 

    return *this;
}

//Comparison Operators
template<typename Data>
bool Vector<Data> :: operator==(const Vector & other) const noexcept{

    if (size != other.size)
        return false;
    
    for(unsigned long i=0; i<size; i++){
        if(elements[i] != other.elements[i]){
            return false;
        }

    }

    return true;
}

template<typename Data>
bool Vector<Data> :: operator!=(const Vector & other) const noexcept{
    return !(*this == other);
}



//Clear function
template<typename Data>
void Vector<Data> :: Clear() {

    delete[] elements;
    elements = nullptr;
    size = 0;

}


//Reize function
template<typename Data>
void Vector<Data> :: Resize(const unsigned long new_size) {
    

    if (size != new_size && new_size > 0 ){
        try
        {
            Data* tmp = new Data[new_size];

            
            unsigned long min = std::min(size, new_size); //copia dei valori del vecchio vettore nel vettore temporaneo

            for(unsigned long i=0; i<min; i++){
                std::swap(elements[i], tmp[i]);
            }

            std::swap(elements, tmp); //scambia i valori dei due puntatori
            size = new_size; //aggiornamento della dimensione 
            delete[] tmp; //elimina il vettore temp
        }
        catch(std::bad_alloc)
        {
            std::cerr << "[EXCEPTION] Cannot allocate memory for Vector";
        }
        
        
    } else if(new_size == 0){
        Clear();
    }
    
    
}

//OP[]
template<typename Data>
const Data& Vector<Data> :: operator[](const unsigned long index) const{
    if(index < 0 || index >= size)
        throw std:: out_of_range("[EXCEPTION] index out of bounds");
    
    return elements[index];
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long index){
    if(index < 0 || index >= size){
        throw std::out_of_range("[EXCEPTION]: Vector index out of range");
    }

    return elements[index];
    
}


//Front
template<typename Data>
const Data& Vector<Data>::Front() const{
    if(size > 0){
        return elements[0];
    }

    throw std::length_error("[EXCEPTION]: Empty Vector");
}

template<typename Data>
Data& Vector<Data>::Front(){
    if(size > 0){
        return elements[0];
    }

    throw std::length_error("[EXCEPTION]: Empty Vector");
}

//Back
template<typename Data>
const Data& Vector<Data>::Back() const{
    if(size > 0){
        return elements[size-1];
    }

    throw std::length_error("[EXCEPTION]: Empty Vector");
}

template<typename Data>
Data& Vector<Data>::Back(){
    if(size > 0){
        return elements[size-1];
    }

    throw std::length_error("[EXCEPTION]: Empty Vector");
}

    
/* ************************************************************************** */

/*SortableVector*/

// Specific constructors
template<typename Data>
SortableVector<Data> :: SortableVector(const unsigned long initialSize){
    try
    {
        size = initialSize;
        elements = new Data[size];
    }
    catch(std::bad_alloc)
    {
        std::cerr << "[EXCEPTION] Cannot allocate memory for SortableVector" ;
    }
    
}

template<typename Data>
SortableVector<Data> :: SortableVector(const TraversableContainer<Data> & container){
    try
    {
        size = container.size;
        elements = new Data[size];

        unsigned long i = 0;
        container.Traverse(
            [this, &i](const Data &data){
                elements[i++] = data;
            }
        );     
    }
    catch(std:: bad_alloc)
    {
        std::cerr << "[EXCEPTION] Cannot allocate memory for SortableVector" ;    
    }
    
}

template<typename Data>
SortableVector<Data> :: SortableVector(MappableContainer<Data> && mappableCon){
    try
    {
        size = mappableCon.size;
        elements = new Data[size];

        unsigned long i = 0;
        mappableCon.Map(
            [this, &i](Data & data){
                elements[i++] = std::move(data);
            }
        );
    }
    catch(std::bad_alloc)
    {
        std::cerr << "[EXCEPTION] Cannot allocate memory for SortableVector" ;
    }
    
}

// Copy constructor
template<typename Data>
SortableVector<Data> ::SortableVector(const SortableVector & other){
    try{
        size = other.size;
        elements = new Data[size];

        std::copy(other.elements, other.elements + size, elements);

    }catch(std::bad_alloc){

        delete[] elements;
        elements = nullptr;

        std::cerr << "[EXCEPTION] Cannot allocate memory for SortableVector";
    }

}


// Move constructor
template<typename Data>
SortableVector<Data>::SortableVector(SortableVector &&other) noexcept{
    std::swap(elements, other.elements);
    std::swap(size, other.size);
}   

// Copy assignmemt
template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector &other){
    if(this != &other){
        try{
            SortableVector<Data> tmp = new SortableVector<Data>(other);
            std::swap(*tmp, *this);

            delete tmp;
        }catch(std::bad_alloc &exception){
            std::cerr << "[EXCEPTION] Cannot allocate memory for SortableVector";
        }
    }

    return *this;
}



// Move assignment
template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector &&other) noexcept{
    std::swap(elements, other.elements);
    std::swap(size, other.size);

    return *this;
}

}
