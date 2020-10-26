#include "Variable.h"
#include "Constant.h"
#include <cmath>

Variable::Variable(const std::string& name) : LeafNode(), _name{name} {
    if (!Variable::exists(name)) {
        _variableValuesByName[name] = std::nan(""); // initialize key but don't assign any value
        std::cout << "Adding variable named '" << name << "' to internal map.\n";
    }
    else {
        std::cout << "Variable name '" << name << "' already exists in internal map.\n";
    }
}

double Variable::evaluate() const {
    double value = Variable::getVariableValue(_name);
    if (std::isnan(value)) {
        throw Node::EvaluateException("variable '" + _name + "' has no assigned value");
    }
    else {
        return value;
    }
}

void Variable::print(std::ostream &os) const {
    os << _name;
}

Node *Variable::clone() const {
    return new Variable(_name);
}

bool Variable::exists(const std::string& nameKey) {
    if (_variableValuesByName.find(nameKey) != _variableValuesByName.end()) {
        return true;
    }
    else {
        return false;
    }
}

void Variable::setVariableValue(const std::string& nameKey, double val) {
    if (Variable::exists(nameKey)) {
        _variableValuesByName[nameKey] = val;
    }
    else {
        throw Variable::VariableException("Could not find variable '" + nameKey + "'");
    }
}

double Variable::getVariableValue(const std::string& nameKey) {
    if (Variable::exists(nameKey)) {
        return _variableValuesByName[nameKey];
    }
    else {
        throw Variable::VariableException("Could not find variable '" + nameKey + "'");
    }
}

Node *Variable::derivative(const std::string &variableName) const {
    if (variableName == _name) {
        return new Constant(1.0);
    }
    else {
        return new Constant(0.0);
    }
}
