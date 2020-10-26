#include "gtest/gtest.h"
#include "Constant.h"
#include "Variable.h"
#include "Positive.h"
#include "Negative.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include <vector>

TEST(ExpressionTreeTests, TestConstant) {
    std::vector<double> vals{5.0, -2.0, 0};
    for (auto &val : vals) {
        Constant c{val};
        EXPECT_DOUBLE_EQ(c.evaluate(), val);
    }
}

TEST(ExpressionTreeTests, TestVariable) {
    Variable v1{"X"};
    Variable v2{"Y"};
    Variable v3{"Z"};
    ASSERT_NO_THROW(Variable::getVariableValue("X"));
    ASSERT_THROW(Variable::setVariableValue("B", 5.0), Variable::VariableException);
    ASSERT_THROW(Variable::getVariableValue("A"), Variable::VariableException);
    ASSERT_THROW(v1.evaluate(), Node::EvaluateException);
    Variable::setVariableValue("X", 5.0);
    EXPECT_DOUBLE_EQ(Variable::getVariableValue("X"), 5.0);
    EXPECT_DOUBLE_EQ(v1.evaluate(), 5.0);
    Variable::setVariableValue("Y", -10.0);
    EXPECT_DOUBLE_EQ(Variable::getVariableValue("Y"), -10.0);
    EXPECT_DOUBLE_EQ(v2.evaluate(), -10.0);
    Variable::setVariableValue("Z", 0.0);
    EXPECT_DOUBLE_EQ(Variable::getVariableValue("Z"), 0.0);
    EXPECT_DOUBLE_EQ(v3.evaluate(), 0.0);
}

TEST(ExpressionTreeTests, TestPositive) {
    double val1 = 5.0;
    double val2 = -2.0;
    double val3 = 0.0;
    Positive e1{new Constant(val1)};
    Positive e2{new Constant(val2)};
    Positive e3{new Constant(val3)};
    EXPECT_DOUBLE_EQ(e1.evaluate(), val1);
    EXPECT_DOUBLE_EQ(e2.evaluate(), val2);
    EXPECT_DOUBLE_EQ(e3.evaluate(), val3);
}

TEST(ExpressionTreeTests, TestNegative) {
    double val1 = 5.0;
    double val2 = -2.0;
    double val3 = 0.0;
    Negative e1{new Constant(val1)};
    Negative e2{new Constant(val2)};
    Negative e3{new Constant(val3)};
    EXPECT_DOUBLE_EQ(e1.evaluate(), -val1);
    EXPECT_DOUBLE_EQ(e2.evaluate(), -val2);
    EXPECT_DOUBLE_EQ(e3.evaluate(), -val3);
}

TEST(ExpressionTreeTests, TestAdd) {
    double val1 = 5.0;
    double val2 = -2.0;
    double val3 = 0.0;
    Add e1{new Constant(val1), new Constant(val2)};
    Add e2{new Constant(val2), new Constant(val3)};
    Add e3{new Constant(val1), new Constant(val3)};
    EXPECT_DOUBLE_EQ(e1.evaluate(), val1 + val2);
    EXPECT_DOUBLE_EQ(e2.evaluate(), val2 + val3);
    EXPECT_DOUBLE_EQ(e3.evaluate(), val1 + val3);
}

TEST(ExpressionTreeTests, TestSub) {
    double val1 = 5.0;
    double val2 = -2.0;
    double val3 = 0.0;
    Sub e1{new Constant(val1), new Constant(val2)};
    Sub e2{new Constant(val2), new Constant(val3)};
    Sub e3{new Constant(val1), new Constant(val3)};
    EXPECT_DOUBLE_EQ(e1.evaluate(), val1 - val2);
    EXPECT_DOUBLE_EQ(e2.evaluate(), val2 - val3);
    EXPECT_DOUBLE_EQ(e3.evaluate(), val1 - val3);
}

TEST(ExpressionTreeTests, TestMul) {
    double val1 = 5.0;
    double val2 = -2.0;
    double val3 = 0.0;
    Mul e1{new Constant(val1), new Constant(val2)};
    Mul e2{new Constant(val2), new Constant(val3)};
    Mul e3{new Constant(val1), new Constant(val3)};
    EXPECT_DOUBLE_EQ(e1.evaluate(), val1 * val2);
    EXPECT_DOUBLE_EQ(e2.evaluate(), val2 * val3);
    EXPECT_DOUBLE_EQ(e3.evaluate(), val1 * val3);
}

TEST(ExpressionTreeTests, TestDiv) {
    double val1 = 5.0;
    double val2 = -2.0;
    double val3 = 0.0;
    Div e1{new Constant(val1), new Constant(val2)};
    Div e2{new Constant(val2), new Constant(val3)};
    Div e3{new Constant(val1), new Constant(val3)};
    EXPECT_DOUBLE_EQ(e1.evaluate(), val1 / val2);
    EXPECT_DOUBLE_EQ(e2.evaluate(), val2 / val3);
    EXPECT_DOUBLE_EQ(e3.evaluate(), val1 / val3);
}