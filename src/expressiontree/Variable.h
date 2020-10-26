#ifndef ASSIGNMENT8_VARIABLE_H
#define ASSIGNMENT8_VARIABLE_H

#include "LeafNode.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <exception>
#include <utility>

class Variable : public LeafNode {
private:
    inline static std::unordered_map<std::string, double> _variableValuesByName;
    std::string _name;

public:
    explicit Variable(const std::string& name);
    [[nodiscard]] double evaluate() const override;
    void print(std::ostream& os) const override;
    [[nodiscard]] Node *clone() const override;
    [[nodiscard]] Node *derivative(const std::string& variableName) const override;
    static bool exists(const std::string& nameKey);
    static void setVariableValue(const std::string& nameKey, double val);
    static double getVariableValue(const std::string& nameKey);

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
