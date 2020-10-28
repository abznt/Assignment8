#ifndef ASSIGNMENT8_EXPRESSIONTREE_H
#define ASSIGNMENT8_EXPRESSIONTREE_H

#include "Node.h"
#include <iostream>

/**
 * @brief Encapsulates an expression tree as a rooted Node
 */
class ExpressionTree {
private:
    Node* _root;

public:
    /**
     * @brief Creates an ExpressionTree class object from a root Node
     * @param root Pointer to a Node
     */
    ExpressionTree(Node* root);

    /**
     * @brief Creates an ExpressionTree class object from an existing ExpressionTree by performing a deep copy
     * @param tree Existing ExpressionTree
     */
    ExpressionTree(ExpressionTree& tree);

    /**
     * @brief Destructor that deletes the root Node*
     */
    ~ExpressionTree() {
        delete _root;
    };

    /**
     * @brief Gets a pointer to the root node
     * @return Node* pointing to the root node
     */
    [[nodiscard]] Node* root() const {
        return _root;
    };

    /**
     * @brief Evaluates an ExpressionTree class object recursively
     * @return The value of the ExpressionTree
     * @throw Node::EvaluateException if a Node in the tree cannot be evaluated at runtime
     */
    [[nodiscard]] double evaluate() const {
        return _root->evaluate();
    };

    /**
     * @brief Recursively computes the derivative of an ExpressionTree class object
     * @param variableName The variable name the derivative should be taken w.r.t
     * @return ExpressionTree* pointing to the resulting derivative
     */
    [[nodiscard]] ExpressionTree derivative(const std::string& variableName) const;
};

inline std::ostream& operator<<(std::ostream& os, const ExpressionTree& tree) {
    tree.root()->print(os);
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const ExpressionTree* tree) {
    tree->root()->print(os);
    return os;
}

#endif //ASSIGNMENT8_EXPRESSIONTREE_H
