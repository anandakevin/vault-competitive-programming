#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct stones{
    int s, e, l, taken;
} stone[101];

int numOfStone;
int memo[10001];

// long long knapsack(int idx, int ttlTime, int ttlEnergy){
//     cout << "dalem " << idx << endl;
//     if(memo[ttlTime] != -1 && memo[ttlTime] > ttlEnergy)  return memo[ttlTime];
//     long long maxEnergy = ttlEnergy;
//     for(int i = 0; i < numOfStone; i++){
//         if(stone[i].taken == 0){
//             stone[i].taken = 1;
//             maxEnergy = max(maxEnergy, knapsack(i, ttlTime + stone[i].s, ttlEnergy + stone[i].e - (stone[i].l * ttlTime)));
//             stone[i].taken = 0;
//         }
//     }
//     cout << "keluar " << idx << endl;
//     return memo[ttlTime] = maxEnergy;
// }

bool check(const stones a, const stones b){
    return a.e > b.e;
}

void showStone(){
    for(int i = 0; i < numOfStone; i++) {
        cout << stone[i].s << " " << stone[i].e << " " << stone[i].l << endl;
    }
}

long long countOnly(){
    sort(stone, stone + numOfStone, check);
    // showStone();
    long long ttlEnergy = 0, ttlTime = 0;
    for(int i = 0; i < numOfStone; i++){
        // cout << ttlEnergy << " jadi ";
        long long currEnergy = stone[i].e - ttlTime * stone[i].l;
        ttlEnergy += (currEnergy > 0) ? currEnergy : 0;
        ttlTime += stone[i].s;
        // cout << ttlEnergy << endl;
    }
    return ttlEnergy;
}

void reset(){
    for(int i = 0; i < 101; i++){
        stone[i].s = stone[i].e = stone[i].l = stone[i].taken = 0;
    }
}

void resetValue(){
    for(int i = 0; i < 10001; i++) memo[i] = -1;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        reset();
        cin >> numOfStone;
        for(int j = 0; j < numOfStone; j++) cin >> stone[j].s >> stone[j].e >> stone[j].l;
        long long maxVal = 0;
        // for(int j = 0; j < numOfStone; j++){
        //     cout << "luar " << j << endl;
        //     resetValue();
        //     stone[j].taken = 1;
        //     maxVal = max(maxVal, knapsack(j, stone[j].s, stone[j].e));
        //     cout << "hasil sementara " << maxVal << endl;
        //     stone[j].taken = 0;
        // }
        cout << "Case #" << i << ": " << countOnly() << endl;
    }
    return 0;
}