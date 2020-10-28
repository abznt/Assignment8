#ifndef ASSIGNMENT8_POSITIVE_H
#define ASSIGNMENT8_POSITIVE_H

#include "UnaryNode.h"
#include <iostream>

/**
 * @brief Encapsulates the unary operator +A
 */
class Positive : public UnaryNode {
public:
    /**
     * @brief Creates a Positive class object with a single child Node
     * @param left Node pointer to the child
     */
    explicit Positive(Node* left);

    /**
     * @brief Performs the operation +A recursively
     * @return The value of +A
     * @throw Node::EvaluateException if a Node cannot be evaluated at runtime
     */
    [[nodiscard]] double evaluate() const override;

    /**
     * @brief Writes "(+A)" to a std::ostream
     * @param os The std::ostream to write to
     */
    void print(std::ostream& os) const override;

    /**
     * @brief Performs a deep copy of a Positive class object
     * @return Node* pointing to a deep copy of this Positive class object
     */
    [[nodiscard]] Node *clone() const override;

    /**
     * @brief Recursively computes the derivative of a Positive class object
     * @details The derivative is computed as +du
     * @param variableName The variable name the derivative should be taken w.r.t
     * @return Node* pointing to the resulting derivative
     */
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_POSITIVE_H
