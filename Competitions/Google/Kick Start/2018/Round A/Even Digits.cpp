#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long stringtoi(string str){
    long long int res = 0;
    for(int i = str.length() - 1, j = 0; i >= 0; i--, j++) res += (str[i] - '0') *  pow(10, j);
    return res;
}

int checkOdd(string num){
    for(int i = 0; i < num.length(); i++){
        cout << i << " " << num[i] << endl;
        if((num[i] - '0') % 2) return i;
    }
    return -1;
}

int checkOdd(int num, string str){
    int idx = 0;
    while(num > 0){
        if((num % 10) % 2) {
            return str.length() - 1 - idx;
        }
        idx++;
        num /= 10;
    }
    return -1;
}

long long getUp(long long num){
    string temp = to_string(num);
    long long idx, resNum = num;
    while((idx = checkOdd(resNum, temp)) != -1){
        string res = "";
        long long lowestNum = 0;
        while(lowestNum < (temp[idx] - '0'))   lowestNum += 2;
        int numBefore;
        if (lowestNum == 10) {
            res = temp;
            numBefore = res[idx] - '0' + 1;
            while(numBefore == 10){
                cout << "numbefore " << numBefore << " " << idx << endl;
                res = "";
                while((temp[idx - 1] + '1') == 10) {
                    if(idx > 0){
                        continue;
                        idx--;    
                    }
                    else if(idx == 0){
                        res += '1';
                        for(int i = 0; i < temp.length(); i++)
                    }
                }
                res += temp.substr(0, idx - 1);
                res += temp[idx - 1] + '1';
                res += '0';
                cout << "res " << res << " ulang didalam" << endl;
                for(int i = idx + 1; i < temp.length(); i++) res += '0'; 
                numBefore = res[--idx] - '0' + 1;
            }
            
            
        }
        // res = "";
        cout << "lowest " << num << " " << lowestNum << endl;
        cout << "bef " << res << " ";
        res += temp.substr(0, idx);
        cout << "bef " << res << " ";
        res += lowestNum + '0';
        cout << "aft " << res << endl;
        for(int i = idx + 1; i < temp.length(); i++) res += '0';
        temp = res;
        resNum = stringtoi(temp);
        cout << "up " << resNum << " " << res << " " << num << endl;    
    }
    return resNum - num;
}

long long getDown(long long num){
    string temp = to_string(num);
    long long idx;
    if((idx = checkOdd(temp)) == -1) return 0;
    string res = "";
    res += temp.substr(0, idx);
    long long highestNum = 10;
    while(highestNum > (temp[idx] - '0')) highestNum -= 2;
    res += highestNum + '0';
    for(int i = idx + 1; i < temp.length(); i++) res += '8';
    long long resNum = stringtoi(res);
    cout << "down " << resNum << " " << num << " " << resNum - num << endl;
    return num - resNum;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        long long num; cin >> num;
        long long res = min(getDown(num), getUp(num));
        cout << "Case #" << i << ": " << res << endl;
    }
}