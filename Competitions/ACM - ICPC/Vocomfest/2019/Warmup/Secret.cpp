#include <iostream>
using namespace std;

char ct[101][101];

void reset(){
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++) ct[i][j] = '0';
    }
}

char getMirror(char curr){
    int ascii = curr - 'A';
    if(ascii <= 12) return ascii + 'A' + 13;
    else return ascii + 'A' - 13;
}

char getChar(int x, int y, string mode){
    char temp;
    if(mode == "STANDARD") temp = ct[x][y];
    else temp = getMirror(ct[x][y]);
    return temp;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        reset();
        int size; cin >> size;
        string pat, cr; cin >> pat >> cr;
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                cin >> ct[j][k];
            }
        }
        string dec = "";
        if(pat == "SNAKE"){
            for(int j = 0; j < size; j++){
                if(j % 2 == 0){
                    for(int k = 0; k < size; k++) dec += getChar(j, k, cr);
                }
                else{
                    for(int k = size - 1; k >= 0; k--) dec += getChar(j, k, cr);
                }
                
            }
        }
        else if(pat == "N"){
            for(int j = size - 1; j >= 0; j--) dec += getChar(j, 0, cr);
            for(int j = 1, k = 1; j < size - 1 && k < size - 1; j++, k++) dec += getChar(k, j, cr);
            for(int j = size - 1; j >= 0; j--) dec += getChar(j, size - 1, cr);
        }
        else if(pat == "Z"){
            for(int j = 0; j < size; j++) dec += getChar(0, j, cr);
            for(int j = size - 2, k = 1; j > 0 && k < size - 1; j--, k++) dec += getChar(k, j, cr);
            for(int j = 0; j < size; j++) dec += getChar(size - 1, j, cr);
        }
        cout << "Case #" << i << ": " << dec << endl;
    }
    return 0;
}