#ifndef ASSIGNMENT8_MUL_H
#define ASSIGNMENT8_MUL_H

#include "BinaryNode.h"
#include <iostream>

class Mul : public BinaryNode {
public:
    Mul(Node* left, Node* right);

    [[nodiscard]] double evaluate() const override;

    void print(std::ostream& os) const override;

    [[nodiscard]] Node *clone() const override;

    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_MUL_H
