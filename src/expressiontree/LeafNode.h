#ifndef ASSIGNMENT8_LEAFNODE_H
#define ASSIGNMENT8_LEAFNODE_H

#include "Node.h"
#include <iostream>

/**
 * @brief Abstract class encapsulating a leaf node. Contains no child nodes (left and right child nodes  are both set
 * to nullptr)
 */
class LeafNode : public Node {
protected:
    /**
     * @brief Protected constructor. Creates a LeafNode with no children.
     */
    LeafNode();
};


#endif //ASSIGNMENT8_LEAFNODE_H
