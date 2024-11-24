#include <iostream>
#include <string>
using namespace std;

void printopen(int len) {
    for(int i = 0; i < len; i++) cout << '(';
}

void printclose(int len) {
    for(int i = 0; i < len; i++) cout << ')';
}

int main() {
    int rep; cin >> rep; string dummy;
    getline(cin, dummy);
    for(int i = 1; i <= rep; i++) {
        string inp; getline(cin, inp);
        int currnum, nextnum;
        cout << "Case #" << i << ": ";
        for(int j = 0, len = inp.length(); j < len; j++) {
            if(j == 0) {
                currnum = inp[j] - '0';
                printopen(currnum);
                cout << currnum;
            }
            if(j != len - 1) {
                currnum = inp[j] - '0';
                nextnum = inp[j + 1] - '0';
                if(j != 0) cout << currnum;
                if(currnum > nextnum) printclose(currnum - nextnum);
                else if(currnum < nextnum) printopen(nextnum - currnum);
            } else {
                currnum = inp[j] - '0';
                if(len != 1) cout << currnum;
                printclose(currnum);
            }
        }
        cout << endl;
    }
    return 0;
}