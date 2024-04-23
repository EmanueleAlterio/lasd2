#include "list.hpp"
namespace lasd {

    //Specific constructor
    template<typename Data>
    List<Data>::Node::Node(const Data & data){
        element = data;
        next = nullptr;
    }

    template<typename Data>
    List<Data>::Node::Node(Data && data) noexcept{
        std::swap(element, data);
        next = nullptr;
    }

    //Copy Constructor
    template<typename Data>
    List<Data>::Node::Node(const Node & node){
        element = node.element;
        next = nullptr;
    }

    //Move Constructor
    template<typename Data>
    List<Data>::Node::Node(Node && node) noexcept{
        std::swap(element, node.element);
        std::swap(next, node.next);
    }

    //Copy Assignment
    template<typename Data>
    List<Data>::Node& List<Data>::Node:: operator=(const Node & node){
        if(this != &node){ 
            element = node.element;
            next = node.next;
        }

        return *this;
    }

    //Move Assignment
    template<typename Data>
    List<Data>::Node& List<Data>::Node:: operator=(Node && node) noexcept{
        if(this != &node){ 
            std::swap(element, node.element);
            std::swap(next, node.next);
        }

        return *this;
    }

    template<typename Data>
    List<Data>:: Node :: ~Node(){
        delete next;
    }


    //Comparison operator
    template<typename Data>
    bool List<Data>::Node::operator==(const Node &node)const noexcept{
        return (element == node.element) && 
            ((next == nullptr && node.next == nullptr) || 
            ((next != nullptr && node.next != nullptr) && *next == *(node.next)));
    }
    

    //Comparison operator
    template<typename Data>
    bool List<Data>::Node:: operator!=(const Node & node) const noexcept{
        return !(*this == node);
    }
    /* ************************************************************************** */


    //List

    //Specific Constructor
    template<typename Data>
    List<Data> :: List(const TraversableContainer<Data> & container){
        head = nullptr;
        tail = nullptr;

        container.Traverse(
            [this](const Data & data){
                InsertAtBack(data);
            }

        );
    }


    //Specific Constructor
    template<typename Data>
    List<Data> :: List(MappableContainer<Data> && container){
        head = nullptr;
        tail = nullptr;

        container.Map(
            [this](Data & data){
                InsertAtBack(std::move(data));
            }

        );
    }


    //Copy Constructor
    template<typename Data>
    List<Data>::List(const List & other){
        if(this != &other){
            if(other.head != nullptr){
                for(Node* curr = other.head; curr != nullptr; curr = curr->next){
                    InsertAtBack(curr->element);
                }
            }
        }
    }

    //Move Constructor
    template<typename Data>
    List<Data>::List(List && other) noexcept{
        if(this != &other){
                std::swap(head, other.head);
                std::swap(tail, other.tail);
                std::swap(size, other.size);
        }
    }

    // Destructor
    template<typename Data>
    List<Data>::~List(){
        delete head;
    }


    // Copy Assignment
    template<typename Data>
    List<Data>& List<Data>:: operator=(const List & other){
        if(this != &other){
            try
            {
                List<Data> *temp = new List<Data>(other);
                std::swap(*temp, *this);
                delete temp;
            }catch(std::bad_alloc &exception){
                std::cerr << "Cannot allocate memory " <<  exception.what();
            }

        }

        return *this;
    }



    //Move Assignment
    template<typename Data>
    List<Data>& List<Data>:: operator=(List && other) noexcept{
        if(this != &other){
            if(this != &other){
                std::swap(head, other.head);
                std::swap(tail, other.tail);
                std::swap(size, other.size);
                
            }
        }
        return *this;
    }


    //Comparison Operators
    template<typename Data>
    bool List<Data> :: operator==(const List & other) const noexcept{
        if(this == &other){
            return true;
        }

        if(size != other.size){
            return false;
        }

        return (size == other.size) &&
            ((head == nullptr && other.head == nullptr) || 
            ((head != nullptr && other.head != nullptr) && (*head == *(other.head)))); 
    }

    template<typename Data>
    bool List<Data> :: operator!=(const List & other) const noexcept{
        return !(*this == other);
    }

    // Specific member functions

