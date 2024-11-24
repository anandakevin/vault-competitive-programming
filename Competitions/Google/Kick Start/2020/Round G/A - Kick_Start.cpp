#include <iostream>
using namespace std;

int main() {
    int rep; cin >> rep;
    string inp; getline(cin, inp);
    for(int i = 0; i < rep; i++) {
        getline(cin, inp);
        int len = inp.length();
        bool iskick = false, isstart = false;
        int curridx = 0, totalkick = 0, ttlluckyfragment = 0;
        for(int j = 0; j < len; j++) {
            if(iskick) {
                if(curridx == 1 && inp[j] == 'I') curridx++;
                else if(curridx == 2 && inp[j] == 'C') curridx++;
                else if(curridx == 3 && inp[j] == 'K') {
                    curridx = 0;
                    totalkick++;
                    iskick = false;
                } else {
                    curridx = 0;
                    iskick = false;
                }
            } else if(isstart) {
                if(curridx == 1 && inp[j] == 'T') curridx++;
                else if(curridx == 2 && inp[j] == 'A') curridx++;
                else if(curridx == 3 && inp[j] == 'R') curridx++;
                else if(curridx == 4 && inp[j] == 'T') {
                    curridx = 0;
                    ttlluckyfragment += totalkick;
                    isstart = false;
                } else {
                    curridx = 0;
                    isstart = false;
                }
            } 
            if (iskick == false && isstart == false) {
                if (inp[j] == 'K') {
                    iskick = true;
                    curridx++;
                } else if(inp[j] == 'S') {
                    isstart = true;
                    curridx++;
                } else {
                    iskick = isstart = false;
                    curridx = 0;
                }
            }
            // cout << inp[j] << curridx << totalkick << ttlluckyfragment << endl;
        }
        cout << "Case #" << (i+1) << ": " << ttlluckyfragment << endl;
    }
    return 0;
}