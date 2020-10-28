#ifndef ASSIGNMENT8_CONSTANT_H
#define ASSIGNMENT8_CONSTANT_H

#include "LeafNode.h"
#include <iostream>

/**
 * @brief Encapsulates a constant double value X
 */
class Constant : public LeafNode {
private:
    const double _val;
public:
    /**
     * @brief Creates a Constant class object
     * @param val Value of the Constant
     */
    explicit Constant(double val);

    /**
     * @brief Returns the value of the constant
     * @return Constant value
     * @throw Node::EvaluateException if a Node cannot be evaluated at runtime
     */
    [[nodiscard]] double evaluate() const override;

    /**
     * @brief Writes "_val" to a std::ostream
     * @param os The std::ostream to write to
     */
    void print(std::ostream& os) const override;

    /**
     * @brief Performs a deep copy of a Constant class object
     * @return Node* pointing to a deep copy of this Constant class object
     */
    [[nodiscard]] Node *clone() const override;

    /**
     * @brief Computes the derivative of a Constant class object
     * @details The derivative is computed as 0.0
     * @param variableName The variable name the derivative should be taken w.r.t
     * @return Node* pointing to the resulting derivative
     */
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
};


#endif //ASSIGNMENT8_CONSTANT_H
