
namespace lasd {

/* ************************************************************************** */

//Specific constructors
template <typename Data>
BST<Data>::BST(const TraversableContainer<Data>& container){
    container.Traverse([this](const Data& data){
        Insert(data);
    });
}


template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& container) noexcept {
    container.Map([this](Data & data){
        Insert(std::move(data));
    });
}

//Comparison operators
template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept {
    if(size != bst.Size()) {
        return false;
    }

    if(size == 0) {
        return true;
    }

    BTInOrderIterator<Data> itr1(*this);
    BTInOrderIterator<Data> itr2(bst);
    while(!itr1.Terminated() && !itr2.Terminated()) {
        if(*itr1 != *itr2) {
            return false;
        }
        ++itr1;
        ++itr2;
    }

    if(!itr1.Terminated() || !itr2.Terminated()) {
        return false;
    }

    return true;

}

template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}


//Specific functions

//Min
template <typename Data>
const Data& BST<Data>::Min() const {
    if(root == nullptr) {
        throw std::length_error("BST is empty");  
    }

    return FindPointerToMin(root)->info;
}



//MinNRemove
template <typename Data>
Data BST<Data>::MinNRemove() {
    if(root == nullptr) {
       throw std::length_error("BST is empty");
    }

    return DataNDelete(DetachMin(root));
}


//RemoveMin
template <typename Data>
void BST<Data>::RemoveMin() {
    if(root == nullptr) {
        throw std::length_error("BST is empty");
    } 

    delete DetachMin(root);
}


//Max
template <typename Data>
const Data& BST<Data>::Max() const {
    if(root == nullptr) {
        throw std::length_error("BST is empty");
    } 

    return FindPointerToMax(root)->info;
}

//MaxNRemove
template <typename Data>
Data BST<Data>::MaxNRemove() {
    if(root == nullptr) {
        throw std::length_error("BST is empty");
    } 

    return DataNDelete(DetachMax(root));
}

//RemoveMax
template <typename Data>
void BST<Data>::RemoveMax() {
    if(root == nullptr) {
        throw std::length_error("BST is empty");
    }

    delete DetachMax(root);
}

//Predecessor
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const {
    NodeLnk* const * tmp = FindPointerToPredecessor(root, data);
    if(tmp == nullptr) {
        throw std::length_error("Predecessor not found");
    }

    return (*tmp)->info;
}

//PredecessorNRemove
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data) {
    NodeLnk** tmp = FindPointerToPredecessor(root, data);
    if(tmp == nullptr) {
        throw std::length_error("Predecessor not found");
    }

    return DataNDelete(Detach(*tmp));
}


//RemovePredecessor
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data) {
    NodeLnk** tmp = FindPointerToPredecessor(root, data);
    if(tmp == nullptr) {
        throw std::length_error("Predecessor not found");
    } 

    delete Detach(*tmp);
}



//Successor
template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const {
    NodeLnk* const * tmp = FindPointerToSuccessor(root, data);
    if(tmp == nullptr) {
        throw std::length_error("Successor not found");
    }

    return (*tmp)->info;
}

//SuccessorNRemove
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data) {
    NodeLnk** tmp = FindPointerToSuccessor(root, data);
    if(tmp == nullptr) {
        throw std::length_error("Successor not found");
    }

    return DataNDelete(Detach(*tmp));
}

//RemoveSuccessor
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data) {
    NodeLnk** tmp = FindPointerToSuccessor(root, data);
    if(tmp == nullptr) {
        throw std::length_error("Successor not found");
    }

    delete Detach(*tmp);
}

//Insert
template <typename Data>
bool BST<Data>::Insert(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp != nullptr) {
        return false;
    } 

    tmp = new NodeLnk(data);
    size++;
    return true;
}

//Insert move
template <typename Data>
bool BST<Data>::Insert(Data&& data) noexcept {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp != nullptr) {
        return false;
    } 

    tmp = new NodeLnk(std::move(data));
    size++;
    return true;
}

//Remove
template <typename Data>
bool BST<Data>::Remove(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp == nullptr) {
        return false;
    }

    delete Detach(tmp);
    return true;
}

//Exists
template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept {
    return (FindPointerTo(root, data) != nullptr);
}


//DataNDelete
template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data data{};
    std::swap(data, node->info);
    delete node;
    return data;
}

//Detach
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept {
    if(node != nullptr) {
        if(node->left == nullptr) {
            return Skip2Right(node);
        } else if(node->right == nullptr) {
            return Skip2Left(node);
        } else {
            NodeLnk* tmp = DetachMax(node->left);
            std::swap(node->info, tmp->info);
            return tmp;
        }
    }
    return nullptr;
}

//DetachMin
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept {
    return Skip2Right(FindPointerToMin(node));
}

//DetachMax
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept {
    return Skip2Left(FindPointerToMax(node));
}

//Skip2Left
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->left);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}

//Skip2Right
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->right);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}


//FindPointerToMin 
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* cur = node;
    if(cur != nullptr) {
        while(cur->left != nullptr) {
            tmp = &cur->left;
            cur = cur->left;
        }
    }
    return *tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
}


//FindPointerToMax 
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* cur = node;
    if(cur != nullptr) {
        while(cur->right != nullptr) {
            tmp = &cur->right;
            cur = cur->right;
        }
    }
    return *tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
}

//FindPointerTo
template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * tmp = &node;
    if(*tmp != nullptr) {
        if(node->info == data) {
            return *tmp;
        }
        else if(node->info < data) {
            tmp = &(FindPointerTo(node->right, data));
        }
        else {
            tmp = &(FindPointerTo(node->left, data));
        }
    }
    return *tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, data));
}


//FindPointerToPredecessor
template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToPredecessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * cur = &node;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->info != data) {
        if((*cur)->info < data) {
            tmp = cur;
            cur = &((*cur)->right);
        }
        else if((*cur)->info > data) {
            cur = &((*cur)->left);
        }
    }

    if(*cur != nullptr && (*cur)->HasLeftChild()) {
        return &FindPointerToMax((*cur)->left);
    }

    return tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, data));
}


//FindPointerToSuccessor
template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * cur = &node;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->info != data) {
        if((*cur)->info > data) {
            tmp = cur;
            cur = &((*cur)->left);
        }
        else if((*cur)->info < data) {
            cur = &((*cur)->right);
        }
    }

    if(*cur != nullptr && (*cur)->HasRightChild()) {
        return &FindPointerToMin((*cur)->right);
    }

    return tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
}

/* ************************************************************************** */

}