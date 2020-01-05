////
//// Created by yuval Kasner on 26/12/19.
////

#include "SimManager.h"
#include "mutex"
mutex m;

SimManager::SimManager(unordered_map<string, Command *> commands) {
  this->client = new Client();
  this->commandMap = commands;
  initVarss();
}
//
////lexer function separate the code to strings.
////input: a file that contains a code.
////output: vector to string that contains string from the code file.
void SimManager::lexer(ifstream &codeFile) {
  vector<string> codeArray;
  if (!codeFile.is_open()) {
    throw "file not open";

  }
  //save the current the string that we read from the file.
  string currentString;

  //if the file is not null
  int curlyBrackets = 0;
  while (getline(codeFile, currentString)) {
    int error = 0;
    int leftPos = 0;
    int range = 0;
    string pushS;
    int flagInBrackets = 0;
    int commas = 0;

    for (int i = 0; i < currentString.size(); i++) {
      if (!commas) {
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
          flagInBrackets++;
          if (flagInBrackets == 1) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            if (pushS != "") {
              codeArray.push_back(pushS);
            }
            leftPos += range + 1;
          }
        }
          // check if the char is a comma
        else if (currentString[i] == ',') {
          range = i - leftPos;
          pushS = currentString.substr(leftPos, range);
          if (pushS != "") {
            codeArray.push_back(pushS);
          }
          leftPos += range + 1;
        } else if (currentString[i] == '"') {
          if (commas == 1) {
            if (currentString[i + 1] != ',' && currentString[i + 1] != ')') {
              throw "string error";
            }
            commas = 0;
          } else {
            if ((currentString[i - 1] != ',' && currentString[i - 1] != '(') || ((currentString[i - 1] == ' ' &&
                currentString[i - 2] != ',' && currentString[i - 2] != '('))) {
              throw "string error";
            }
            commas = 1;
          }
        }
          // check if the char is right bracket
        else if (currentString[i] == ')') {
          flagInBrackets--;
          if (flagInBrackets == 0) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            if (pushS != "") {
              if (pushS.find('"') == string::npos && (pushS.find('+') != string::npos ||
                  pushS.find('-') != string::npos || pushS.find('*') != string::npos
                  || pushS.find('/') != string::npos)) {
                int j = 0;
                string newPush;
                for (j = 0; j < pushS.size(); j++) {
                  if (pushS[j] != ' ') {
                    newPush += pushS[j];
                  }
                }
                codeArray.push_back(newPush);
              } else {
                codeArray.push_back(pushS);
              }

            }
            leftPos += range + 1;
          }
        }
          // check if the char is =>
        else if (currentString[i] == '=' && currentString[i + 1] == '>' && !flagInBrackets) {
          if (i != leftPos) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            if (pushS != "") {
              codeArray.push_back(pushS);
            }
            leftPos += range + 2;
          } else {
            leftPos += 2;
          }
          i++;
          codeArray.push_back("=>");
        }
          // check if the char is <-
        else if (currentString[i] == '<' && currentString[i + 1] == '-' && !flagInBrackets) {
          if (i != leftPos) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            codeArray.push_back(pushS);
            leftPos += range + 2;
          } else {
            leftPos += 2;
          }
          i++;
          codeArray.push_back("<-");
        }
          // check if the char is <=
        else if (currentString[i] == '<' && currentString[i + 1] == '=' && !flagInBrackets) {
          if (i != leftPos) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            if (pushS != "") {
              codeArray.push_back(pushS);
            }
            leftPos += range + 2;
          } else {
            leftPos += 2;
          }
          i++;
          codeArray.push_back("<=");
        } else if (currentString[i] == '=' && currentString[i + 1] == '=' && !flagInBrackets) {
          if (i != leftPos) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            if (pushS != "") {
              codeArray.push_back(pushS);
            }
            leftPos += range + 2;
          } else {
            leftPos += 2;
          }
          i++;
          codeArray.push_back("==");
        } else if (currentString[i] == '!' && currentString[i + 1] == '=' && !flagInBrackets) {
          if (i != leftPos) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            if (pushS != "") {
              codeArray.push_back(pushS);
            }
            leftPos += range + 2;
          } else {
            leftPos += 2;
          }
          i++;
          codeArray.push_back("!=");
        }
          // check if the char is =
        else if (currentString[i] == '=' & !flagInBrackets) {
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
              if (currentString[j] == '"') {
                throw "eror: string in math expression";
              } else {
                expression += currentString[j];
              }

            }
          }
          codeArray.push_back(expression);
          i = currentString.size();
        }
          // check if the char is <
        else if (currentString[i] == '<' && !flagInBrackets) {
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
        else if (currentString[i] == '>' && !flagInBrackets) {
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
        } else if (currentString[i] == '{' && !flagInBrackets) {
          curlyBrackets++;
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
          codeArray.push_back("{");
        } else if (currentString[i] == '}' && !flagInBrackets) {
          curlyBrackets--;
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
          codeArray.push_back("}");
        }
          // check if the char is ->
        else if (currentString[i] == '-' && currentString[i + 1] == '>' && !flagInBrackets) {
          if (i != leftPos) {
            range = i - leftPos;
            pushS = currentString.substr(leftPos, range);
            codeArray.push_back(pushS);
            leftPos += range + 2;
          } else {
            leftPos += 2;
          }
          i++;
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
      } else if (currentString[i] == '"') {
        if (commas == 1) {
          if (currentString[i + 1] != ',' && currentString[i + 1] != ')') {
            throw "string error";
          }
          commas = 0;
        } else {
          commas = 1;
        }
      }
    }

    if (flagInBrackets == 1) {
      throw "brackets problem!";
    }
  }

  if (curlyBrackets > 0) {
    throw "curly brackets problem!";
  }
  this->lex = codeArray;



  //print vector
  for (auto x: this->lex) {
    cout << x << endl;
  }
}

