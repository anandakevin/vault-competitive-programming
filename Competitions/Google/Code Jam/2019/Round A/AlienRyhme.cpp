#include <iostream>
using namespace std;

string inputs[1001];
bool same[1001];

void reset(int ttl){
    for(int i = 0; i < ttl; i++) {
        inputs[i] = "";
        same[i] = true;
    }
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int numOfInp; cin >> numOfInp;
        reset(numOfInp);
        int minLen = 51, minIdx = -1;
        for(int j = 0; j < numOfInp; j++) {
            cin >> inputs[j];
            if(inputs[j].length() < minLen) {
                minLen = inputs[j].length();
                minIdx = j;
            }
        }
        int ttlWords = 0, ttlTemp;
        for(int j = 1; j <= minLen; j++){
            ttlTemp = 0;
            char currChar = inputs[0][inputs[0].length() - j];
            for(int k = 0; k < numOfInp; k++){
                if(same[k]){
                    if(inputs[k][inputs[k].length() - j] == currChar) ttlTemp++;
                    else same[k] = false;
                }
            }
            if(ttlTemp > ttlWords) ttlWords = ttlTemp;
            else break;
        }
        if(ttlWords != 1) cout << "Case #" << i << ": " << ttlWords << endl;
        else cout << "Case #" << i << ": 0" << endl;
    }
    return 0;
}