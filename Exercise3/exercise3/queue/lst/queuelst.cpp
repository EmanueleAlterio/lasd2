
namespace lasd {

/* ************************************************************************** */


// Copy assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data> :: operator=(const QueueLst &queueLst){
    List<Data> :: operator=(queueLst);
    return *this;
}


//Move assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data> :: operator=(QueueLst &&queueLst) noexcept {
    List<Data> :: operator=(std::move(queueLst));
    return *this;
}


//Comparison operator
template<typename Data>
bool QueueLst<Data> :: operator==(const QueueLst &queueLst) const noexcept{
    
    return List<Data> :: operator==(queueLst);
}


//Comparison operator
template<typename Data>
bool QueueLst<Data> :: operator!=(const QueueLst &queueLst) const noexcept{

    return List<Data> :: operator!=(queueLst);
}


 // Specific member functions (inherited from Queue)
template<typename Data>
const Data& QueueLst<Data> :: Head() const {
    return List<Data> :: Front();
}

template<typename Data>
Data& QueueLst<Data> :: Head(){
    return List<Data> :: Front();
}

template<typename Data>
void QueueLst<Data> :: Dequeue(){
    List<Data> :: RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data> :: HeadNDequeue(){
    return List<Data> :: FrontNRemove();
}

template<typename Data>
void QueueLst<Data> :: Enqueue(const Data & data){
    List<Data> :: InsertAtBack(data); 
}

template<typename Data>
void QueueLst<Data> :: Enqueue(Data && data) noexcept{ 
    List<Data> :: InsertAtBack(std::move(data)); 
}
/* ************************************************************************** */

}