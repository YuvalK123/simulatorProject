//
// Created by israela on 09/11/2019.
//

#ifndef EX1_EX1_H
#define EX1_EX1_H

#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <regex>
#include <utility>
#include "unordered_map"
#include <iostream>
#include "vector"
using namespace std;

class Expression {

 public:
  virtual double calculate() = 0;
  virtual ~Expression() {}
};

//BinaryoOperator Class
class BinaryoOperator : public Expression {

 protected:
  //variables
  Expression *rightExp;
  Expression *leftExp;

 public:
  //functions
  double calculate() = 0;
  //Constructor
  BinaryoOperator(Expression *right, Expression *left);
  ~BinaryoOperator() = default;
};

//Mul class
class Mul : public BinaryoOperator {
 public:
  using BinaryoOperator::BinaryoOperator;
  ~Mul() = default;
  double calculate();
};

//Plus class
class Plus : public BinaryoOperator {
 public:
  using BinaryoOperator::BinaryoOperator;
  ~Plus() = default;
  double calculate();
};

//Minus class
class Minus : public BinaryoOperator {
 public:
  using BinaryoOperator::BinaryoOperator;
  ~Minus() = default;
  double calculate();
};

//Div class
class Div : public BinaryoOperator {
 public:
  using BinaryoOperator::BinaryoOperator;
  ~Div() = default;
  double calculate();
};

//Value Class
class Value : public Expression {
 private:
  //variable
  double Double;
 public:
  Value(double d);
  ~Value() = default;
  double calculate();
};

//Variable Class

class Variable : public Expression {
 public:
  //variables
  std::string name;
  double *value = new double(0.0);
  vector<double> v;
  int index;
  string side;
  string sim;

  //Constructor & Destructor
  Variable(string n, double v);
  ~Variable() = default;
  void setValueByReference(double *d);
  void setVec(vector<double> vec, int ind) {
    this->v = vec;
    this->index = ind;
  }
  void setValueByValue(double d);
  double calculate();
  void setToSim(string sd, string sm) {
    if (sm != "none") {
      this->sim = std::move(sm);
    }
    this->side = std::move(sd);
  }

  //over load to ++
  Variable &operator++();
  //over load to ++
  Variable &operator++(int);
  //over load to --
  Variable &operator--();
  //over load to +=
  Variable &operator+=(double d);
  //over load to -=
  Variable &operator-=(double d);
};

//UnaryOperator Class
class UnaryOperator : public Expression {
 protected:
  //variables
  Expression *e;
 public:
  //functions
  double calculate() = 0;
  //Constructor
  UnaryOperator(Expression *expression);
  ~UnaryOperator();
};

//UPlus Class
class UPlus : public UnaryOperator {
 public:
  using UnaryOperator::UnaryOperator;
  ~UPlus() = default;
  double calculate();
};

//UMinus Class
class UMinus : public UnaryOperator {
 public:
  using UnaryOperator::UnaryOperator;
  ~UMinus() = default;
  double calculate();
};

//Interpreter Class
class Interpreter {
 private:
  queue<string> output;
  stack<char> operators;
  unordered_map<string, Variable *> variables;
 public:
  Interpreter() {}

  Expression *interpret(string s);

  Expression *calcluate(queue<string> posfix);

  bool isVariable(string var);

  bool isOperator(string s);

  void setVariables(string s);

  void removeVars(vector<string> vars);

  queue<string> shuntingYard(string s);

  int precedence(char &oper);

  unordered_map<string, Variable *> getVars() { return this->variables; }
};

#endif //EX1_EX1_H
