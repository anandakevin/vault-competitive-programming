#include <iostream>
#include <vector.h>
#define clear cin.clear(); cin.sync();

int main(){
    int rep; cin >> rep; clear;
    vector<long long> nums;
    for(int i = 0; i < rep; i++){
        int chc; cin >> chc; clear;
        if(chc != 3){
            int num;
            cin >> num;
            if(chc == 1) nums.push_front(num);
            else {
                for(int j = 0; j < nums.size(); j++){
                    
                }
            }
        }else{

        }
    }
}