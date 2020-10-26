#ifndef ASSIGNMENT8_SUB_H
#define ASSIGNMENT8_SUB_H

#include "BinaryNode.h"
#include <iostream>

class Sub : public BinaryNode {
public:
    Sub(Node* left, Node* right);

    [[nodiscard]] double evaluate() const override;

    void print(std::ostream& os) const override;

    [[nodiscard]] Node *clone() const override;

    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_SUB_H
