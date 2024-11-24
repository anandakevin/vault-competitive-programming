#include <iostream>
using namespace std;

int beautyVal[50][30];

void reset(int row, int plate) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < plate; j++) {
            beautyVal[i][j] = 0;
        }
    }
}

int main() {
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++) {
        int bval = 0;
        int rowTot, plateEach; cin >> rowTot >> plateEach;
        reset(rowTot, plateEach);
        for(int j = 0; j < rowTot; j++) {
            for(int k = 0; k < plateEach; k++) cin >> beautyVal[j][k];
        }
        cout << "Case #" << i << ": " << bval << endl;
    }
    return 0;
}