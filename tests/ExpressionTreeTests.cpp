#include "gtest/gtest.h"
#include "Constant.h"
#include "Variable.h"
#include "Positive.h"
#include "Negative.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "ExpressionTree.h"
#include <vector>

TEST(ExpressionTreeTests, TestConstant) {
    std::vector<double> vals{5.0, -2.0, 0};
    for (auto &val : vals) {
        Constant c{val};
        EXPECT_DOUBLE_EQ(c.evaluate(), val);
    }
    Constant c{8};
    std::ostringstream ss;
    ss << c.derivative("X");
    EXPECT_EQ(ss.str(), "0");
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
    std::ostringstream ss;
    ss << v1.derivative("X");
    EXPECT_EQ(ss.str(), "1");
    std::ostringstream ss1;
    ss1 << v1.derivative("Y");
    EXPECT_EQ(ss1.str(), "0");
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
    Positive e4{new Variable("X")};
    std::ostringstream os;
    os << e4.derivative("X");
    EXPECT_EQ(os.str(), "(+1)");
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
    Negative e4{new Variable("X")};
    std::ostringstream os;
    os << e4.derivative("X");
    EXPECT_EQ(os.str(), "(-1)");
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
    Add e4{new Variable("X"), new Variable("Y")};
    std::ostringstream ss;
    ss << e4.derivative("X");
    EXPECT_EQ(ss.str(), "(1 + 0)");
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
    Sub e4{new Variable("X"), new Variable("Y")};
    std::ostringstream ss;
    ss << e4.derivative("X");
    EXPECT_EQ(ss.str(), "(1 - 0)");
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
    Mul e4{new Variable("X"), new Variable("Y")};
    std::ostringstream ss;
    ss << e4.derivative("X");
    EXPECT_EQ(ss.str(), "((X * 0) + (Y * 1))");
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
    Div e4{new Variable("X"), new Variable("Y")};
    std::ostringstream ss;
    ss << e4.derivative("X");
    EXPECT_EQ(ss.str(), "(((Y * 1) - (X * 0)) / (Y * Y))");
}

TEST(ExpressionTreeTests, TestExpressionTree) {
    ASSERT_NO_THROW(ExpressionTree(new Constant(1.0)));
    Node* root = new Constant(5.0);
    ExpressionTree t = root;
    ASSERT_EQ(root, t.root()); // pointers should match
    ExpressionTree t1 = t;
    ASSERT_NE(root, t1.root()); // pointers should not match
    ASSERT_EQ(root->evaluate(), t1.evaluate());
    ExpressionTree t2 = new Add(
            new Mul(new Constant(2.3), new Variable("X")),
            new Mul(new Variable("Y"),
                    new Sub(new Variable("Z"), new Variable("X")))
            );
    Variable::setVariableValue("X", 2.0);
    Variable::setVariableValue("Y", 3.0);
    Variable::setVariableValue("Z", 5.0);
    ASSERT_DOUBLE_EQ(t2.evaluate(), 13.6);
    ExpressionTree dtdx = t2.derivative("X");
    ASSERT_DOUBLE_EQ(dtdx.evaluate(), -0.7);
}