#ifndef ASSIGNMENT8_BINARYNODE_H
#define ASSIGNMENT8_BINARYNODE_H

#include "Node.h"
#include <iostream>

/**
 * @brief Abstract class encapsulating a binary node. Contains pointers to left and right child nodes.
 */
class BinaryNode : public Node {
protected:
    /**
     * @brief Protected constructor. Creates a BindaryNode with left and right child nodes.
     * @param left Node pointer to a left child.
     * @param right Node pointer to a right child.
     */
    BinaryNode(Node* left, Node* right);
};


#endif //ASSIGNMENT8_BINARYNODE_H
