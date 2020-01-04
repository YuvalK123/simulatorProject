////
//// Created by yuval Kasner on 26/12/19.
////

#include "SimManager.h"
#include "mutex"
//#include "SimulatorHelper.h"
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
                    if(flagInBrackets == 1 ){
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
                        if(currentString[i+1] != ',' && currentString[i+1] != ')'){
                            throw "string error";
                        }
                        commas = 0;
                    } else {
                        if((currentString[i-1] != ',' && currentString[i-1] != '(') || ((currentString[i-1] == ' ' &&
                        currentString[i-2] != ',' &&  currentString[i-2] != '('))){
                            throw "string error";
                        }
                        commas = 1;
                    }
                }
                    // check if the char is right bracket
                else if (currentString[i] == ')') {
                    flagInBrackets--;
                    if(flagInBrackets == 0){
                        range = i - leftPos;
                        pushS = currentString.substr(leftPos, range);
                        if (pushS != "") {
                            if(pushS.find('"') == string::npos && (pushS.find('+') != string::npos  ||
                            pushS.find('-') != string::npos || pushS.find('*') != string::npos  || pushS.find('/') != string::npos)){
                                int j=0;
                                string newPush;
                                for(j= 0; j < pushS.size(); j++){
                                    if(pushS[j] != ' '){
                                        newPush += pushS[j];
                                    }
                                }
                                codeArray.push_back(newPush);
                            }
                            else {
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
                            if(currentString[j] == '"'){
                                throw "eror: string in math expression";
                            }else {
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
                    curlyBrackets = 1;
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
                    curlyBrackets = 0;
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
                    if(currentString[i+1] != ',' && currentString[i+1] != ')'){
                        throw "string error";
                    }
                    commas = 0;
                } else {
                    commas = 1;
                }
            }
        }

        if(flagInBrackets == 1){
            throw "brackets problem!";
        }
    }

    if(curlyBrackets == 1){
        throw "curly brackets problem!";
    }
    this->lex = codeArray;


    //print vector
    int size = codeArray.size();
  for (int i = 0; i < size; i++) {
   // cout << i << endl;
    cout << codeArray.back() << endl;
    codeArray.pop_back();
  }
}

void SimManager::parser() {
    int index = 0;
    auto it = (this->lex).begin();
//  for (string str : this->lex) {
//    cout << str << endl;
//  }
    cout << "lex size is " << (this->lex.size()) << endl;
    while (index < this->lex.size()) {
        Command *c = nullptr;
        c = this->commandMap[*(it + index)];
        if (c != nullptr) {
//      cout<<"index is "<< index<< " and next is "<<*(it + index)<<endl;
            index += c->execute(it + index);
        } else {
//      cout<<"index is "<< index<< " and next is "<<*(it + index)<<endl;
            c = this->commandMap["var"];
            index += c->execute(it + index);
        }
    }

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
        this->id2InIndex.insert(make_pair(match_str, i));
        i++;
    }
    for (long t = 0; t < this->id2InIndex.size(); t++) {
        this->inVals.push_back(0.0);
    }
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
vector<double>::iterator SimManager::getInIndex(string str) {
    int ind = this->id2InIndex[str];
    return (this->inVals.begin() + ind);
}

void SimManager::assignValByVec(const vector<string> &vals) {
    vector<double> vec;
    double x;
    int i = 0;
    for (const string &str:vals) {
        try {
            x = stod(str);
            if(i == 35){
                cout << x << endl;
            }
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
}
void SimManager::sendMsg(const string &msg) {
    int x = this->client->sendMsg(msg);
}




