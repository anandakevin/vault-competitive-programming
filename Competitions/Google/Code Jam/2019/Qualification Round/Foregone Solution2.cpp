#include <iostream>
#include <vector>
using namespace std;

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
        vector<int> blocks, temp, preSum;
        blocks.push_back(inp);
        int a, b;
        bool repeat = true;
        do{
            do{
                int currNum = blocks[0];
                int currAdd = currNum / 2;
                temp.push_back(currAdd);
                if(preSum.size() == 0) preSum.push_back(currAdd);
                else preSum.push_back(preSum.at(preSum.size() - 1) + currAdd);
                // cout << "temp " << temp[temp.size() - 1] << " " << preSum[preSum.size() - 1] << endl;
                currAdd += (currNum % 2 == 0) ? 0 : 1;
                temp.push_back(currAdd);
                preSum.push_back(preSum.at(preSum.size() - 1) + currAdd);
                // cout << "temp " << temp[temp.size() - 1] << " " << preSum[preSum.size() - 1] << endl;
                blocks.erase(blocks.begin());
            } while(blocks.size() > 0);
            blocks = temp;
            temp.clear();
            for(int j = 0; j < blocks.size(); j++){
                if(checkFour(blocks[i])) continue;
            }
            // for(int j = 0; j < blocks.size(); j++){
            //     cout << blocks[j] << " ";
            // }
            // cout << endl;
            // for(int j = 0; j < preSum.size(); j++){
            //     cout << preSum[j] << " ";
            // }
            // cout << endl;
            for(int j = 0; j < preSum.size(); j++){
                if(!checkFour(preSum[preSum.size() - 1] - preSum[j]) && !checkFour(preSum[j])){
                    a = preSum[preSum.size() - 1] - preSum[j];
                    b = preSum[j];
                    cout << "Case #" << i << ": " << a << " " << b << endl;
                    repeat = false;
                    break;
                }
            }
            preSum.clear();
        } while(repeat);
    }
    return 0;
}