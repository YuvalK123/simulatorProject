//
// Created by yuval Kasner on 20/12/19.
//
#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand() {
  this->value = 0;
  this->sim = "";
}

void DefineVarCommand::simVar(const char *side, const char *var) {
  this->sim = var;
  if (strcmp(side, "<-") == 0) {
    this->arrow = INPUTVAL;
  } else {
    this->arrow = OUTPUTVAL;
  }
}
DefineVarCommand &DefineVarCommand::operator=(int x) {
  this->value = x;
  return *this;
}
int DefineVarCommand::execute(vector<string>::iterator it) {



//  string next = vec[index+1];
//  int retValue = 1;
//  if(next == "sim"){
//    simVar(vec[index],vec[index+2]);
//    retValue += 3;
//  } else {
//    try {
//      this->value = std::stod(next);
//      retValue += 2;
//    }
//    catch (runtime_error& e) {
//      cout<<"next is "<<next<<endl;
//      throw e.what();
//    }
//    catch (exception& e){
//      throw e.what();
//    }
//  }
//  return retValue;
  return 0;
}

