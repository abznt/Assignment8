#include "Div.h"

Div::Div(Node *left, Node *right) : BinaryNode(left, right) {}

double Div::evaluate() const {
    return left()->evaluate() / right()->evaluate();
}

void Div::print(std::ostream &os) const {
    os << "(";
    left()->print(os);
    os << " / ";
    right()->print(os);
    os << ")";
}

Node *Div::clone() const {
    return new Div(left()->clone(), right()->clone());
}

Node *Div::derivative(const std::string &variableName) const {
    return nullptr;
}
