#include <iostream>
using namespace std;

int row[100][100], col[100][100];

void reset(int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            row[i][j] = 0;
            col[i][j] = 0;
        }
    }
}

int main() {
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++) {
        int len; cin >> len;
        reset(len);
        int num, trace = 0;
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < len; k++) {
                cin >> num;
                if(j == k) trace += num;
                row[j][num-1]++;
                col[k][num-1]++;
            }
        }
        
        int ttlDupRow = 0, ttlDupCol = 0;
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < len; k++) {
                if(row[j][k] > 1) {
                    ttlDupRow++;
                    break;
                }
            }
        }
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < len; k++) {
                if(col[j][k] > 1) {
                    ttlDupCol++;
                    break;
                }
            }
        }
           
        
        cout << "Case #" << i << ": " << trace << " " << ttlDupRow << " " << ttlDupCol << endl;
    }
    return 0;
}