#include "ExpressionTree.h"

ExpressionTree::ExpressionTree(Node *root) : _root(root) {}

ExpressionTree::ExpressionTree(ExpressionTree &tree) : _root(tree.root()->clone()) {}

ExpressionTree ExpressionTree::derivative(const std::string &variableName) const {
    return ExpressionTree(_root->derivative(variableName));
}