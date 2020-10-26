#ifndef ASSIGNMENT8_NEGATIVE_H
#define ASSIGNMENT8_NEGATIVE_H

#include "UnaryNode.h"
#include <iostream>

class Negative : UnaryNode {
public:
    explicit Negative(Node* left);
    [[nodiscard]] double evaluate() const override;
    void print(std::ostream& os) const override;
    [[nodiscard]] Node *clone() const override;
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_NEGATIVE_H
