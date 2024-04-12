#include "list.hpp"
namespace lasd {

/* ************************************************************************** */

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
    List<Data>::Node::Node(Node && node){
        std:swap(element, node.element);
        std:swap(next, node.next);
    }

    //Copy Assignment
    template<typename Data>
    List<Data>::Node& List<Data>::Node:: operator=(const Node & node){
        if(this != &node){ //Controlla se gli indirizzi di memoria sono gli stessi
            element = node.element
            next = node.next;
        }

        return *this;
    }

    //Move Assignment
    template<typename Data>
    List<Data>::Node& List<Data>::Node:: operator=(Node && node) noexcept{
        if(this != &node){ //Controlla se gli indirizzi di memoria sono gli stessi
            std::swap(element, node.element);
            std::swap(next, node.next);
        }

        return *this;
    }

    template<typename Data>
    List<Data>:: Node :: ~Node(){
        delete next;
    }

    template<typename Data>
    bool List<Data>::Node:: operator==(const Node & node) const noexcept{
        return (element == node.element) &&
            ((next == nullptr && node.next == nullptr) || ((next != nullptr && node.next != nullptr) && *next == *(node.next))); //Viene confrontato il nodo successivo richiamando ricorsivamente ==
    }

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
            [this](const Data & Data){
                InsertAtBack(data);
            }

        );
    }

    template<typename Data>
    List<Data> :: List(MappableContainer<Data> && container){
        head = nullptr;
        tail = nullptr;

        container.Map(
            [this](const Data & Data){
                InsertAtBack(std::move(data));
            }

        );
    }

    //Copy Constructor
    template<typename Data>
    List<Data>::List(const List & other){
        if(this != &other){
            if(list.head != nullptr){
                for(Node* curr = list.head; curr != nullptr; curr = curr->next){
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
            }
            catch(std::bad_alloc)
            {
                std:: cerr << "[EXCEPTION] Cannot allocate memory for list";
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
        if(this == &other)
            return true;

        if(size != other.size)
            return false;
        
        return (size == other.size) &&
            ((head == nullptr && other.head == nullptr) || ((head != nullptr && other.head != nullptr) && (*head == *(other.head)))); //Utilizza l'operatore == dei confronti dei nodi
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

        }catch(std::bad_alloc){
            std::cerr <<"[EXCEPTION] Cannot allocate memory for List";
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
        }
        catch(std::bad_alloc){
            std::cerr <<"[EXCEPTION] Cannot allocate memory for List";
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
    Data& List<Data> :: FrontNRemove(){
        if(head != nullptr){
            
            Data data = head->element;
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
            }

            if(head == nullptr){
                head = newNode;
            }

            tail = newNode;
            size++;
        }
        catch(std::bad_alloc)
        {
            std::cerr <<"[EXCEPTION] Cannot allocate memory for List";
        }
        
    }


    template<typename Data>
    void List<Data> :: InsertAtBack(Data && data){
        try{
            Node* newNode = new Node(std::move(data));
            
            if(tail != nullptr){
                tail->next = newNode;
            }

            if(head == nullptr){
                head = newNode;
            }

            tail = newNode;
            size++;
        }
        catch(const std::exception& e){
            std::cerr <<"[EXCEPTION] Cannot allocate memory for List";
        }
    }


    template<typename Data>
    void List<Data> :: Clear(){
        
        while(head != nullptr){
            Node* tmp = head->next;
            delete head;
            head = tmp;
        }

        size = 0;
        tail = nullptr;

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

        if(head->element == data)
            RemoveFromFront();
            return true;

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


    template<typename Data>
    const Data& List<Data> :: operator[](const unsigned long index) const{
        if(index >= size){ //index essendo ulong non ha bisogno del controllo < 0 in quanto non può mai esserlo
            throw std::out_of_range("[EXCEPTION]: List index out of range");
        }

        if(index == size - 1)
            return tail->element;
        
        Node* curr = head;
        for(i = 0; i < index; i++){
            curr = curr->next;
        }
        
        return curr->element;
    }   


    template<typename Data>
    Data& List<Data> :: operator[](const unsigned long){
        
        if(index >= size){ //index essendo ulong non ha bisogno del controllo < 0 in quanto non può mai esserlo
            throw std::out_of_range("[EXCEPTION]: List index out of range");
        }

        if(index == size - 1 && tail != nullptr)
            return tail->element;
        
        Node* curr = head;
        for(i = 0; i < index; i++){
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
    const Data& List<Data> :: Back() const{

        if(tail != nullptr){
            throw std::length_error("List is Empty");
        }

        return tail->element;

    }

    template<typename Data>
    Data& List<Data> :: Back(){

        if(tail != nullptr){
            throw std::length_error("List is Empty");
        }

        return tail->element;

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