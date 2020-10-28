#ifndef ASSIGNMENT8_VARIABLE_H
#define ASSIGNMENT8_VARIABLE_H

#include "LeafNode.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <exception>
#include <utility>

/**
 * @brief Encapsulates a named variable V that has an assignable value
 */
class Variable : public LeafNode {
private:
    inline static std::unordered_map<std::string, double> _variableValuesByName;
    inline static std::unordered_map<std::string, int> _variableReferenceCount;
    std::string _name;

public:
    /**
     * @brief Creates a Variable class object with a name and sets its value to NaN in static storage
     * @param name The variable name
     */
    explicit Variable(const std::string& name);

    /**
     * @brief Non-trivial destructor that removes the variable from static storage if the reference count is below 1
     */
    ~Variable();

    /**
     * @brief Returns the value of a variable if it has been set
     * @return The variable value
     * @throw Node::EvaluateException if the variable value has not been set
     */
    [[nodiscard]] double evaluate() const override;

    /**
     * @brief Writes "_name" to a std::ostream
     * @param os The std::ostream to write to
     */
    void print(std::ostream& os) const override;

    /**
     * @brief Performs a deep copy of a Variable class object
     * @return Node* pointing to a deep copy of this Variable class object
     */
    [[nodiscard]] Node *clone() const override;

    /**
     * @brief Computes the derivative of a Variable class object
     * @details Computes the derivative as 1.0 if variableName matches _name, otherwise, computes the derivative as 0.0
     * @param variableName The variable name the derivative should be taken w.r.t
     * @return Node* pointing to the resulting derivative
     */
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;

    /**
     * @brief Checks if a variable exists in static storage
     * @param nameKey Variable name
     * @return True if the variable exists, false otherwise
     */
    static bool exists(const std::string& nameKey);

    /**
     * @brief Assigns a double value to a variable
     * @param nameKey Variable name
     * @param val Variable value
     * @throw Variable::VariableException if the variable doesn't exist in static storage
     */
    static void setVariableValue(const std::string& nameKey, double val);

    /**
     * @brief Gets the double value of a variable
     * @param nameKey Variable name
     * @return Variable value
     * @throw Variable::VariableException if the variable doesn't exist in static storage
     */
    static double getVariableValue(const std::string& nameKey);

    /**
     * @brief Exception class that should thrown if a Variable doesn't exist
     */
    class VariableException : std::exception {
    private:
        std::string _msg;

    public:
        explicit VariableException(std::string msg) : _msg{std::move(msg)} {};

        [[nodiscard]] std::string msg() const {
            return "VariableException: " + _msg;
        }
    };
};


#endif //ASSIGNMENT8_VARIABLE_H
