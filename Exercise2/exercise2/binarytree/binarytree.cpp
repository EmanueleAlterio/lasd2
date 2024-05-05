#include "binarytree.hpp"
namespace lasd {

/* ************************************************************************** */

// NODE

//Comparison opeartors

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& other) const noexcept {

    if (this->Element() != other.Element()){
        return false;
    }

        bool rChild = this->HasRightChild();
        bool lChild = this->HasLeftChild();
        bool otherRChild = other.HasRightChild();
        bool otherLChild = other.HasLeftChild();
        bool right = (rChild == otherRChild);
        bool left = (lChild == otherLChild);

        if(left && right) {
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
bool BinaryTree<Data>::Node::operator!=(const Node& other) const noexcept {
    return !(*this == other);
}


//BINARY TREE

//Comparison operators
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept {
    if(size == bt.size) {
        if(size == 0) {
            return true;
        } else {
            return (Root() == bt.Root());
        }
    }
    return false;
}


template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bt) const noexcept {
    return !(*this == bt);
}

template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const {
    if(size > 0){
        PreOrderTraverse(fun, &Root());
    }
}

template<typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const{
    if(size > 0){
        PreOrderTraverse(fun, &Root());
    }
}

template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const{
    if(size > 0){
        PostOrderTraverse(fun, &Root());
    }
}

template<typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const{
    if(size > 0){
        InOrderTraverse(fun, &Root());
    }
}

template<typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const{
    if(size > 0){
        BreadthTraverse(fun, &Root());
    }
}

//Auxiliary function

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const{
    if (node == nullptr){
        return;
    }

    fun(node->Element());

    if(node->HasLeftChild()){
        PreOrderTraverse(fun, &node->LeftChild());
    }

    if(node->HasRightChild()){
        PreOrderTraverse(fun, &node->RightChild());
    }


}


template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const{
    if (node == nullptr){
        return;
    }

    if(node->HasLeftChild()){
        PostOrderTraverse(fun, &node->LeftChild());
    }

    if(node->HasRightChild()){
        PostOrderTraverse(fun, &node->RightChild());
    }

    fun(node->Element());

}


template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node* node) const{
    if (node == nullptr){
        return;
    }

    if(node->HasLeftChild()){
        InOrderTraverse(fun, &node->LeftChild());
    }

    fun(node->Element());

    if(node->HasRightChild()){
        InOrderTraverse(fun, &node->RightChild());
    }

}


template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node* node) const{
    if (node == nullptr){
        return;
    }

    lasd::QueueVec<const Node*> q;
    if(node != nullptr){
        q.Enqueue(node);
    }

    while (!q.Empty()){
        fun(q.Head()->Element());

        
        if(q.Head()->HasLeftChild()){
            q.Enqueue(&(q.Head()->LeftChild()));
        }

        if(q.Head()->HasRightChild()){
            q.Enqueue(&(q.Head()->RightChild()));
        }

        q.Dequeue();
    }

}


//MUTABLE BINARYTREE

//Specific function

template <typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun){
    if(size>0) {
        PreOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun){
    if(size>0) {
        PreOrderMap(fun, &Root());
    }  
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun){
    if(size>0) {
        PostOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun){
    if(size>0) {
        InOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun){
    if(size>0) {
        BreadthMap(fun, &Root());
    }
}


// Auxiliary functions

template <typename Data>
 void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode* node){
    
    if (node == nullptr){
        return;
    }

    fun(node->Element());

    if(node->HasLeftChild()){
        PreOrderMap(fun, &node->LeftChild());
    }

    if(node->HasRightChild()){
        PreOrderMap(fun, &node->RightChild());
    }

 }

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode* node){
    if (node == nullptr){
        return;
    }

    if(node->HasLeftChild()){
        PostOrderMap(fun, &node->LeftChild());
    }

    if(node->HasRightChild()){
        PostOrderMap(fun, &node->RightChild());
    }

    fun(node->Element());

}


template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode* node){
    if (node == nullptr){
        return;
    }

    if(node->HasLeftChild()){
        InOrderMap(fun, &node->LeftChild());
    }

    fun(node->Element());

    if(node->HasRightChild()){
        InOrderMap(fun, &node->RightChild());
    }

}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode* node){
    if (node == nullptr){
        return;
    }

    lasd::QueueVec<MutableNode*> q;
    if(node != nullptr){
        q.Enqueue(node);
    }

    while (!q.Empty()){
        fun(q.Head()->Element());

        
        if(q.Head()->HasLeftChild()){
            q.Enqueue(&(q.Head()->LeftChild()));
        }

        if(q.Head()->HasRightChild()){
            q.Enqueue(&(q.Head()->RightChild()));
        }

        q.Dequeue();
    }

}

// BTPreOrderIterator

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator terminated!");
    }
    if(curr->HasRightChild()) {
        stk.Push(&(curr->RightChild()));
    }
    if(curr->HasLeftChild()) {
        stk.Push(&(curr->LeftChild()));
    }
    if(stk.Empty()) {
        curr = nullptr;
    } else {
        curr = stk.TopNPop();
    }
    return *this;
}


//BTPostOrderIterator

//Specific constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
      if(bt.Size() != 0) {
            curr = root = &bt.Root();
            getLeftMostLeaf();
        }
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
    if(Terminated()) {
        throw std::out_of_range("Iterator out of bounds");
    }
    if(stk.Empty()) {
        curr = nullptr;
    } else {
        if(stk.Top()->HasRightChild() && !(&stk.Top()->RightChild() == curr)) {
            curr = &stk.Top()->RightChild();
            getLeftMostLeaf();
        } else {
            curr = stk.TopNPop();
        }
    }
    return *this;
}


template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    curr = root;
    if(curr != nullptr){
        getLeftMostLeaf();
    }
    
}

template <typename Data>
void BTPostOrderIterator<Data>::getLeftMostLeaf() {
    while(curr->HasLeftChild()) {
        stk.Push(curr);
        curr = &curr->LeftChild();
    }
    if(curr->HasRightChild()) {
        stk.Push(curr);
        curr = &curr->RightChild();
        getLeftMostLeaf();
    }
}


//InOrderIterator

//Specific constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size()!=0) {
        curr = root = &bt.Root();
        getLeftMostNode();
    }
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator out of bounds");
    }

    if(curr->HasRightChild()) {
        curr = &(curr->RightChild());
        getLeftMostNode();
    } else {
        if(stk.Empty()) {
            curr = nullptr;
        } else {
            curr = stk.TopNPop();
        }
    }
    return *this;
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    curr = root;
    getLeftMostNode();
}

template <typename Data>
void BTInOrderIterator<Data>::getLeftMostNode() {
    if(curr == nullptr) {
        return;
    }
    
    while(curr->HasLeftChild()) {
        stk.Push(curr);
        curr = &curr->LeftChild();
    }
}


//BreadthIterator

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator out of bounds");
    }

    if(curr->HasLeftChild()) {
        que.Enqueue(&(curr->LeftChild()));
    }

    if(curr->HasRightChild()) {
        que.Enqueue(&(curr->RightChild()));
    }

    if(que.Empty()) {
        curr = nullptr;
    } else {
        curr = que.HeadNDequeue();
    }

    return *this;
}

/* ************************************************************************** */

}
