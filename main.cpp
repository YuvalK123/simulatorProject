#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>

//include commands
#include "commands/Command.h"
#include "commands/OpenServerCommand.cpp"
#include "commands/DefineVarCommand.cpp"
#include "commands/ConnectCommand.cpp"
#include "commands/IfCommand.cpp"
#include "commands/Print.cpp"
#include "commands/Sleep.cpp"
//#include "commands/ForLoop.cpp"

using namespace std;

vector<string> lexer(ifstream &file);
void parser(vector<string> codeArray);

int main() {
    vector<string> codeArray;
    ifstream codeFile;
    codeFile.open("try");
    if (codeFile.is_open()) {
        codeArray = lexer(codeFile);
       // parser(codeArray);
    } else {
        cout << "file not open" << endl;
    }
}

//parser function go throw the array and call to execute function if the string is a command or a variable.
//input: vector of strings that contains strings from the code file.
//output: none
void parser(vector<string> codeArray){

    unordered_map <string,Command> commandMap;
    //how??
    unordered_map <string,DefineVarCommand> symbolTable;

    //create the command map
    OpenServerCommand open;
    commandMap["openDataServer"] = open;
    ConnectCommand connect;
    commandMap["connectControlClient"] = connect;
    DefineVarCommand defineVar;
    commandMap["var"] = defineVar;
    /*IfCommand ifC;
    commandMap["if"]= ifC;
    ForLoop forC;
    commandMap["for"] = forC;*/
    Print printC;
    commandMap["Print"] = printC;
    Sleep sleepC;
    commandMap["Sleep"] = sleepC;


    for(int i=0; i<codeArray.size();i++){
        //if the string is a command
        if(commandMap.count(codeArray[i] ) > 0){
            Command c = commandMap[codeArray[i]];
            i += c.execute();
        }
        else{
            string var = codeArray[i];
            //if the string is a var
            if(symbolTable.count(var) > 0){
                i += symbolTable[var].execute();
            }
        }
    }
}

//lexer function separate the code to strings.
//input: a file that contains a code.
//output: vector to string that contains string from the code file.
vector<string> lexer(ifstream &codeFile) {

    vector<string> codeArray;

    //save the current the string that we read from the file.
    string currentString;

    //if the file is not null
    if (!codeFile.is_open()) {
        cout << "file not open" << endl;
    } else {
        int firstLine = 0;
        while (getline(codeFile, currentString)) {
            firstLine++;
            int start = 0;
            int leftPos = 0;
            int range = 0;
            string pushS;
            int flagInBrackets = 0;

            //if is the first line in the file
            if(firstLine == 1){
                leftPos = 3;
                start = 3;
            }


            for (int i = start; i < currentString.size(); i++) {

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
                        leftPos += range +1;
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
                }
                else if (currentString[i] == '=' && currentString[i + 1] == '=') {
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
                }
                else if (currentString[i] == '!' && currentString[i + 1] == '=') {
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
                    for(int j=i + 1;j<currentString.size();j++){
                        if(currentString[j]  != ' '){
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

        //print vector
        int size = codeArray.size();
        for (int i = 0; i < size; i++) {
            cout << i << endl;
            cout << "codeArray:" + codeArray.back() << endl;
            codeArray.pop_back();
        }
    }
    return codeArray;
}

