#include "Constant.h"

Constant::Constant(double val) : LeafNode(), _val{val} {}

double Constant::evaluate() const {
    return _val;
}

void Constant::print(std::ostream &os) const {
    os << _val;
}

Node *Constant::clone() const {
    return new Constant(_val);
}

Node *Constant::derivative(const std::string& variableName) const {
    return new Constant(0.0);
}
