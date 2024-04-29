

namespace lasd {

/* ************************************************************************** */

//Specific Constructor
template<typename Data>
Vector<Data> :: Vector(const unsigned long initialSize){
    try{
        size = initialSize;
        elements = new Data[size];

    }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
    }
}

template<typename Data>
Vector<Data> :: Vector(const TraversableContainer<Data> & traversableCon){
    try{
        size = traversableCon.Size();
        elements = new Data[size];

        unsigned long i = 0;
        traversableCon.Traverse(
            [this, &i](const Data & data){
                elements[i++] = data;
            }
        );

    }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
    }
}

template<typename Data>
Vector<Data> :: Vector(MappableContainer<Data> && mappableCon){
    try{
        size = mappableCon.Size();
        elements = new Data[size];

        unsigned long i = 0;
        mappableCon.Map(
            [this, &i](Data & data){
                elements[i++] = std::move(data);
            }
        );
    }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory "<<  exception.what();
    }
}


//Copy Constructor
template<typename Data>
Vector<Data>::Vector(const Vector & other){
    try{
        size = other.size;
        elements = new Data[size];

        std::copy(other.elements, other.elements + size, elements);

    }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
    }
}


//Move Constructor
template<typename Data>
Vector<Data>::Vector(Vector && other) noexcept{
        std::swap(elements, other.elements); 
        std::swap(size, other.size);
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
                Vector<Data> *tmp = new Vector<Data>(vec);
                std::swap(*tmp, *this);

                delete tmp;
                return *this;
                
            }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
            }
        }

        return *this;
    }

//Move Assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector &&other) noexcept{

    std::swap(size, other.size);
    std::swap(elements, other.elements); 

    return *this;
}

//Comparison Operators
template<typename Data>
bool Vector<Data>::operator==(const Vector &vec) const noexcept{
    if(this == &vec){
        return true;
    }

    if(size != vec.size){
        return false;
    }

    for(unsigned long i = 0; i < size; i++){
        if(elements[i] != vec.elements[i]){
            return false;
        }
    }
    
    return true;
}

template<typename Data>
bool Vector<Data>::operator!=(const Vector & vec) const noexcept{
    return !(*this == vec);
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

            
            unsigned long min = std::min(size, new_size);

            for(unsigned long i=0; i<min; i++){
                std::swap(elements[i], tmp[i]);
            }

            std::swap(elements, tmp); 
            size = new_size;  
            delete[] tmp; 

        }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
        }
        
        
    } else if(new_size == 0){
        Clear();
    }
    
    
}

//OP[]
template<typename Data>
const Data& Vector<Data> :: operator[](const unsigned long index) const{
    if(index >= size){
        throw std:: out_of_range("index out of bounds");
    }
    
    return elements[index];
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long index){
    if(index >= size){
        throw std::out_of_range("index out of range");
    }

    return elements[index];
    
}


//Front
template<typename Data>
const Data& Vector<Data>::Front() const{
    if(size == 0){
        throw std::length_error("Empty Vector");   
    }

    return elements[0];
}

template<typename Data>
Data& Vector<Data>::Front(){
    if(size == 0){
        throw std::length_error("Empty Vector");
    }
    return elements[0];
    
}

//Back
template<typename Data>
const Data& Vector<Data>::Back() const{
    if(size == 0){
        throw std::length_error("Empty Vector");
    }
    return elements[size-1];
    
}

template<typename Data>
Data& Vector<Data>::Back(){
    if(size == 0){
        throw std::length_error("Empty Vector");
    }

    return elements[size-1];
}

    
/* ************************************************************************** */

/*SortableVector*/

   // Specific constructors
    template<typename Data>
    SortableVector<Data>::SortableVector(const unsigned long newSize):Vector<Data>(newSize){}

    template<typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data>& container):Vector<Data>(container){}

    template<typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data>&& container):Vector<Data>(std::move(container)){}

    //Copy and Move constructor
    template<typename Data>
    SortableVector<Data>::SortableVector(const SortableVector &vec):Vector<Data>(vec){}

    template<typename Data>
    SortableVector<Data>::SortableVector(SortableVector &&vec) noexcept :Vector<Data>(std::move(vec)){}
    
    // Copy and Move assignment
    template<typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector &vec){
        Vector<Data>::operator=(vec);

        return *this;
    }

    template<typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector &&vec) noexcept{
        Vector<Data>::operator=(std::move(vec));

        return *this;
    }

}
