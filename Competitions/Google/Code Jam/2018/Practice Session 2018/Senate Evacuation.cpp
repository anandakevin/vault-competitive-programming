#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> num){
    int temp = 0;
    for(int i = 0; i < num.size(); i++) {
        if(num[i] > num[temp]) temp = i;
    }
    return temp;
}

int getTotal(vector<int> nums){
    int ttl = 0;
    for(int i = 0; i < nums.size(); i++) ttl += nums[i];
    return ttl;
}

bool val(vector<int> nums){
    int ttl = getTotal(nums);
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] * 2 > ttl) return false;
    }
    return true;
}

string solve(vector<int> nums){
    string tempOut = "";
    vector<int>temp = nums;
    int add;
    while(getTotal(nums) > 0){
        add = 1;
        int fmaxIndex = getMax(nums);
        if(temp[fmaxIndex] > 0) temp[fmaxIndex]--;
        if(val(temp)) {
            nums[fmaxIndex]--;
            tempOut += (fmaxIndex + 'A');
            add = 0;
        }
        int smaxIndex = getMax(temp);
        if(temp[smaxIndex] > 0) temp[smaxIndex]--;
        if(val(temp)) {
            nums[smaxIndex]--;
            if(add) {
                nums[fmaxIndex]--;
                tempOut += (fmaxIndex + 'A');
            }
            tempOut += (smaxIndex + 'A');
        }
        if(getTotal(temp)) tempOut += ' ';
    }
    return tempOut;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int ttl; cin >> ttl;
        vector<int> nums;
        while(ttl--){
            int temp; cin >> temp;
            nums.push_back(temp);
        }
        cout << "Case #" << i << ": " << solve(nums) << endl;
    }
}