#include <iostream>
using namespace std;

int countAlpha[26];

void resetAlpha(){
    for(int i = 0; i < 26; i++) countAlpha[i] = 0;
}

bool check(int from, int to, string inp){
    // cout << from << " " << to << endl;
    resetAlpha();
    for(int i = from - 1; i <= to - 1; i++) countAlpha[inp[i] - 'A'] += 1;
    int singles = 0;
    for(int i = 0; i < 26; i++){
        if(countAlpha[i] % 2 != 0) {
            if(singles == 0) singles++;
            else return false;
        }
    }
    // cout << "bener" << endl;
    return true;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int len, ques; cin >> len >> ques;
        string inp; cin >> inp;
        int poss = 0;
        for(int j = 0; j < ques; j++){
            int from, to; cin >> from >> to;
            poss += (check(from, to, inp)) ? 1 : 0;
        }
        cout << "Case #" << i << ": " << poss << endl;
    }
    return 0;
}