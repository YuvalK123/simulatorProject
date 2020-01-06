//
// Created by israela on 03/01/2020.
//

#ifndef WORK_FUNCCOMMAND_H
#define WORK_FUNCCOMMAND_H

#include "Command.h"
#include "SimulatorHelper.h"
class FuncCommand : public Command {
 public:
  int execute(vector<string>::iterator it);
};
int FuncCommand::execute(vector<string>::iterator it) {
  int returnValue = 0, flag = 1;
  string funcName = *(it);
  auto *funcMap = helper->getManager()->getFunctions();
  if (funcMap->find(funcName) != funcMap->end()) { //if the function was asstablished
    returnValue++;//jumps over func name
    vector<string> paramsToDel;//for inner vars
    vector<string> code = (*funcMap)[funcName];//gets specific func lexer
    int countParamters = 0;
    vector<string> parameters;
    auto itCode = code.begin();
    while (*(itCode) != "{") {
      if (*(itCode) != ",") {
        //var
        vector<string> var = helper->getManager()->split(*(itCode), " ");
        parameters.push_back(var[0]);//var
        parameters.push_back(var[1]);//var name
        paramsToDel.push_back(var[1]);
        itCode++;

        //=
        parameters.push_back("=");//for var x = value
        //value
        parameters.push_back(*(it + returnValue));
        returnValue++;
      }
      flag++;//has +1 parameter
    }
    if (*(itCode + 1) == "var") {
      cerr << "too little vars" << endl;
      throw "too little vars";
    }
    vector<string> newCode;
    for (long i = flag; i < code.size() - 1; i++) {
      newCode.push_back(code[i]);
    }
    if (!parameters.empty()) {
      helper->parser(parameters);
    }
    helper->parser(newCode);
    helper->getInterpret()->removeVars(paramsToDel);
  } else {//function is now created
    vector<string> code;
    //input parameters
    string str = *it;
    while (str != "{") {//gets params
      returnValue++;
      str = *(it + returnValue);
      code.push_back(helper->getManager()->trim(str));
    }
    //put the function code in the map
    returnValue++;
    str = *(it + returnValue);
    int counter = 1;
    while (counter > 0) {//counts for "{" or "}" in case of inner conditions, so we will know when func ends
      if (str == "{") {
        counter++;
      } else if (str == "}") {
        counter--;
      }
      code.push_back(str);
      returnValue++;
      str = *(it + returnValue);
    }
    funcMap->insert(make_pair(funcName, code));
  }
  return returnValue;
}

#endif //WORK_FUNCCOMMAND_H
