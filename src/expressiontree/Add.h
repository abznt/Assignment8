#ifndef ASSIGNMENT8_ADD_H
#define ASSIGNMENT8_ADD_H

#include "Node.h"
#include "BinaryNode.h"
#include <iostream>

/**
 * @brief Encapsulates the addition of two child nodes A and B.
 */
class Add : public BinaryNode {
public:
    /**
     * @brief Creates an Add node with a left and right child Node.
     * @param left Node pointer to a left child
     * @param right Node pointer to a right child
     */
    Add(Node* left, Node* right);

    /**
     * @brief Performs the operation A + B recursively
     * @return The value of A + B
     * @throw Node::EvaluateException if a Node cannot be evaluated at runtime
     */
    [[nodiscard]] double evaluate() const override;

    /**
     * @brief Writes "(A + B)" to a std::ostream
     * @param os The std::ostream to write to
     */
    void print(std::ostream& os) const override;

    /**
     * @brief Performs a deep copy of an Add class object.
     * @return Node* pointing to a deep copy of this Add class object
     */
    [[nodiscard]] Node* clone() const override;

    /**
     * @brief Recursively computes the derivative of an Add class object.
     * @details The derivative is computed as du + dv
     * @param variableName The variable name the derivative should be taken w.r.t
     * @return Node* pointing to the resulting derivative
     */
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_ADD_H
