//
// Created by yuval Kasner on 26/12/19.
//

#include "SimManager.h"
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;
//lexer function separate the code to strings.
//input: a file that contains a code.
//output: vector to string that contains string from the code file.
void SimManager::lexer(ifstream &codeFile) {
  vector<string> codeArray;
  if (!codeFile.is_open()) {
    throw "file not open";

  }
  //save the current the string that we read from the file.
  string currentString;

  //if the file is not null

  while (getline(codeFile, currentString)) {
    int leftPos = 0;
    int range = 0;
    string pushS;
    int flagInBrackets = 0;

    for (int i = 0; i < currentString.size(); i++) {

      //check if there is tab
      if (currentString[i] == '\t') {
        leftPos += i + 1;
      }
        //check if the char is a space and it is not in a brackets.
      else if (currentString[i] == ' ' && !flagInBrackets) {
        range = i - leftPos;
        pushS = currentString.substr(leftPos, range);
        if (pushS != "") {
          codeArray.push_back(pushS);
        }
        leftPos += range + 1;
      }
        // check if the char is a left bracket
      else if (currentString[i] == '(') {
        flagInBrackets = 1;
        range = i - leftPos;
        pushS = currentString.substr(leftPos, range);
        if (pushS != "") {
          codeArray.push_back(pushS);
        }
        leftPos += range + 1;
      }
        // check if the char is a comma
      else if (currentString[i] == ',') {
        range = i - leftPos;
        pushS = currentString.substr(leftPos, range);
        if (pushS != "") {
          codeArray.push_back(pushS);
        }
        leftPos += range + 1;
      }
        // check if the char is right bracket
      else if (currentString[i] == ')') {
        flagInBrackets = 0;
        range = i - leftPos;
        pushS = currentString.substr(leftPos, range);
        if (pushS != "") {
          codeArray.push_back(pushS);
        }
        leftPos += range + 1;
      }
        // check if the char is =>
      else if (currentString[i] == '=' && currentString[i + 1] == '>') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos += 2;
          i++;
        }
        codeArray.push_back("=>");
      }
        // check if the char is <-
      else if (currentString[i] == '<' && currentString[i + 1] == '-') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          codeArray.push_back(pushS);
          leftPos += range + 1;
        } else {
          leftPos += 2;
          i++;
        }
        codeArray.push_back("<-");
      }
        // check if the char is <=
      else if (currentString[i] == '<' && currentString[i + 1] == '=') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos += 2;
          i++;
        }
        codeArray.push_back("<=");
      } else if (currentString[i] == '=' && currentString[i + 1] == '=') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos += 2;
          i++;
        }
        codeArray.push_back("==");
      } else if (currentString[i] == '!' && currentString[i + 1] == '=') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos += 2;
          i++;
        }
        codeArray.push_back("!=");
      }
        // check if the char is =
      else if (currentString[i] == '=') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos++;
        }
        codeArray.push_back("=");

        //after "=" there is an expression that should be in one cell.
        string expression;
        for (int j = i + 1; j < currentString.size(); j++) {
          if (currentString[j] != ' ') {
            expression += currentString[j];
          }
        }
        codeArray.push_back(expression);
        i = currentString.size();
      }
        // check if the char is <
      else if (currentString[i] == '<') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos++;
        }
        codeArray.push_back("<");
      }
        // check if the char is >
      else if (currentString[i] == '>') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else {
          leftPos++;
        }
        codeArray.push_back(">");
      }
        // check if the char is ->
      else if (currentString[i] == '-' && currentString[i + 1] == '>') {
        if (i != leftPos) {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          codeArray.push_back(pushS);
          leftPos += range;
        } else {
          leftPos += 2;
          i++;
        }
        codeArray.push_back("->");
      }
        //end of string
      else if (i == currentString.size() - 1) {
        range = i - leftPos;
        if (range != 0) {
          pushS = currentString.substr(leftPos, range + 1);
        } else {
          pushS = currentString[i];
        }
        codeArray.push_back(pushS);
      }
    }
  }
  this->lex = codeArray;


  //print vector

//  for (int i = 0; i < size; i++) {
//    cout << i << endl;
//    cout << codeArray.back() << endl;
//    codeArray.pop_back();
//  }
//  return codeArray;

}
void SimManager::parser() {
  for (string str : this->lex) {
    cout << str << endl;
  }

}
Command *SimManager::getVar(const string &var) {

  return this->vars[var];
}
int SimManager::getIndex() {
  return this->index;
}
string SimManager::getLex(int ind) {
  if (ind >= this->lex.size()) {
    cerr << "bad index" << endl;
    throw "bad index";
  }
  return this->lex[ind];
}
void SimManager::initVarss() {
  ifstream generic_small;
  (generic_small).open("generic_small_to_read.txt");
  if (!generic_small.is_open()) {
    cerr << "not open" << endl;
    return;
  }
  string currentString;
  regex node("<node>");
  regex line("([^<node>][a-zA-Z/0-9-]+[^</node>])");
  int i = 0;
  while (getline(generic_small, currentString)) {
    sregex_iterator currentNodeMatch(currentString.begin(), currentString.end(), node);
    sregex_iterator lastMatch;
    if (currentNodeMatch == lastMatch) {
      continue;
    }
    sregex_iterator currentMatch(currentString.begin(), currentString.end(), line);
    smatch match = *currentMatch;
    if (currentMatch == lastMatch) {
      continue;
    }
    string match_str;
    for (auto p = 0; p < match.size(); p++) {
      match_str += match.str(p);
    }
    this->id2Index.insert(make_pair(match_str, i));
    i++;
  }
  for (long t = 0; t < this->id2Index.size(); t++) {
    this->varVals.push_back(0.0);
  }
}
SimManager::SimManager() {
  initVarss();
}

vector<string> SimManager::split(string str, string token) {
  vector<string> result;
  while (str.size()) {
    int index = str.find(token);
    if (index != string::npos) {
      result.push_back(str.substr(0, index));
      str = str.substr(index + token.size());
      if (str.size() == 0) {
        result.push_back(str);
      }
    } else {
      result.push_back(str);
      str = "";
    }
  }
  return result;
}
void SimManager::assignValByVec(vector<string> vals) {
  vector<double> vec;
  for (string str:vals) {
    double x = stod(str);
    this->varVals.push_back(x);
    cout << x << endl;
  }

}
