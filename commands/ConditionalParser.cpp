//
// Created by yuval Kasner on 21/12/19.
//
#include "ConditionParser.h"

void ConditionParser::initiateCond(vector<const char *> vec, int index) {
  bool cond = false;
  while (strcmp(vec[index], "{") != 0) {
    index++;
  }
  this->condition = cond;
}
string ConditionParser::getArithmetic(string left, string right, const char *arithmetic) {
  string arith;
  if (strcmp(arithmetic, "<") == 0) {
    arith = "smaller";
  } else if (strcmp(arithmetic, ">") == 0) {
    arith = "bigger";
  } else if (strcmp(arithmetic, ">=") == 0) {
    arith = "biggerEq";
  } else if (strcmp(arithmetic, "<=") == 0) {
    arith = "smallerEq";
  } else if (strcmp(arithmetic, "==") == 0) {
    arith = "Equal";
  }

  return arith;
}