#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

vector<string> lexer(ifstream &file);

int main() {
    vector<string> codeArray;
    ifstream codeFile;
    codeFile.open("fly");
    if(codeFile.is_open()){
        codeArray = lexer(codeFile);
    }else{
        cout << "file not open" << endl;
    }
}



vector<string> lexer(ifstream &codeFile) {

    vector<string> codeArray;

    //save the current the string that we read from the file.
    string currentString;

    //if the file is not null
    if (!codeFile.is_open()) {
        cout << "file not open" << endl;
    } else {
        while (getline(codeFile, currentString)) {
            int leftPos = 0;
            int range = 0;
            string pushS;
            int flagInBrackets = 0;

            for (int i = 0; i < currentString.size(); i++) {
                //check if there is tab
                if(currentString[i] == '\t'){
                    leftPos += i +1;
                }
                    //check if the char is a space and it is not in a brackets
                else if (currentString[i] == ' ' && !flagInBrackets) {
                    range = i - leftPos;
                    pushS = currentString.substr(leftPos, range);
                    if(pushS != ""){
                        codeArray.push_back(pushS);
                    }
                    leftPos += range + 1;
                }
                    // check if the char is a left bracket
                else if (currentString[i] == '(') {
                    flagInBrackets = 1;
                    range = i - leftPos;
                    pushS = currentString.substr(leftPos, range);
                    if(pushS != ""){
                        codeArray.push_back(pushS);
                    }
                    leftPos += range + 1;
                }
                    // check if the char is a comma
                else if (currentString[i] == ',') {
                    range = i - leftPos;
                    pushS = currentString.substr(leftPos, range);
                    if(pushS != ""){
                        codeArray.push_back(pushS);
                    }
                    leftPos += range + 1;
                }
                    // check if the char is right bracket
                else if (currentString[i] == ')') {
                    flagInBrackets = 0;
                    range = i - leftPos;
                    pushS = currentString.substr(leftPos, range);
                    if(pushS != ""){
                        codeArray.push_back(pushS);
                    }
                    leftPos += range + 1;
                }
                // check if the char is =>
                else if (currentString[i] == '=' && currentString[i+1] == '>') {
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
                        leftPos += range;
                    } else {
                        leftPos += 2;
                        i++;
                    }
                    codeArray.push_back("<-");
                }
                // check if the char is <=
                else if (currentString[i] == '<' && currentString[i+1] == '=' ) {
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
                // check if the char is =
                else if (currentString[i] == '=') {
                    if (i != leftPos) {
                        range = i - leftPos;
                        pushS = currentString.substr(leftPos, range);
                        if(pushS != ""){
                            codeArray.push_back(pushS);
                        }
                        leftPos += range +1;
                    } else {
                        leftPos++;
                    }
                    codeArray.push_back("=");
                }
                // check if the char is <
                else if (currentString[i] == '<') {
                    if (i != leftPos) {
                        range = i - leftPos;
                        pushS = currentString.substr(leftPos, range);
                        if(pushS != ""){
                            codeArray.push_back(pushS);
                        }
                        leftPos += range +1;
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
                //elementary arithmetic functions saved in a separate cell
                else if (currentString[i] == '/' && !flagInBrackets) {
                    codeArray.push_back("/");
                    leftPos++;
                }
                else if (currentString[i] == '+' && !flagInBrackets) {
                    codeArray.push_back("+");
                    leftPos++;
                }
                else if (currentString[i] == '-' && !flagInBrackets) {
                    codeArray.push_back("-");
                    leftPos++;
                }
                else if (currentString[i] == '*' && !flagInBrackets) {
                    codeArray.push_back("*");
                    leftPos++;
                }
                //end of string
                else if (i == currentString.size() - 1) {
                    range = i - leftPos;
                    if(range != 0){
                        pushS = currentString.substr(leftPos, range+1);
                    }
                    else{
                        pushS = currentString[i];
                    }
                    codeArray.push_back(pushS);
                }
            }
            //end of a line
            codeArray.push_back(";");
        }


        //print vector
        int size = codeArray.size();
        for (int i = 0; i < size; i++) {
            cout << i << endl;
            cout << "codeArray: " + codeArray.back() << endl;
            codeArray.pop_back();
        }
    }
    return codeArray;
}

