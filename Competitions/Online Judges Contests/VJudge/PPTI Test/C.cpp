#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double beg;
    int x, y; cin >> beg >> x >> y;
    double percent = ((100.00  - x) * y) / 10000;
    double diff = (percent / (1 - percent)) * beg;
    cout << fixed << setprecision(4);
    cout << beg << " ";
    beg += diff;
    cout << beg << " ";
    beg *= (100.00 - x) / 100.00;
    cout << beg << " " << beg - diff << " " << beg - diff << endl;
    return 0;
}