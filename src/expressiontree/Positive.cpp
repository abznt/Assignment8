#include "Positive.h"

Positive::Positive(Node *left) : UnaryNode(left) {}

double Positive::evaluate() const {
    return 1.0 * left()->evaluate();
}

void Positive::print(std::ostream &os) const {
    os << "(+";
    left()->print(os);
    os << ")";
}

Node *Positive::clone() const {
    return new Positive(left()->clone());
}

Node *Positive::derivative(const std::string &variableName) const {
    return nullptr;
}
