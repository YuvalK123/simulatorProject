//
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_

#include "Command.h"
#include "unordered_map"
#include "../SimulatorHelper.h"

class DefineVarCommand : public Command {
 private:
  enum side { None, INPUTVAL, OUTPUTVAL };
//  SimulatorHelper simHelper;
//  unordered_map<string,Variable*> vars;


//  void outVal(double val);
 public:
  int execute(vector<string>::iterator it) override;
  explicit DefineVarCommand() = default;
};

int DefineVarCommand::execute(vector<string>::iterator it) {
  //if sim than create var
  //if = than find var in interpreter and change value
  int retVal;
  double value = 0.0;
  string ID = *(it + 1), sm, arrow, eq = "=";
  if (strcmp((it + 3)->c_str(), "sim") == 0) {
    retVal = 5;
//    cout << "id is " << ID << endl;
    helper->getInterpret()->setVariables(ID + eq + to_string(0.0));
    const char *side = (it + 2)->c_str();
    sm = *(it + 4);
    sm.erase(std::remove(sm.begin(), sm.end(), '"'), sm.end());
    string sim = sm;
    if (strcmp(side, "<-") == 0) {
      arrow = "<-";
//      value = *(helper->getManager()->getInIndex(sm));
      helper->getInterpret()->getVars()[ID]->setValueByReference(&(*helper->getManager()->getInIndex(sm)));
    } else { //->
      arrow = "->";
      *(helper->getManager()->getOutIndex(sm)) = value;
    }
    helper->getInterpret()->getVars()[ID]->setToSim(arrow, sm);
  } else { //=
    ID = *(it);
//    cout << "id is " << ID << endl;
    string x = *(it + 2);
    retVal = 3;
    string exp = ID + eq + x;
    cout << "exp is " << exp << " ";
    helper->getInterpret()->setVariables(exp);
    arrow = helper->getInterpret()->getVars()[ID]->side;
    sm = helper->getInterpret()->getVars()[ID]->sim;
    cout << "arrow is " << arrow << endl;
    if (arrow == "->") {
      string msg = ("set ") + (sm) + " " + x;
      helper->getManager()->sendMsg(msg);
    } else {
      arrow = "0";//new variable with no sim/arrow
      helper->getInterpret()->getVars()[ID]->setToSim(arrow, "none");
    }
  }
  return retVal;
}
//    try {
//      string x = *(it+2);
////      value = helper->getInterpret()->interpret(*(it+2))->calculate();
//    }
//    string exp = ID + eq + to_string(helper->getInterpret()->interpret(*(it+2))->calculate());


#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_
