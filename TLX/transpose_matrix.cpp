#include <iostream>
using namespace std;

int main() {
    int num[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cin >> num[i][j];
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << num[j][i];
            if(j < 2) cout << " ";
        }
        cout << endl;
    }
}