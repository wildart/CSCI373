#pragma once

#include <algorithm>
#include "BinaryNode.h"

template <typename Type>
class AdvancedBinaryNode : public BinaryNode {
protected:
    AdvancedBinaryNode<Type> *parent_node;
    int tree_height;

    void update_height();

public:
    AdvancedBinaryNode( const Type& , AdvancedBinaryNode<Type>* = nullptr,
                        AdvancedBinaryNode<Type>* = nullptr, AdvancedBinaryNode<Type>* = nullptr );

    bool is_root() const;
    AdvancedBinaryNode<Type>* parent() const;
    int height() const;

    friend class BinaryTree<Type>;
};

template <typename Type>
AdvancedBinaryNode<Type>::AdvancedBinaryNode( const Type &e, AdvancedBinaryNode<Type>* p,
                                              AdvancedBinaryNode<Type>* l, AdvancedBinaryNode<Type>* r):
    parent{p}, BinaryNode(e, l, r) {} // empty constructor

template <typename Type>
AdvancedBinaryNode<Type>* AdvancedBinaryNode<Type>::parent() const {
    return parent_node;
}

template <typename Type>
bool AdvancedBinaryNode<Type>::is_root() const {
    return (parent_node == nullptr);
}

template <typename Type>
int AdvancedBinaryNode<Type>::height() const {
    return ( this == nullptr ) ? -1 : tree_height;
}

template <typename Type>
void AdvancedBinaryNode<Type>::update_height() {
    tree_height = std::max( left_tree->height(), right_tree->height() ) + 1;
}
