#ifndef ASSIGNMENT8_UNARYNODE_H
#define ASSIGNMENT8_UNARYNODE_H

#include "Node.h"

/**
 * @brief Abstract class encapsulating a unary node. Maintains a pointer to the left child node. The right child node
 * is set to nullptr.
 */
class UnaryNode : public Node {
protected:
    /**
     * @brief Protected constructor. Creates a UnaryNode with a single child and stores it as the left child. The right
     * child is set to nullptr.
     * @param left Node pointer to the child.
     */
    UnaryNode(Node* left);
};


#endif //ASSIGNMENT8_UNARYNODE_H
