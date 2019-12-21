//
// Created by yuval Kasner on 21/12/19.
//

#ifndef SIMULATORPROJECT__SYMBOLTABLE_H_
#define SIMULATORPROJECT__SYMBOLTABLE_H_
using namespace std;
#include "string"
#include "unordered_map"
#include "commands/DefineVarCommand.cpp"
template<class Type>
class SymbolTable {
  SymbolTable<Type>() = default;

  unordered_map<string, pair<string, DefineVarCommand>> map;

  Type ID;
  Type dataType;
  Type returnType;
  Type value;
  Type numOfParams;
  Type typeOfParamaters;

};

template<class Type>

#endif //SIMULATORPROJECT__SYMBOLTABLE_H_
