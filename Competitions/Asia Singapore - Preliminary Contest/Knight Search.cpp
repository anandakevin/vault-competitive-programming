#include <iostream>
using namespace std;

bool checkString(char board[][100], string b, int x, int y, int len){

    if(x)checkString(board, b, )
}

int main(){
    int a; cin >> a;
    char board[a][100];
    string
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(board[i][j] == 'I') checkString(board, "", i, j, a);
        }
        cout << endl;
    }
    return 0;
}
