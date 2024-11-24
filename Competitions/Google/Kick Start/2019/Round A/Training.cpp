#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int stud[100001]; //-1 kosong, n = Si, 
int ttlStudent, team;
int taken[100001];

void reset(){
    for(int i = 0; i < 100001; i++) {
        stud[i] = -1;
        taken[i] = -1; 
    }
}

long long countTime(){
    int maxVal = -1, maxIndex = -1;
    for(int i = ttlStudent - 1; i >= 0 ; i--) {
        if(taken[i] == 1) {
            //maxVal = stud[i];
            maxIndex = i;
        }
    }
    long long ttlDiff = 0;
    // cout << "ini isi temp" << endl;
    for(int i = 0; i < ttlStudent; i++){
        if(taken[i] == 1) ttlDiff += (stud[maxIndex] - stud[i]);
    }
    // cout << "ini diffnya " << ttlDiff << endl;
    return ttlDiff;
}

long long solve(int currStud, int ttlTakenStud){
    //cout << "masuk " << ttlTakenStud << " " << currStud << " " << ttlStudent - currStud << " " << team << endl;
    if(ttlTakenStud + ttlStudent - currStud < team) {
        // cout << "dia return" << endl;
        return 100000;
    }
    if(ttlTakenStud > team || currStud > ttlStudent) return countTime();
    long long reqTime = 1000001;
    taken[currStud] = 1;
    reqTime = min(solve(currStud + 1, ttlTakenStud + 1), reqTime);
    taken[currStud] = -1;
    reqTime = min(solve(currStud + 1, ttlTakenStud), reqTime);
    return reqTime;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        cin >> ttlStudent >> team;
        reset();
        for(int j = 0; j < ttlStudent; j++) cin >> stud[j];
        sort(begin(stud), begin(stud) + (ttlStudent - 1));
        // cout << "tess" << endl;
        cout << "Case #" << i << ": " << solve(0, 0) << endl;
    }
    return 0;
}