#include <iostream>
using namespace std;

string robots[255];
int numOfRobot;

void resetProgram() {
    for(int i = 0; i < 255; i++) robots[i] = "";
}

int checkWin(char a, char b) { //a pertama, b kedua
    if(a == 'R') {
        if(b == 'S') return 1;
        if(b == 'P') return -1;
        if(b == 'R') return 0;
    }
    if(a == 'P') {
        if(b == 'S') return -1;
        if(b == 'P') return 0;
        if(b == 'R') return 1;
    }
    if(a == 'S') {
        if(b == 'S') return 0;
        if(b == 'P') return 1;
        if(b == 'R') return -1;
    }
}

bool checkWinAll(int idx, char beingChecked) {
    for(int i = 0; i < numOfRobot; i++) {
        if(idx < robots[i].length() && checkWin(beingChecked, robots[i][idx]) < 1) return false;
        // else cout << beingChecked << " " << robots[i][idx] << endl;
    }
    return true;
}

string solve(int idx, int otherRobotsIdx, int restart, string currProgram) {
    int robotCt = 0;
    string resProgram = "";
    bool r = true, p = true, s = true;
    for(int i = 0; i < numOfRobot; i++) {
        if(otherRobotsIdx >= robots[i].length()) continue;
        robotCt++;
        switch(robots[i][otherRobotsIdx]) {
            case 'R': s = false; break;
            case 'P': r = false; break;
            case 'S': p = false; break;
        }
    }
    if(robotCt == 0) return currProgram;
    // cout << idx << " " << otherRobotsIdx << " " << currProgram << endl;
    char chars[3] = {'R', 'P', 'S'};
    if(restart == 0) {
        // for(int i = 0; i < 3; i++) {
        //     resProgram = currProgram + chars[i];
        //     // cout << i << " " << resProgram << endl;
        //     if(checkWinAll(otherRobotsIdx, resProgram[idx])) return resProgram;    
        //     else resProgram = "";
        // }
        if(r) resProgram = solve(idx + 1, otherRobotsIdx + 1, restart, currProgram + 'R');
        // cout << "yg R " << resProgram << endl;
        if(p) resProgram = solve(idx + 1, otherRobotsIdx + 1, restart, currProgram + 'P');
        // cout << "yg P " << resProgram << endl;
        if(s) resProgram = solve(idx + 1, otherRobotsIdx + 1, restart, currProgram + 'S');
        // cout << "yg S " << resProgram << endl;
    }    
    if(!(r || p || s)) {
        if(restart == 0) resProgram = solve(0, otherRobotsIdx + 1, 1, currProgram);
        else resProgram = solve(idx + 1, otherRobotsIdx + 1, 1, currProgram);
    }
    if(restart == 1 && currProgram.length() <= idx) idx = 0;
    // cout << "return " << idx << " " << otherRobotsIdx << endl;
    return resProgram;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++) {
        resetProgram();
        cin >> numOfRobot;
        for(int j = 0; j < numOfRobot; j++) cin >> robots[j];
        string res = solve(0, 0, 0, "");
        cout << "Case #" << i << ": " << ((res.length() > 0) ? res : "IMPOSSIBLE") << endl;
    }
    return 0;
}