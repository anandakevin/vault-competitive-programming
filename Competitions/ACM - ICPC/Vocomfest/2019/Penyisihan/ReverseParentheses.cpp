#include <iostream>
#include <ctype.h>
#include <vector>
using namespace std;

int main(){
    string inp; cin >> inp;
    string newInp = "", symbolTemp = "";
    for(int i = 0; i < inp.length(); i++){
        if(isalpha(inp[i])) newInp += inp[i];
        else symbolTemp += inp[i];
        if(symbolTemp.length() == 3){
            if(symbolTemp == "%20") newInp += 32;
            else if(symbolTemp == "%28") newInp += '(';
            else if(symbolTemp == "%29") newInp += ')';
            else if(symbolTemp == "%2C") newInp += ',';
            else if(symbolTemp == "%22") newInp += '"';
            else if(symbolTemp == "%27") newInp += 39; //'
            else if(symbolTemp == "%21") newInp += '!';
            else if(symbolTemp == "%3F") newInp += '?';
            symbolTemp = "";
        }
    }
    string ans = "";
    vector<string> temp; 
    bool rev = false;
    for(int i = 0; i < newInp.length(); i++){
        if(isalpha(inp[i])) ans += inp[i];
        else{
            if(inp[i] == '(')     
        }
    }
    cout << newInp << endl;
    return 0;   
}