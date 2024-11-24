//masih WA
#include <iostream>
using namespace std;

struct pos{
    int x, y;
} board[401];

struct nextNode{
    int nextPos;
} nodes[401];

int memo[401], taken[401];
int ttlEdge;

bool valPos(int pos1, int pos2){
    // cout << board[pos1].x << " " << board[pos1].y << " " << board[pos2].x << " " << board[pos2].y << endl;
    if(board[pos1].x == board[pos2].x) return false;
    if(board[pos1].y == board[pos2].y) return false;
    if(board[pos1].x - board[pos1].y == board[pos2].x - board[pos2].y) return false;
    if(board[pos1].x + board[pos1].y == board[pos2].x + board[pos2].y) return false;
    // cout << "bener" << endl;
    return true;
}

int solve(int currIdx, int ttlTaken){
    // cout << currIdx << " " << ttlTaken << endl;
    if(ttlTaken == ttlEdge) {
        // cout << "keluar lgsg " << currIdx << " " << ttlTaken << endl;
        return 1;
    }
    if(memo[currIdx] != -1) return memo[currIdx];
    int possibility = 0;
    taken[currIdx] = 1;
    for(int i = 0; i < ttlEdge; i++){
        if(taken[i] != 1 && valPos(currIdx, i)) {
            // cout << "masuk " << i << endl;
            int res = solve(i, ttlTaken + 1);
            if(res == 1) {
                // cout << "nextnya " << i << endl;
                nodes[currIdx].nextPos = i;
                possibility = 1; break;
            }
            
        }
    }
    taken[currIdx] = 0;
    // cout << "keluar " << currIdx << " " << ttlTaken << endl;
    return memo[currIdx]= possibility;
}

void printList(int startIdx, int ttlPrinted){
    cout << board[startIdx].x << " " << board[startIdx].y << endl;
    if(ttlPrinted == ttlEdge) return;
    printList(nodes[startIdx].nextPos, ttlPrinted + 1);
}

void resetMemo(){
    int mask = (1 << 20) - 1;
    for(int i = 0; i < 101; i++){
        memo[i] = -1;
        taken[i] = 0;
        nodes[i].nextPos = -1;
    }
}

void resetBoard(){
    for(int i = 0; i < 21; i++){
        board[i].x = board[i].y = 0;
    }
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        int x, y; cin >> x >> y;
        ttlEdge = x * y;
        resetBoard();
        for(int j = 1, currIdx = 0; j <= x; j++){
            for(int k = 1; k <= y; k++) {
                board[currIdx].x = j;
                board[currIdx++].y = k;
            }
        }
        bool possible = false;
        int trueIdx = -1;
        for(int j = 0; j < ttlEdge; j++){
            resetMemo();
            // cout << "start dari " << j << endl;
            int temp = solve(j, 1);
            if(temp) {
                possible = true;
                trueIdx = j;
                // cout << "ini bener " << j << " " << trueIdx << endl;
                break;
            }
        }
        cout << "Case #" << i << ": " << ((possible) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        if(possible) printList(trueIdx, 1);
    }
    return 0;
}