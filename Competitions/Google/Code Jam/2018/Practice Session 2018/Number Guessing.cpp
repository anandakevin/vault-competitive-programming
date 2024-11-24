#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++){
        int lo, hi; cin >> lo >> hi;
        int maxGuess; cin >> maxGuess;
        int currNumOfGuess = 0;
        while(currNumOfGuess <= maxGuess && lo < hi){
            int mid = (lo + hi + 1) / 2;
            currNumOfGuess++;
            cout << mid << endl; fflush(stdout);
            string res; cin >> res;
            if(res == "CORRECT") break;
            else if(res == "TOO_SMALL") lo = mid;
            else hi = mid - 1;
        }
    }
    return 0;
}