#include "binarytreevec.hpp"

namespace lasd {

/* ************************************************************************** */

//NODEVEC

//Specific constructor

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& data, unsigned long index, Vector<NodeVec*> *v){
    info = data;
    curr = index;
    tree = v;
}

//Copy assignment

template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node){
    info = node.info;
    curr = node.curr;
    tree = node.tree;
    return *this;
}

//Move assignment
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
    std::swap(info, node.info);
    std::swap(curr, node.curr);
    std::swap(tree, node.tree);
    return *this;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return info;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return info;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::isLeaf() const noexcept{
    return ((2*curr+1) > tree->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    return ((2*curr+1) < tree->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    return ((2*curr+2) < tree->Size());
}

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(!HasLeftChild()){
        throw std::out_of_range("There is no left child");
    }

    return *(tree->operator[](2*curr+1));
}

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if(!HasRightChild()){
        throw std::out_of_range("There is no right child");
    }

    return *(tree->operator[](2*curr+2));
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(!HasLeftChild()) {
        throw std::out_of_range("There is no left child");
    }

    return *(tree->operator[](2*curr+1));
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(!HasRightChild()) {
        throw std::out_of_range("There is no right child");
    }
    
    return *(tree->operator[](2*curr+2));
}


//BINARY TREE VECTOR

//Specific constructors

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container){
    size = container.Size();
    if(size > 0){
        vec = new Vector<NodeVec*>(size);
        unsigned long index = 0;
        container.Traverse([this, &index](const Data& data){
            NodeVec* node = new NodeVec(data, index, vec);
            vec->operator[](index) = node;
            index++;
        });
    }
}


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& container) noexcept{
    size = container.Size();
    if(size > 0){
        vec = new Vector<NodeVec*>(size);
        unsigned long index = 0;
        container.Map([this, &index](Data& data){
            NodeVec* node = new NodeVec(data, index, vec);
            vec->operator[](index) = node;
            index++;
        });
    }
}

//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& bt){
    size = bt.Size();
    if(size > 0){
        vec = new Vector<NodeVec*>(size);
        for(unsigned long i=0; i<size; i++){
            NodeVec* tmp = new NodeVec(bt.vec->operator[](i)->Element(), i, vec);
            vec->operator[](i) = tmp;
        }
    }
}

//Move constructor

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& bt) noexcept {
    std::swap(size, bt.size);
    std::swap(vec, bt.vec);
}


//Destructor

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();
    delete vec;
    vec = nullptr;
}


//Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& bt){
    BinaryTreeVec<Data>* temp = new BinaryTreeVec<Data>(bt);
    std::swap(*this, *temp);
    delete temp;
    
    return *this;
}

//Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& bt) noexcept {
    std::swap(size, bt.size);
    std::swap(vec, bt.vec);

    return *this;
}


template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if(size == 0) {
        throw std::length_error("Empty tree");
    }

    return *(vec->operator[](0));
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root(){
    if(size == 0) {
        throw std::length_error("Empty tree");
    }

    return *(vec->operator[](0));
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    if(size > 0){
        for(unsigned long i=0; i<size; i++){
            if(vec->operator[](i) != nullptr){
                delete (*vec)[i];
            }
        }
        vec->Clear();
        size = 0;
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const{
    for(unsigned long i=0; i<size; i++){
        if(vec->operator[](i) != nullptr){
            fun(vec->operator[](i)->Element());
        }
    }
}


template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun){
    for(unsigned long i=0; i<size; i++){
        if(vec->operator[](i) != nullptr){
            fun(vec->operator[](i)->Element());
        }
    }
}


/* ************************************************************************** */

}
