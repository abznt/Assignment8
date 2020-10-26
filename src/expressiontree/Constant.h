#ifndef ASSIGNMENT8_CONSTANT_H
#define ASSIGNMENT8_CONSTANT_H

#include "LeafNode.h"
#include <iostream>

class Constant : public LeafNode {
private:
    const double _val;
public:
    explicit Constant(double val);

    [[nodiscard]] double evaluate() const override;

    void print(std::ostream& os) const override;

    [[nodiscard]] Node *clone() const override;

    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_CONSTANT_H
