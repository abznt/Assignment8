#ifndef ASSIGNMENT8_DIV_H
#define ASSIGNMENT8_DIV_H

#include "BinaryNode.h"
#include <iostream>

class Div : public BinaryNode {
public:
    Div(Node* left, Node* right);

    [[nodiscard]] double evaluate() const override;

    void print(std::ostream& os) const override;

    [[nodiscard]] Node *clone() const override;

    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_DIV_H
