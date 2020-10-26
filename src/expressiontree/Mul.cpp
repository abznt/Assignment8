#include "Mul.h"

Mul::Mul(Node *left, Node *right) : BinaryNode(left, right) {}

double Mul::evaluate() const {
    return left()->evaluate() * right()->evaluate();
}

void Mul::print(std::ostream &os) const {
    os << "(";
    left()->print(os);
    os << " * ";
    right()->print(os);
    os << ")";
}

Node *Mul::clone() const {
    return new Mul(left()->clone(), right()->clone());
}

Node *Mul::derivative(const std::string &variableName) const {
    return nullptr;
}


