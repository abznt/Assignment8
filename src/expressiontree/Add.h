#ifndef ASSIGNMENT8_ADD_H
#define ASSIGNMENT8_ADD_H

#include "Node.h"
#include "BinaryNode.h"
#include <iostream>

class Add : public BinaryNode {
public:
    Add(Node* left, Node* right);

    [[nodiscard]] double evaluate() const override;

    void print(std::ostream& os) const override;

    [[nodiscard]] Node* clone() const override;

    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_ADD_H
