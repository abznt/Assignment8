#ifndef ASSIGNMENT8_NODE_H
#define ASSIGNMENT8_NODE_H

#include <iostream>
#include <exception>
#include <string>

/**
 * @brief Abstract class encapsulating a Node. Provides common protoyptes for implementing expression tree operations.
 */
class Node {
private:
    Node* _left;
    Node* _right;

protected:
    /**
     * @brief Protected default constructor. Only classes that inherit Node should be able to construct it.
     * @param left Node pointer to left child. Defaults to nullptr.
     * @param right Node pointer to right child. Defaults to nullptr.
     */
    explicit Node(Node* left = nullptr, Node* right = nullptr);

public:
    /**
     * @brief Virtual destructor that deletes pointer to the left and right children.
     */
    virtual ~Node() {
        delete _left;
        delete _right;
    }

    /**
     * @brief Gets a pointer to the left child Node
     * @return Node* pointing to the left child Node
     */
    [[nodiscard]] Node* left() const { return _left; }

    /**
     * @brief Gets a pointer to the right child Node
     * @return Node* pointing to the right child Node
     */
    [[nodiscard]] Node* right() const { return _right; }

    /**
     * @brief Pure virtual function prototype for evaluating a Node
     * @return The result of evaluating a node
     * @throw Node::EvaluateException if a Node cannot be evaluated at runtime
     */
    [[nodiscard]] virtual double evaluate() const = 0;

    /**
     * @brief Pure virtual function prototype for writing a Node to an std::ostream
     * @param os The std::ostream to write to
     */
    virtual void print(std::ostream& os) const = 0;

    /**
     * @brief Pure virtual function prototype for performing a deep copy of a Node
     * @return Node* pointing to a deep copy of this Node class object
     */
    [[nodiscard]] virtual Node* clone() const = 0;

    /**
     * @brief Pure virtual function prototype for computing the derivative of a Node
     * @param variableName The variable name the derivative should be taken w.r.t.
     * @return Node* pointing to the resulting derivative
     */
    [[nodiscard]] virtual Node* derivative(const std::string& variableName) const = 0;

    /**
     * Exception class that should be thrown if a Node cannot be evaluated.
     */
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
