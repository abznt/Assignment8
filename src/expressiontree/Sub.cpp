#include "Sub.h"

Sub::Sub(Node *left, Node *right) : BinaryNode(left, right) {}

double Sub::evaluate() const {
    return left()->evaluate() - right()->evaluate();
}

void Sub::print(std::ostream &os) const {
    os << "(";
    left()->print(os);
    os << " - ";
    right()->print(os);
    os << ")";
}

Node *Sub::clone() const {
    return new Sub(left()->clone(), right()->clone());
}

Node *Sub::derivative(const std::string &variableName) const {
    return new Sub(left()->derivative(variableName), right()->derivative(variableName));
}