    template<typename Data>
    void List<Data> :: InsertAtFront(const Data & data){

        try
        {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;

            if(tail == nullptr){
                tail = newNode;
            }

            size++;

        }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
        }

    }   

    template<typename Data>
    void List<Data> :: InsertAtFront(Data && data) noexcept{
        try
        {
            Node* newNode = new Node(std::move(data));
            newNode->next = head;
            head = newNode;

            if(tail == nullptr){
                tail = newNode;
            }

            size++;
        }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
        }
    }

    template<typename Data>
    void List<Data> :: RemoveFromFront(){
        if(head != nullptr){
            
            Node* tmp = head;
            
            if(head == tail){
                head = nullptr;
                tail = nullptr;
            }else{
                head = head->next;
            }

            size--;
            tmp->next = nullptr;
            delete tmp;

        }else{
            throw std::length_error("List is Empty");
        }
    }


    template<typename Data>
    Data List<Data> :: FrontNRemove(){
        if(head != nullptr){
            
            Data data = Front();
            List<Data>::RemoveFromFront();

            return data;

        }else{
            throw std::length_error("List is Empty");
        }
    }


    template<typename Data>
    void List<Data> :: InsertAtBack(const Data & data){
        
        try
        {
            Node* newNode = new Node(data);

            if(tail != nullptr){
                tail->next = newNode;
            }else{
                head = newNode;
            }

            tail = newNode;
            size++;
        }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
        }
        
    }


    template<typename Data>
    void List<Data> :: InsertAtBack(Data && data){
        try{
            Node* newNode = new Node(std::move(data));
            
            if(tail != nullptr){
                tail->next = newNode;
            }else{
                head = newNode;
            }

            tail = newNode;
            size++;
        }catch(std::bad_alloc &exception){
            std::cerr << "Cannot allocate memory " <<  exception.what();
        }
    }


    template<typename Data>
    void List<Data>::Clear(){
        while(head!=nullptr) {
            RemoveFromFront(); 
        }
        
    }

    template<typename Data>
    bool List<Data>::Insert(const Data & data){
        for(Node *tmp = head; tmp != nullptr; tmp = tmp->next){
            if(tmp->element == data){
                return false;
            }
        }
        
        InsertAtBack(data);
        return true;
    }


    template<typename Data>
    bool List<Data>::Insert(Data && data){
        for(Node *tmp = head; tmp != nullptr; tmp = tmp->next){
            if(tmp->element == data){   
                return false;
            }
        }

        InsertAtBack(std::move(data));
        return true;
    }

    template<typename Data>
    bool List<Data> :: Remove(const Data & data){
        if(head == nullptr)
            return false;

        if(head->element == data){
            RemoveFromFront();
            return true;
        }

        Node *prev = head;
        Node *curr = head->next;
        
        while(curr != nullptr && curr->element != data){
            prev = curr;
            curr = curr->next;
        }

        if(curr != nullptr){
            Node* tmp = curr;
            prev->next = curr->next;

            if(curr == tail)
                tail = prev;
            
            tmp->next = nullptr;
            delete tmp;
            size--;
            return true;

        }

        return false;
    }

    // [] operator
    template<typename Data>
    const Data& List<Data> :: operator[](const unsigned long index) const{
        if(index >= size){ //index essendo ulong non ha bisogno del controllo < 0 in quanto non può mai esserlo
            throw std::out_of_range("List index out of range");
        }

        if(index == size - 1){
            return tail->element;
        }

        Node* curr = head;
        for(unsigned long i = 0; i < index; i++,curr=curr->next){}
        
        return curr->element;
    }   


    // [] operator
   template<typename Data>
    Data& List<Data>::operator[](const unsigned long index){
        if(index >= size){
            throw std::out_of_range("List index out of range");
        }

       if(index == size - 1){
            return tail->element;
        }

        Node *curr = head;
        for(unsigned long i = 0; i < index ; i++){
            curr = curr->next;
        }

        return curr->element;
    }

    //Front
    template<typename Data>
    const Data& List<Data> :: Front() const{
        
        if(head == nullptr){
            throw std::length_error("List is Empty");
        }

        return head->element;

    }


    template<typename Data>
    Data& List<Data> :: Front(){
        
        if(head == nullptr){
            throw std::length_error("List is Empty");
        }

        return head->element;
    }


    //Back
    template<typename Data>
    const Data& List<Data>::Back() const{
        if(tail != nullptr){
            return tail->element;
        }

        throw std::length_error("List is empty");
    }
    
    template<typename Data>
    Data& List<Data>::Back(){
        if(tail != nullptr){
            return tail->element;
        }

        throw std::length_error("List is empty");
    }



   // Specific member function (inherited from TraversableContainer)
    template<typename Data>
    void List<Data>::Traverse(TraverseFun fun) const{
        PreOrderTraverse(fun, head);
    }
    
    template<typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun) const{
        PreOrderTraverse(fun, head);
    }

    template<typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun) const{
        PostOrderTraverse(fun, head);
    }

    // Specific member function (inherited from MappableContainer)

     template<typename Data>
    void List<Data>::Map(MapFun fun){
        PreOrderMap(fun, head);
    }
    
    template<typename Data>
    void List<Data>::PreOrderMap(MapFun fun){
        PreOrderMap(fun, head);
    }

    template<typename Data>
    void List<Data>::PostOrderMap(MapFun fun){
        PostOrderMap(fun, head);
    }

    // Auxiliary functions

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, const Node *node) const{
        if(node != nullptr){
            for( ; node != nullptr; node = node->next){
                fun(node->element);
            }
        }
    }

    template<typename Data>
    void List<Data> :: PostOrderTraverse(TraverseFun fun, const Node *node) const{
        if(node != nullptr){
            PostOrderTraverse(fun, node->next);
            fun(node->element);
        }
    }

    template <typename Data>
    void List<Data> :: PreOrderMap(MapFun fun, Node *node){
        if(node != nullptr){
            for( ; node != nullptr; node = node->next){
                fun(node->element);
            }
        }
    }

    template <typename Data>
    void List<Data> :: PostOrderMap(MapFun fun, Node *node){
        if(node != nullptr){
            PostOrderMap(fun, node->next);
            fun(node->element);
        }
    }
}
