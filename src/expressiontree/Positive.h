#ifndef ASSIGNMENT8_POSITIVE_H
#define ASSIGNMENT8_POSITIVE_H

#include "UnaryNode.h"
#include <iostream>

class Positive : public UnaryNode {
public:
    explicit Positive(Node* left);
    [[nodiscard]] double evaluate() const override;
    void print(std::ostream& os) const override;
    [[nodiscard]] Node *clone() const override;
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_POSITIVE_H
