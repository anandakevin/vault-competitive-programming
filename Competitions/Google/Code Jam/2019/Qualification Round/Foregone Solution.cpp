#include <iostream>
using namespace std;

// int coba[500000000];

bool checkFour(int num){
    while(num > 0){
        if(num % 10 == 4) return true;
        num /= 10;
    }
    return false;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        long long inp; cin >> inp;
        long long diff = 0, a, b;
        while(true){
            if(!checkFour(inp - diff) && !checkFour(diff)) {
                cout << "Case #" << i << ": " << inp - diff << " " << diff << endl;
                break;
            }
            else if((diff < (inp / 2)) && (!checkFour(inp/2 - diff) && !checkFour((inp - inp/2) + diff))){
                cout << "Case #" << i << ": " << inp/2 - diff << " " << (inp - inp/2) + diff << endl;
                break;
            }
            else diff++;
        }
    }
    return 0;
}