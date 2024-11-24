#include <iostream>
using namespace std;

int vowels[5];

void reset(){
    for(int i = 0; i < 5; i++) vowels[i] = 0;
}

void processString(char inp){
    switch(inp){
        case 'a': vowels[0]++; break;
        case 'i': vowels[1]++; break;
        case 'u': vowels[2]++; break;
        case 'e': vowels[3]++; break;
        case 'o': vowels[4]++; break;
    }
}

int checkVowel(){
    int num = 0;
    for(int i = 0; i < 5; i++){
        if(vowels[i] > 0) num++;
    }
    if(num == 5) return 1;
    else return 0;
}

int main(){
    string inp; cin >> inp; 
    int ttlSubstring = 0;
    bool isVowel;
    for(int i = 0; i < inp.length() - 5; i++){
        // cout << "ulang " << i << endl;
        reset();
        isVowel = false;
        for(int j = i; j < i + 5; j++) processString(inp[j]);
        int temp = checkVowel();
        if(temp == 1) isVowel = true;
        ttlSubstring += temp;
        int rest = 0;
        for(int j = i + 5; j < inp.length(); j++){
            if(isVowel){
                rest = j;
                // cout << "rest " << inp.length() - rest << " " << rest << " " << j << " ";
                break;
            }
            else{
                processString(inp[j]);
                temp += checkVowel();
                if(temp == 1) isVowel = true;
                ttlSubstring += temp;
            }
        }
        // cout << ttlSubstring << " ";
        if(rest != 0) ttlSubstring += (inp.length() - rest);
        // cout << ttlSubstring << endl;
    }
    cout << ttlSubstring << endl;
    return 0;
}