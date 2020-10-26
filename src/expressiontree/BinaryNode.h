#ifndef ASSIGNMENT8_BINARYNODE_H
#define ASSIGNMENT8_BINARYNODE_H

#include "Node.h"
#include <iostream>

class BinaryNode : public Node {
protected:
    BinaryNode(Node* left, Node* right);
};


#endif //ASSIGNMENT8_BINARYNODE_H