void SimManager::parser() {
  int index = 0;
  auto it = (this->lex).begin();
//  for (string str : this->lex) {
//    cout << str << endl;
//  }
  while (index < this->lex.size()) {
    try {
      Command *c = nullptr;
      c = this->commandMap[*(it + index)];
//    cout<<"next is "<<*(it + index)<<endl;
      if (c != nullptr) {
        index += c->execute(it + index);
      } else {
//      cout<<"index is "<< index<< " and next is "<<*(it + index)<<endl;
        c = this->commandMap["var"];
        index += c->execute(it + index);
      }
    }
    catch (const char *e) {
      cerr << e << endl;
    }
  }
}



void SimManager::initVarss() {
  this->id2InIndex.insert(make_pair("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
  this->id2InIndex.insert(make_pair("/sim/time/warp", 1));
  this->id2InIndex.insert(make_pair("/controls/switches/magnetos", 2));
  this->id2InIndex.insert(make_pair("/instrumentation/heading-indicator/offset-deg", 3));
  this->id2InIndex.insert(make_pair("/instrumentation/altimeter/indicated-altitude-ft", 4));
  this->id2InIndex.insert(make_pair("/instrumentation/altimeter/pressure-alt-ft", 5));
  this->id2InIndex.insert(make_pair("/instrumentation/attitude-indicator/indicated-pitch-deg", 6));
  this->id2InIndex.insert(make_pair("/instrumentation/attitude-indicator/indicated-roll-deg", 7));
  this->id2InIndex.insert(make_pair("/instrumentation/attitude-indicator/internal-pitch-deg", 8));
  this->id2InIndex.insert(make_pair("/instrumentation/attitude-indicator/internal-roll-deg", 9));
  this->id2InIndex.insert(make_pair("/instrumentation/encoder/indicated-altitude-ft", 10));
  this->id2InIndex.insert(make_pair("/instrumentation/encoder/pressure-alt-ft", 11));
  this->id2InIndex.insert(make_pair("/instrumentation/gps/indicated-altitude-ft", 12));
  this->id2InIndex.insert(make_pair("/instrumentation/gps/indicated-ground-speed-kt", 13));
  this->id2InIndex.insert(make_pair("/instrumentation/gps/indicated-vertical-speed", 14));
  this->id2InIndex.insert(make_pair("/instrumentation/heading-indicator/indicated-heading-deg", 15));
  this->id2InIndex.insert(make_pair("/instrumentation/magnetic-compass/indicated-heading-deg", 16));
  this->id2InIndex.insert(make_pair("/instrumentation/slip-skid-ball/indicated-slip-skid", 17));
  this->id2InIndex.insert(make_pair("/instrumentation/turn-indicator/indicated-turn-rate", 18));
  this->id2InIndex.insert(make_pair("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 19));
  this->id2InIndex.insert(make_pair("/controls/flight/aileron", 20));
  this->id2InIndex.insert(make_pair("/controls/flight/elevator", 21));
  this->id2InIndex.insert(make_pair("/controls/flight/rudder", 22));
  this->id2InIndex.insert(make_pair("/controls/flight/flaps", 23));
  this->id2InIndex.insert(make_pair("/controls/engines/engine/throttle", 24));
  this->id2InIndex.insert(make_pair("/controls/engines/current-engine/throttle", 25));
  this->id2InIndex.insert(make_pair("/controls/switches/master-avionics", 26));
  this->id2InIndex.insert(make_pair("/controls/switches/starter", 27));
  this->id2InIndex.insert(make_pair("/engines/active-engine/auto-start", 28));
  this->id2InIndex.insert(make_pair("/controls/flight/speedbrake", 29));
  this->id2InIndex.insert(make_pair("/sim/model/c172p/brake-parking", 30));
  this->id2InIndex.insert(make_pair("/controls/engines/engine/primer", 31));
  this->id2InIndex.insert(make_pair("/controls/engines/current-engine/mixture", 32));
  this->id2InIndex.insert(make_pair("/controls/switches/master-bat", 33));
  this->id2InIndex.insert(make_pair("/controls/switches/master-alt", 34));
  this->id2InIndex.insert(make_pair("/engines/engine/rpm", 35));
  for (auto i : this->id2InIndex) {
    this->inVals.push_back(0.0);
  }
/*
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
    this->id2InIndex.insert(make_pair(match_str, i));
    i++;
  }
  for (long t = 0; t < this->id2InIndex.size(); t++) {
    this->inVals.push_back(0.0);
  }*/
}

vector<string> SimManager::split(string str, const string &token) {
  vector<string> result;
  while (!str.empty()) {
    int index = str.find(token);
    if (index != string::npos) {
      result.push_back(str.substr(0, index));
      str = str.substr(index + token.size());
      if (str.empty()) {
        result.push_back(str);
      }
    } else {
      result.push_back(str);
      str = "";
    }
  }
  return result;
}
double *SimManager::valuePtr(string str) {
  try {
    return &(this->inVals[this->id2InIndex[str]]);
  }
  catch (exception &e) {
    cerr << "exeption in valuePtr " << e.what() << endl;
  }
  return new double(0.0);
//  cout<<"get in index is = "<<*(this->inVals.begin() + ind)<<endl;
//  return
}

void SimManager::assignValByVec(const vector<string> &vals) {
  vector<double> vec;
  double x;
  int i = 0;
  for (const string &str:vals) {
    try {
      x = stod(str);
      this->inVals[i] = x;
      i++;
      if (i > 35) {
        break;
      }
    }
    catch (exception &e) {
      cerr << "error sim stod" << endl;
//      throw "eerror";
    }
  }
//  cout<<"rpm is "<<inVals[35]<<endl;
}
void SimManager::sendMsg(const string &msg) {
  int x = this->client->sendMsg(msg);
}

//void lex(ifstream &codeFile) {
//    vector<string> codeArray;
//    if (!codeFile.is_open()) {
//      throw "file not open";
//    }
//  //save the current the string that we read from the file.
//  string currentString;
//
//  //if the file is not null
//
//  while (getline(codeFile, currentString)) {
//    int leftPos = 0;
//    int range = 0;
//    string pushS;
//    int flagInBrackets = 0;
//
//    for (int i = 0; i < currentString.size(); i++) {
//
//      //check if there is tab
//      if (currentString[i] == '\t') {
//        leftPos += i + 1;
//      }
//        //check if the char is a space and it is not in a brackets.
//      else if (currentString[i] == ' ' && !flagInBrackets) {
//        range = i - leftPos;
//        pushS = currentString.substr(leftPos, range);
//        if (pushS != "") {
//          codeArray.push_back(pushS);
//        }
//        leftPos += range + 1;
//      }
//        // check if the char is a left bracket
//      else if (currentString[i] == '(') {
//        flagInBrackets = 1;
//        range = i - leftPos;
//        pushS = currentString.substr(leftPos, range);
//        if (pushS != "") {
//          codeArray.push_back(pushS);
//        }
//        leftPos += range + 1;
//      }
//        // check if the char is a comma
//      else if (currentString[i] == ',') {
//        range = i - leftPos;
//        pushS = currentString.substr(leftPos, range);
//        if (pushS != "") {
//          codeArray.push_back(pushS);
//        }
//        leftPos += range + 1;
//      }
//        // check if the char is right bracket
//      else if (currentString[i] == ')') {
//        flagInBrackets = 0;
//        range = i - leftPos;
//        pushS = currentString.substr(leftPos, range);
//        if (pushS != "") {
//          codeArray.push_back(pushS);
//        }
//        leftPos += range + 1;
//      }
//        // check if the char is =>
//      else if (currentString[i] == '=' && currentString[i + 1] == '>') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos += 2;
//          i++;
//        }
//        codeArray.push_back("=>");
//      }
//        // check if the char is <-
//      else if (currentString[i] == '<' && currentString[i + 1] == '-') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          codeArray.push_back(pushS);
//          leftPos += range + 1;
//        } else {
//          leftPos += 2;
//          i++;
//        }
//        codeArray.push_back("<-");
//      }
//        // check if the char is <=
//      else if (currentString[i] == '<' && currentString[i + 1] == '=') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos += 2;
//          i++;
//        }
//        codeArray.push_back("<=");
//      } else if (currentString[i] == '=' && currentString[i + 1] == '=') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos += 2;
//          i++;
//        }
//        codeArray.push_back("==");
//      } else if (currentString[i] == '!' && currentString[i + 1] == '=') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos += 2;
//          i++;
//        }
//        codeArray.push_back("!=");
//      }
//        // check if the char is =
//      else if (currentString[i] == '=') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos++;
//        }
//        codeArray.push_back("=");
//
//        //after "=" there is an expression that should be in one cell.
//        string expression;
//        for (int j = i + 1; j < currentString.size(); j++) {
//          if (currentString[j] != ' ') {
//            expression += currentString[j];
//          }
//        }
//        codeArray.push_back(expression);
//        i = currentString.size();
//      }
//        // check if the char is <
//      else if (currentString[i] == '<') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos++;
//        }
//        codeArray.push_back("<");
//      }
//        // check if the char is >
//      else if (currentString[i] == '>') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          if (pushS != "") {
//            codeArray.push_back(pushS);
//          }
//          leftPos += range + 1;
//        } else {
//          leftPos++;
//        }
//        codeArray.push_back(">");
//      }
//        // check if the char is ->
//      else if (currentString[i] == '-' && currentString[i + 1] == '>') {
//        if (i != leftPos) {
//          range = i - leftPos;
//          pushS = currentString.substr(leftPos, range);
//          codeArray.push_back(pushS);
//          leftPos += range;
//        } else {
//          leftPos += 2;
//          i++;
//        }
//        codeArray.push_back("->");
//      }
//        //end of string
//      else if (i == currentString.size() - 1) {
//        range = i - leftPos;
//        if (range != 0) {
//          pushS = currentString.substr(leftPos, range + 1);
//        } else {
//          pushS = currentString[i];
//        }
//        codeArray.push_back(pushS);
//      }
//    }
//  }
//  this->lex = codeArray;
//  for(string str: this->lex){
//    cout<<str<<endl;
//  }
//}


