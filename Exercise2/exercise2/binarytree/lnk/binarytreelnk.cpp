#include "binarytreelnk.hpp"
namespace lasd {

/* ************************************************************************** */

// NODE

//Specific constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data){
    info = data;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& data) noexcept{
    std::swap(info, data);
}

//Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nodelnk){
    info = nodelnk.info;

    if(nodelnk.left != nullptr){
        left = new NodeLnk(*nodelnk.left);
    }

    if(nodelnk.right != nullptr){
        right = new NodeLnk(*nodelnk.right);
    }
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nodelnk) noexcept{
    std::swap(info, nodelnk.info);
    std::swap(left, nodelnk.left);
    std::swap(right, nodelnk.right);
}

//Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk:: ~NodeLnk(){
    delete left;
    delete right;
}

//Copy assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nodelnk) {
    NodeLnk* tmp = new NodeLnk(nodelnk.info);

    if(nodelnk.HasLeftChild()){
        left = nodelnk.left;
    }

    if(nodelnk.HasRightChild()){
        right = nodelnk.right;
    }

    return *tmp;

}

//move assignment
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept {
    std::swap(info, node.info);
    std::swap(left, node.left);
    std::swap(right, node.right);
    return *this;
}


//Comparison operators
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& other) const noexcept {

    if (info != other.info){
        return false;
    }

        bool rChild = this->HasRightChild();
        bool lChild = this->HasLeftChild();
        bool otherRChild = other.HasRightChild();
        bool otherLChild = other.HasLeftChild();

        if(lChild == otherLChild && rChild == otherRChild) {
            if(lChild && rChild) {
                return((LeftChild() == other.LeftChild()) && (RightChild() == other.RightChild()));
            } else if(lChild) {
                return(LeftChild() == other.LeftChild());
            } else if(rChild) {
                return(RightChild() == other.RightChild());
            } else {
                return true;
            }
        }

    return false;
    
}


template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& node) const noexcept {
    return !(*this == node);
}


//Functions

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return info;
}

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return info;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::isLeaf() const noexcept{
    return (!HasLeftChild() && !HasRightChild());
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (left != nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (right != nullptr);
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(left == nullptr) {
        throw std::out_of_range("Left child does not exists");    
    }
    return *left;
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(right == nullptr) {
        throw std::out_of_range("Right child does not exists");
    }
    return *right;
}


template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(left == nullptr) {
        throw std::out_of_range("Left child does not exists"); 
    } 
    return *left;
    
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(right == nullptr) {
        throw std::out_of_range("Right child does not exists");
    }
    return *right;
    
}

//BINARY LINK TREE

//Specific constructors
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& container) {
    size = container.Size();

    if(size == 0){
        root = nullptr;
        return;
    }

    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    container.Traverse([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(data);
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& container) {
    size = container.Size();

    if(size == 0){
        root = nullptr;
        return;
    }
    
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    container.Map([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(std::move(data));
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}

//Copy constructor

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& bt) {
    size = bt.Size();
    if(bt.Size() > 0) {
        root = Copy(bt.root);
    }
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& bt) noexcept : BinaryTreeLnk<Data>() {
    std::swap(size, bt.size);
    std::swap(root, bt.root);
}

//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& bt) {
    if(bt.Size() > 0) {
        BinaryTreeLnk<Data>* tmp = new BinaryTreeLnk<Data>(bt);
        std::swap(*tmp, *this);
        delete tmp;
    } else {
        Clear();
    }
    return *this;
}

//Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& bt) noexcept {
    std::swap(root, bt.root);
    std::swap(size, bt.size);
    return *this;
}


//Comparison operators

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& bt) const noexcept {
    return BinaryTree<Data>::operator==(bt);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& bt) const noexcept {
    return !(*this == bt);
}

//Specific functions

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if(root == nullptr) {
        throw std::length_error("Tree is empty");
    }
    
    return *root;
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if(root == nullptr) {
        throw std::length_error("Tree is empty");
    } 
    
    return *root;

}


template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    size = 0;
    root = nullptr;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Copy(NodeLnk* node) {
    NodeLnk* tmp = nullptr;

    if(node != nullptr) {
        tmp = new NodeLnk(node->info);
    }
    if(node->left != nullptr) {
        tmp->left = Copy(node->left);
    }
    if(node->right != nullptr) {
        tmp->right = Copy(node->right);
    }
    return tmp;
}
/* ************************************************************************** */

}
