#ifndef ASSIGNMENT8_NODE_H
#define ASSIGNMENT8_NODE_H

#include <iostream>
#include <exception>
#include <string>

class Node {
private:
    Node* _left;
    Node* _right;

protected:
    explicit Node(Node* left = nullptr, Node* right = nullptr);

public:
    virtual ~Node() {
        delete _left;
        delete _right;
    }

    [[nodiscard]] Node* left() const { return _left; }

    [[nodiscard]] Node* right() const { return _right; }

    [[nodiscard]] virtual double evaluate() const = 0;
    virtual void print(std::ostream& os) const = 0;
    [[nodiscard]] virtual Node* clone() const = 0;
    [[nodiscard]] virtual Node* derivative(const std::string& variableName) const = 0;

    class EvaluateException : public std::exception {
    private:
        std::string _msg;

    public:
        explicit EvaluateException(std::string msg) : _msg{std::move(msg)} {};
        [[nodiscard]] std::string msg() const {
            return "EvaluateException: " + _msg;
        }
    };
};

inline std::ostream& operator<<(std::ostream& os, const Node& node) {
    node.print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Node* node) {
    node->print(os);
    return os;
}

#endif //ASSIGNMENT8_NODE_H
