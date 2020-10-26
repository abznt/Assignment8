#include "ExpressionTree.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "Constant.h"
#include "Variable.h"
#include <iostream>

/**
 * @brief Main entry point for the program
 */
int main()
{
    // Create the expression 2.3 * X + Y * (Z - X)
    ExpressionTree t = new Add(
            new Mul(new Constant(2.3), new Variable("X")),
            new Mul(new Variable("Y"),
                    new Sub(new Variable("Z"), new Variable("X")))
            );
    std::cout << "Input expression: " << t << std::endl;
    Variable::setVariableValue("X", 2.0);
    Variable::setVariableValue("Y", 3.0);
    Variable::setVariableValue("Z", 5.0);
    std::cout << "Setting variables 'X' = " << 2.0 << ", 'Y' = " << 3.0 << ", 'Z' = " << 5.0 << std::endl;
    std::cout << "Expression evaluates to: " << t.evaluate() << std::endl;
    std::cout << "Computing derivative d/dx of expression: " << t << std::endl;
    ExpressionTree dtdx = t.derivative("X");
    std::cout << "Derivative: " << dtdx << std::endl;
    std::cout << "Derivative evaluates to: " << dtdx.evaluate() << std::endl;
    return 0;
}
