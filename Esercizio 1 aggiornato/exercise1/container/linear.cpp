
namespace lasd {
 
    /* ************************************************************************** */
    // LinearContainer


    // Comparison operators
    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data>& container)const noexcept{
        if(size == container.size){
            for(unsigned long i = 0; i < size; i++){
                if(operator[](i) != container.operator[](i)){
                    return false;
                }
            }
            return true;
        }

        return false;
    }

    template <typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& container) const noexcept{
        return !(operator==(container));
    }

    /* ************************************************************************** */
    // Specific member functions

    template <typename Data>
    const Data& LinearContainer<Data>::Front() const{
        if (size > 0){
            return operator[](0);
        
        }
         
        throw std::length_error("Linear container is empty");
    }

    template <typename Data>
    Data& LinearContainer<Data>::Front(){
        if (size > 0){
            return operator[](0);
        }
         
        throw std::length_error("Linear container is empty");
    }

    template <typename Data>
    const Data& LinearContainer<Data>::Back() const{
        if (size > 0){
            return operator[](size - 1);
        }

        throw std::length_error("Linear container is empty");
    }

    template <typename Data>
    Data& LinearContainer<Data>::Back(){
        if (size > 0){
            return operator[](size - 1);
        }

        throw std::length_error("Linear container is empty");
    }

    /* ************************************************************************** */
    // Specific member function (inherited from TraversableContainer, PreOrderTraversableContainer, PostOrderTraversableContainer)
    
    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun fun) const {
        PreOrderTraverse(fun);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const{
        for(unsigned long i = 0; i < size; i++){
            fun(operator[](i));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const{
        for (unsigned long i = size; i > 0; i--) {
            fun(operator[](i - 1));
        }
    }

    /* ************************************************************************ */
    // Specific member function (inherited from MappableContainer, PreOrderMappableContainer, PostOrderMappableContainer)

    template <typename Data>
    void LinearContainer<Data>::Map(MapFun fun){
        PreOrderMap(fun);
    }

    template <typename Data>
    void LinearContainer<Data>::PreOrderMap(MapFun fun){
        for(unsigned long i = 0; i < size; i++){
            fun(operator[](i));
        }
    }

    template <typename Data>
    void LinearContainer<Data>::PostOrderMap(MapFun fun){
        for(unsigned long i = size - 1; i >= 0; i--){
            fun(operator[](i));
        }
    }

    /* ************************************************************************** */
    // SortableLinearContainer 
    // Comparison operators
    template <typename Data>
    bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data>& container)const noexcept{
        return LinearContainer<Data>::operator==(container);
    }

    template <typename Data>
    bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data>& container) const noexcept{
        return !(operator==(container));
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
}