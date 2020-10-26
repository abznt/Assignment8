#ifndef ASSIGNMENT8_EXPRESSIONTREE_H
#define ASSIGNMENT8_EXPRESSIONTREE_H

#include "Node.h"
#include <iostream>

class ExpressionTree {
private:
    Node* _root;

public:
    ExpressionTree(Node* root);

    ExpressionTree(ExpressionTree* tree);

    ~ExpressionTree() {
        delete _root;
    };

//    ExpressionTree& operator=(Node* root) {
//        _root = root;
//        return *this;
//    };

    [[nodiscard]] Node* root() const {
        return _root;
    };

    [[nodiscard]] double evaluate() const {
        return _root->evaluate();
    };

    [[nodiscard]] ExpressionTree* derivative(const std::string& variableName) const;
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
