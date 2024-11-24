#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct numbers{
    int val, count = 0;
};

vector<numbers> countTotal;
int nums[100001];
int numOfT, ttlAllow;

void show(){
    for(int i = 0; i < countTotal.size(); i++) {
        cout << countTotal[i].val << " " << countTotal[i].count << endl;
    }
}

int solve(int currIdx){
    // cout << currIdx << endl;
    if(currIdx >= numOfT) return 1;
    bool check = true;
    int ttlTaken = 0;
    for(int i = 0; i < countTotal.size(); i++){
        if(countTotal[i].val == nums[currIdx]) {
            check = false;
            countTotal[i].count++;
        }
        if(countTotal[i].count <= ttlAllow) ttlTaken += countTotal[i].count;
    }
    if(check) {
        numbers temp;
        temp.val = nums[currIdx];
        temp.count = 1;
        countTotal.push_back(temp);
        if(1 <= ttlAllow) ttlTaken++;
    }
    // show();
    // cout << "Total: " << ttlTaken << endl;
    return max(ttlTaken, solve(currIdx + 1));
    
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int poss = 0;
        cin >> numOfT >> ttlAllow;
        for(int j = 0; j < numOfT; j++) cin >> nums[j];
        // for(int j = 0; j < numOfT; j++){
        //     int idx = -1;
        //     for(int k = j; k > 0; k--){
        //         if(nums[k].val == nums[j].val) {
        //             idx = k; break;
        //         }
        //     }
        //     nums[j].count = ((idx == -1) ? 0 : nums[idx].count) + 1;
        // }
        int maxCount = 0;
        for(int j = 0; j < numOfT; j++) {
            countTotal.clear();
            // cout << "j: " << j << endl;
            maxCount = max(maxCount, solve(j));
        }
        cout << "Case #" << i << ": " << maxCount << endl;
    }
    return 0;
}