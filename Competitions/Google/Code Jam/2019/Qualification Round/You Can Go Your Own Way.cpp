#include <iostream>
using namespace std;

string way(string inp){
    string temp = "";
    for(int i = 0; i < inp.length(); i++){
        temp += (inp[i] == 'S') ? 'E' : 'S';
    }
    return temp;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int len; cin >> len;
        string l; cin >> l;
        cout << "Case #" << i << ": ";
        string res = "";
        cout << way(l) << endl;
    }
    return 0;
}