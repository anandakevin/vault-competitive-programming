#include <iostream>
using namespace std;

int board[251][251];

void reset(){
    for(int i = 0; i < 251; i++){
        for(int j = 0; j < 251; j++) board[i][j] = -1;
    }
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int w, h; cin >> w >> h;
        reset();
        for(int j = 0; j < w; j++){
            for(int k = 0; k < h; k++) cin >> board[j][k];
        }
        
    }
    return 0;
}