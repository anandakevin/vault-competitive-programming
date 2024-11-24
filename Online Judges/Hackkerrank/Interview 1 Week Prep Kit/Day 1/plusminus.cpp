#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int inp; cin >> inp;
    float minus = 0, zero = 0, pos = 0;
    int temp;
    while(inp--) {
        cin >> temp;
        if(temp < 0) minus++;
        else if(temp == 0) zero++;
        else if(temp > 0) pos++;
    }
    
    float total = minus + zero + pos;
    cout << setprecision(6) << fixed << float(pos/total) << endl << float(minus/total) << endl << float(zero/total);
    return 0;
}