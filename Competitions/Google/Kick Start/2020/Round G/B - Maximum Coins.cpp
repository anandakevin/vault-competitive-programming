#include <iostream>
#include <string.h>
using namespace std;

long vals[20000001];

void reset(int length) {
    for(int i = 0; i < length; i++) vals[i] = 0;
}

long findMax(int length) {
    long maxVal = 0;
    for(int i = 0; i < length; i++) {
        if(vals[i] > maxVal) maxVal = vals[i];
    }
    return maxVal;
}

void check(int length) {
    for(int i = 0; i < length; i++) cout << vals[i] << " ";
}

int main() {
    int rep; cin >> rep;
    for(int i = 0; i < rep; i++) {
        int ssize; cin >> ssize;
        long maxVal = 0;
        reset(ssize * 2 - 1);
        int ttldiag = ssize * 2 - 2;
        for(int j = 0; j < ssize; j++) {
            for(int k = 0; k < ssize; k++) {
                int temp; cin >> temp;
                vals[ttldiag - (ssize - 1 - k) - j] += temp;
            }
        }
        // check(ssize * 2 - 1); cout << endl;
        maxVal = findMax(ssize * 2 - 1);
        cout << "Case #" << (i+1) << ": " << maxVal << endl;
    }
    return 0;
}