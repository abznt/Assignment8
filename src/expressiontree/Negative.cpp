#include "Negative.h"

Negative::Negative(Node *left) : UnaryNode(left) {}

double Negative::evaluate() const {
    return -1 * left()->evaluate();
}

void Negative::print(std::ostream &os) const {
    os << "(-";
    left()->print(os);
    os << ")";
}

Node *Negative::clone() const {
    return new Negative(left()->clone());
}

Node *Negative::derivative(const std::string &variableName) const {
    return new Negative(left()->derivative(variableName));
}
