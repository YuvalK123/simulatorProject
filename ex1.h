//
// Created by israela on 09/11/2019.
//

#ifndef EX1_EX1_H
#define EX1_EX1_H


#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include "Expression.h"
#include <regex>

//BinaryoOperator Class
class BinaryoOperator: public Expression {

protected:
    //variables
    Expression* rightExp;
    Expression* leftExp;

public:
    //functions
    double calculate()=0;
    //Constructor
    BinaryoOperator(Expression* right, Expression* left);
    ~BinaryoOperator() = default;
};

//Mul class
class Mul: public BinaryoOperator {
public:
    using BinaryoOperator::BinaryoOperator;
    ~Mul() = default;
    double calculate();
};

//Plus class
class Plus: public BinaryoOperator {
public:
    using BinaryoOperator::BinaryoOperator;
    ~Plus() = default;
    double calculate();
};

//Minus class
class Minus: public BinaryoOperator {
public:
    using BinaryoOperator::BinaryoOperator;
    ~Minus() = default;
    double calculate();
};

//Div class
class Div: public BinaryoOperator {
public:
    using BinaryoOperator::BinaryoOperator;
    ~Div() = default;
    double calculate();
};

//Value Class
class Value: public Expression {
private:
    //variable
    double Double;
public:
    Value(double d);
    ~Value() = default;
    double calculate();
};

//Variable Class
class Variable:public Expression {
public:
    //variables
    std::string name;
    double value;

    //Constructor & Destructor
    Variable(std::string n,double v);
    ~Variable() = default;
    double calculate();

    //over load to ++
    Variable& operator++();
    //over load to ++
    Variable& operator++(int);
    //over load to --
    Variable& operator--();
    //over load to +=
    Variable& operator+=(double d);
    //over load to -=
    Variable& operator-=(double d);
};

//UnaryOperator Class
class UnaryOperator: public Expression {
protected:
    //variables
    Expression* e;
public:
    //functions
    double calculate()=0;
    //Constructor
    UnaryOperator(Expression* expression);
    ~UnaryOperator();
};

//UPlus Class
class UPlus: public UnaryOperator {
public:
    using UnaryOperator::UnaryOperator;
    ~UPlus() = default;
    double calculate();
};

//UMinus Class
class UMinus: public UnaryOperator {
public:
    using UnaryOperator::UnaryOperator;
    ~UMinus()= default;
    double calculate();
};

//Interpreter Class
class Interpreter {
public:
    queue<string> output;
    stack<char> operators;
    vector<Variable> variables;

    Interpreter() {}

    Expression *interpret(string s);

    Expression *calcluate(queue<string> posfix);

    bool isOperator(string s);

    void setVariables(string s);

    queue<string> shuntingYard(string s);

    int precedence(char &oper);
};

#endif //EX1_EX1_H
