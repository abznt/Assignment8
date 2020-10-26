#include "Add.h"

Add::Add(Node *left, Node *right) : BinaryNode(left, right) {}

double Add::evaluate() const {
    return left()->evaluate() + right()->evaluate();
}

void Add::print(std::ostream &os) const {
    os << "(";
    left()->print(os);
    os << " + ";
    right()->print(os);
    os << ")";
}

Node *Add::clone() const {
    return new Add(left()->clone(), right()->clone());
}

Node *Add::derivative(const std::string &variableName) const {
    return nullptr;
}
