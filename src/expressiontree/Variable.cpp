#include "Variable.h"
#include "Constant.h"
#include <cmath>

Variable::Variable(const std::string& name) : LeafNode(), _name{name} {
    if (!Variable::exists(name)) {
        _variableValuesByName[name] = std::nan(""); // initialize key but don't assign any value
        _variableReferenceCount[name] = 1; // initialize reference count
    }
    else {
        _variableReferenceCount[name]++;
    }
}

Variable::~Variable() {
    // If the variable reference count is >1, decrement the reference count. Otherwise, delete the entries for the
    // variable in variableReferenceCount and variableValuesByName
    if (_variableReferenceCount[_name] > 1) {
        _variableReferenceCount[_name]--;
    }
    else {
        _variableReferenceCount.erase(_name);
        _variableValuesByName.erase(_name);
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
