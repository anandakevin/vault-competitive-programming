#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    double area = a * b * 0.5;
    cout << fixed << setprecision(2) << area << endl;
}