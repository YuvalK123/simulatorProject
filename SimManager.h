////
//// Created by yuval Kasner on 26/12/19.
////
//
#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
//
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "vector"
#include <regex>
#include "Command.h"
#include "Client.h"
#include "SimulatorHelper.h"

class SimManager {
        private:
        vector<string> lex;
        unordered_map<string, int> id2InIndex;
        vector<double> inVals;
        unordered_map<string, Command *> commandMap;
        unordered_map<string, vector<string>> funcMap;
        Client *client;

        public:
        explicit SimManager(unordered_map<string, Command *> commands);
        unordered_map<string, Command *> getCommands() { return this->commandMap; }
        unordered_map<string, vector<string>> *getFunctions() { return &(this->funcMap); }
        void initNodes();
        vector<string> lexer(ifstream &file);
        static vector<string> split(string str, const string &token);
        void assignValByVec(const vector<string> &vals);
        void sendMsg(const string &msg);
        void setClient(Client *c) { this->client = c; }
        double *valuePtr(string str);
        static string trim(string str);
};

double *SimManager::valuePtr(string str) {
    try {
        return &(this->inVals[this->id2InIndex[str]]);
    }
    catch (exception &e) {
        return new double(0.0);
//    cerr << "exeption in valuePtr " << e.what() << endl;
    }

}

SimManager::SimManager(unordered_map<string, Command *> commands) {
this->client = new Client();
this->commandMap = commands;
initNodes();
}
//
////lexer function separate the code to strings.
////input: a file that contains a code.
////output: vector to string that contains string from the code file.
vector<string> SimManager::lexer(ifstream &codeFile) {
vector<string> codeArray;
if (!codeFile.is_open()) {
throw "file not open";

}
//save the current the string that we read from the file.
string currentString;

//if the file is not null
int curlyBrackets = 0;
while (getline(codeFile, currentString)) {
unsigned int leftPos = 0;
int range = 0;
string pushS;
int flagInBrackets = 0;
int commas = 0;

for (unsigned int i = 0; i < currentString.size(); i++) {
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
unsigned int j = 0;
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
else if (currentString[i] == '=' && !flagInBrackets) {
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
for (unsigned int j = i + 1; j < currentString.size(); j++) {
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
return this->lex;
}

/**
 * adds all nodes from xml to map
 */
void SimManager::initNodes() {
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
}

/**
 *
 * @param str to split
 * @param token to split by
 * @return splitted string by vector
 */
vector<string> SimManager::split(string str, const string &token) {
vector<string> splitted;
while (!str.empty()) {
string::size_type index = str.find(token);
if (index != string::npos) {
splitted.push_back(str.substr(0, index));
str = str.substr(index + token.size());
if (str.empty()) {
splitted.push_back(str);
}
} else {
splitted.push_back(str);
str = "";
}
}
return splitted;
}
/**
 * method assigns to program values vector the values from server
 * @param vals from server
 */
void SimManager::assignValByVec(const vector<string> &vals) {
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
}
/**
 * @param msg to send to simulator
 */
void SimManager::sendMsg(const string &msg) {
this->client->sendMsg(msg);
}
/**
 * @param str to trim
 * @return string with no white spaces
 */
string SimManager::trim(string str) {
    size_t start = str.find_first_not_of(" ");
    str = (start == std::string::npos) ? "" : str.substr(start);
    size_t end = str.find_last_not_of(" ");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

//


#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_


