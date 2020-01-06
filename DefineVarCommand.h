//
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_

#include "Command.h"
#include "unordered_map"
#include "SimulatorHelper.h"

class DefineVarCommand : public Command {
 public:
  int execute(vector<string>::iterator it) override;
  explicit DefineVarCommand() = default;
};

int DefineVarCommand::execute(vector<string>::iterator it) {

  //if sim than create var
  //if = than find var in interpreter and change value
  int retVal = 0;
  string id, sm = "sim", arrow, eq = "=", val;
  if (strcmp((it)->c_str(), "var") == 0) {//starts with var((var x ->...) or (var x =...))
    id = *(it + 1);
    //check if var in interpreter. if yes - compilation error.
    if (helper->getInterpret()->isVariable(id)) {
      throw "variable already exists";
    }
    if (strcmp((it + 3)->c_str(), sm.c_str()) == 0) { //var x -> sim("..")
      retVal = 5;
      arrow = *(it + 2);
      val = *(it + 4);
      val.erase(std::remove(val.begin(), val.end(), '"'), val.end());//delete ""
      helper->getInterpret()->setVariables((id + eq + "0.0"));//reset value to 0
      helper->getInterpret()->getVars()[id]->setToSim(arrow, val);//set arrow and string value
      if (strcmp(arrow.c_str(), "<-") == 0) {
        helper->getInterpret()->getVars()[id]->setValueByReference(helper->getManager()->valuePtr(val));
      }
    } else { // var x = y
      retVal = 4;
      val = *(it + 3);
      helper->getInterpret()->setVariables((id + eq + val));
      helper->getInterpret()->getVars()[id]->setToSim("0", "none");//0 cuz point at nothing, an none sim
    }
  } else { //its an existing variable.
    id = *(it);
    //check in interpeter if legal var(declared before). if not - compilation error
    if (!helper->getInterpret()->isVariable(id)) {
      const char *e = string("try to assign to a none existing variable ", id.c_str()).c_str();
      throw e;
    }
    if (strcmp((it + 1)->c_str(), "=") == 0) {//type of x = 10
      retVal = 3;
      val = *(it + 2);
      Variable *var = helper->getInterpret()->getVars()[id];
      var->setValueByValue(helper->getInterpret()->interpret(val)->calculate());
      if (strcmp(var->side.c_str(), "->") == 0) {
        string msg = ("set ") + (var->sim) + " " + to_string(*var->value);
        helper->getManager()->sendMsg(msg);
      }
    } else if (strcmp((it + 2)->c_str(), "sim") == 0) {//x ->sim("..")
      retVal = 4;
      arrow = *(it + 1);
      sm = *(it + 3);
      helper->getInterpret()->getVars()[id]->setToSim(arrow, sm);
    }
  }
  if (retVal == 0) {
    throw "was not able to define variable";
  }
  return retVal;
}





//  if (strcmp((it + 3)->c_str(), "sim") == 0) {
//    retVal = 5;
////    cout << "id is " << ID << endl;
//    helper->getInterpret()->setVariables(id + eq + to_string(0.0));
//    const char *side = (it + 2)->c_str();
//    arrow = *(it + 2);
//    sm = *(it+4);
//    sm.erase(std::remove(sm.begin(), sm.end(), '"'), sm.end());
//    string sim = sm;
//    if (strcmp(arrow.c_str(), "<-") == 0) {
//      arrow = "<-";
//      helper->getInterpret()->getVars()[id]->setValueByReference(&(*helper->getManager()->getInIndex(sm)));
//    } else { //->
//      arrow = "->";
//    }
//    helper->getInterpret()->getVars()[id]->setToSim(arrow, sm);
//  }
//
//  else { //=
//    if (*it != "var") {
//      retVal = 3;
//      id = *(it);
//      string val = *(it + 2);
//      string exp = id + eq + val;
////      cout << "exp is " << exp << " ";
//      helper->getInterpret()->setVariables(exp);
//      arrow = helper->getInterpret()->getVars()[id]->side;
//      sm = helper->getInterpret()->getVars()[id]->sim;
//      cout << "arrow is " << arrow << endl;
//      if (arrow == "->") {
//        string msg = ("set ") + (sm) + " " + val;
//        helper->getManager()->sendMsg(msg);
//      }
//
//      else {
//        arrow = "0";//new variable with no sim/arrow
//        helper->getInterpret()->getVars()[id]->setToSim(arrow, "none");
//      }
//    }
//
//    else {
//      //there is a new var: var(0) x(1) =(2) y(3)
//      retVal = 4;
//      id = *(it + 1);
//      double *val = helper->getInterpret()->getVars()[*(it + 3)]->value;
//      string exp = id + eq + *(it + 3);
//      cout << "exp is " << exp << endl;
//      try {
//        helper->getInterpret()->setVariables(exp);
//        helper->getInterpret()->getVars()[id]->setToSim("0", "none");
//      }
//      catch (const char *e) {
//        cerr << e;
//        throw e;
//      }
//
//    }
//  }


//    try {
//      string x = *(it+2);
////      value = helper->getInterpret()->interpret(*(it+2))->calculate();
//    }
//    string exp = ID + eq + to_string(helper->getInterpret()->interpret(*(it+2))->calculate());


#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_
