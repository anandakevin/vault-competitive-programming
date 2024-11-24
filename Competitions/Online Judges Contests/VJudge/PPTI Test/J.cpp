#include <iostream>
using namespace std;

struct triangle{
    int x1, y1, x2, y2, x3, y3;
};

triangle tri[150000];


int num;

int solve(int mask){
    if(mask == 0){
        return num;
    }
    if()
}

int main(){
    cin >> num;
    int idx = 0;
    while(num--){
        int x1, y1, x2, y2, x3, y3;
        cin >> tri[idx].x1 >> tri[idx].y1 
        >> tri[idx].x2 >> tri[idx].y2 
        >> tri[idx].x3 >> tri[idx].y3;
    }
    cout << solve(1 << num) << endl;
    return 0;
}