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

}
