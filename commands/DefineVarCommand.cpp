////
//// Created by yuval Kasner on 20/12/19.
////
//#include "DefineVarCommand.h"
//
//
//
//int DefineVarCommand::execute(vector<string>::iterator it) {
//  int retVal;
//  if(strcmp((it+3)->c_str(),"sim") == 0){
//    retVal = 5;
//    this->ID = (it+1)->c_str();
//    const char* side = (it+2)->c_str();
//    string sm = *(it+4);
//    sm.erase(std::remove(sm.begin(), sm.end(), '"'), sm.end());
//    this->sim = sm.c_str();
//    if (strcmp(side, "<-") == 0) {
//      this->arrow = INPUTVAL;
//      *(this->simHelper.getManager()->getInIndex(this->sim)) = this->value;
//    } else { //->
//      this->arrow = OUTPUTVAL;
//      *(this->simHelper.getManager()->getOutIndex(this->sim)) = this->value;
//    }
//  } else{
//    retVal = 3;
//    (this->value) = this->simHelper.getInterpret()->interpret(*(it+2))->calculate();
//    string eq = "=";
//    string exp = this->ID + eq + to_string(this->value);
//    this->simHelper.getInterpret()->setVariables(exp);
//    if(this->arrow == OUTPUTVAL){
//      string msg = *("set ") + (this->sim) + to_string(this->value);
//      this->simHelper.getManager()->sendMsg(msg);
//    }
//
//  }
//  return retVal;
//}
//
