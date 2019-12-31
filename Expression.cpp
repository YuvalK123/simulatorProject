//
// Created by israela on 09/11/2019.
//

#include "expression.h"

//BinaryoOperator Class functons
//Constructor
BinaryoOperator::BinaryoOperator(Expression *right, Expression *left) {
  rightExp = right;
  leftExp = left;
}

//Mul class functions
double Mul::calculate() {
  return (rightExp->calculate() * leftExp->calculate());
}

//Plus class
double Plus::calculate() {
  return (rightExp->calculate() + leftExp->calculate());
}

//Minus class
double Minus::calculate() {
  return (rightExp->calculate() - leftExp->calculate());
}

//Div class
double Div::calculate() {
  //divide by zero
  if (leftExp->calculate() == 0) {
    throw "division by zeromain";
  }
  return (rightExp->calculate() / leftExp->calculate());
}

//Value Class
//Constructor
Value::Value(double d) {
  Double = d;
}

double Value::calculate() {
  return Double;
}


//Variable Class

//Constructor
Variable::Variable(std::string n, double v) {
  name = n;
  *value = v;
}

double Variable::calculate() {
  return *value;
}

//over load to ++
Variable &Variable::operator++() {
  ++(*value);
  Variable *variable = new Variable(name, *value);;

  return *variable;
}

//over load to ++
Variable &Variable::operator++(int) {
  (*value)++;
  Variable *variable = new Variable(name, *value);;

  return *variable;
}

//over load to --
Variable &Variable::operator--() {
  --(*value);
  Variable *variable = new Variable(name, *value);;

  return *variable;
}

//over load to +=
Variable &Variable::operator+=(double d) {
  *value = (*value) + d;
  Variable *variable = new Variable(name, *value);;

  return *variable;
}

//over load to -=
Variable &Variable::operator-=(double d) {
  *value = (*value) - d;
  Variable *variable = new Variable(name, *value);;

  return *variable;
}
void Variable::setValueByReference(double *d) {
//  delete this->value;
  this->value = d;

}
void Variable::setValueByValue(double d) {
  *this->value = d;
}

//UnaryOperator Class
//Constructor
UnaryOperator::UnaryOperator(Expression *expression) {
  e = expression;
}

//Destructor
UnaryOperator::~UnaryOperator() {
  delete (e);
}

//UPlus Class
double UPlus::calculate() {
  return e->calculate();
}

//UMinus Class
double UMinus::calculate() {
  return Mul(new Value(e->calculate()), new Value(-1)).calculate();
}


//Interpreter Class

//function interpreter gets string and calcluate the expression.
Expression *Interpreter::interpret(string s) {
  return calcluate(shuntingYard(s));
}

//function calcluate gets a postfix expression and calcuate it.
Expression *Interpreter::calcluate(queue<string> posfix) {
  stack<Expression *> temp;
  while (!posfix.empty()) {
    if (!isOperator(posfix.front())) {
      temp.push(new Value((stod(posfix.front()))));
      posfix.pop();
    } else {
      Expression *num2 = temp.top();
      temp.pop();
      Expression *num1 = temp.top();
      temp.pop();
      if (posfix.front() == "+") {
        temp.push(new Plus(num1, num2));
      } else if (posfix.front() == "-") {
        temp.push(new Minus(num1, num2));
      } else if (posfix.front() == "*") {
        temp.push(new Mul(num1, num2));
      } else if (posfix.front() == "/") {
        temp.push(new Div(num1, num2));
      }

      posfix.pop();

    }
  }
  return temp.top();
}

bool Interpreter::isOperator(string s) {
  if (s == "*" || s == "*" || s == "/" || s == "+" || s == "-") {
    return true;
  } else {
    return false;
  }
}

//gets a string and set a variable(with a name and a value).
void Interpreter::setVariables(string s) {
  regex reg("[^;=]+=[^;]+");
  smatch m;

  //find all the variables in the string
  while (regex_search(s, m, reg)) {
    string str = m.str(0);

    //variable's name
    size_t pos = str.find('=');
    string name = str.substr(0, pos);

    //check if the name is valid
    if (isdigit(name[0])) {
      throw "illegal variable assignment!";
    }
    for (unsigned i = 0; i < name.size(); ++i) {
      if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && (name[i] != '_') &&
          (name[i] < '0' || name[i] > '9')) {
        throw "illegal variable assignment!";
      }
    }

    //variable's value
    str.erase(0, pos + 1);
    string value = str;
    double val;
//    check that value is with legal value
    try {
      val = interpret(value)->calculate();
    }
    catch (const char *e) {
      throw "3 illegal variable assignment!";
    }
//    if (!value.find_first_not_of("0123456789")) {
//    }

    //set the current variable

    auto it = this->variables.find(name);
    if (it != this->variables.end()) {
      it->second->setValueByValue(val);
    } else {
      Variable *tmp = new Variable(name, val);
      this->variables.insert(make_pair(name, tmp));
    }
    //go to the next variable
    s = m.suffix().str();
  }
}

//shuntingYard algorithm
queue<string> Interpreter::shuntingYard(string s) {
  string nums;
  smatch m;
  //puts in the string the variables values
//    for (int j = variables.size() - 1; j >= 0; --j) {
  for (auto &it :this->variables) {
    regex r(it.second->name);
    while (regex_search(s, m, r)) {
      s = regex_replace(s, r, to_string(*it.second->value));
    }
  }

  for (unsigned i = 0; i < s.size(); ++i) {

    //if is is a number
    if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
      nums = nums + s[i];
      //check if the number is more than one digit
      if ((i == (s.size() - 1) || (s[i + 1] < '0' || s[i + 1] > '9')) && s[i + 1] != '.') {
        output.push(nums);
        nums.clear();
      }
    } else if (s[i] == '(') {
      operators.push(s[i]);
    } else if (s[i] == ')') {
      while (operators.top() != '(') {
        //check if the brackets are valid
        if (operators.size() == 1) {
          throw "illegal math exprmainession";
        }
        string o;
        output.push(o + operators.top());
        operators.pop();
      }
      operators.pop();
    }
      //if it is a operator
    else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
      //check for illegal math exprmainession
      if (i != 0 && (s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '+' || s[i - 1] == '-')) {
        throw "illegal math exprmainession";
      }
      while (!operators.empty() && precedence(operators.top()) >= precedence(s[i])) {
        string o;
        output.push(o + operators.top());
        operators.pop();
        o.clear();
      }
      if (i == 0 || s[i - 1] == '(') {
        output.push("0");
      }
      operators.push(s[i]);
    }
  }

  while (!operators.empty()) {
    if (operators.top() == '(') {
      throw "illegal math exprmainession";
    }
    string o;
    output.push(o + operators.top());
    operators.pop();
  }
  return output;
}

int Interpreter::precedence(char &oper) {
  switch (oper) {
    case '(':return 0;
      break;
    case '+':return 1;
      break;
    case '-':return 1;
      break;
    case '*':return 2;
      break;
    case '/':return 2;
      break;
    case '^':return 3;
      break;
    default:throw "invalid operator";
  }
}


