#include <iostream>
using namespace std;

int convertColor(string col){
    int currColor = (col == "RED") ? 1 : 
                    ((col == "BLUE") ? 2 : 
                    ((col == "YELLOW") ? 3 :
                    ((col == "GREEN") ? 4 : 
                    ((col == "ORANGE") ? 5 : 
                    ((col == "VIOLET") ? 6 : 
                    ((col == "BROWN") ? 7 : 8))))));
                    //8 PINK
    return currColor;
}

bool checkComponent(int areaColor, int currColor){
    if(areaColor == 5){
        if(currColor == 1 || currColor == 3) return true;
    }
    else if(areaColor == 4){
        if(currColor == 2 || currColor == 3) return true;
    }
    else if(areaColor == 6){
        if(currColor == 1 || currColor == 2) return true;
    }
    return false;
}

int main(){
    int x, y, torches;
    cin >> x >> y >> torches;
    int pos[x + 1][y + 1];
    string col; cin >> col;
    int currColor = convertColor(col);
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){ 
            pos[i][j] = 0;
        }
    }
    while(torches--){
        string torchColor;
        int posX, posY, range;
        cin >> torchColor >> posX >> posY >> range;
        int tempCol = convertColor(torchColor);
        for(int i = posX; i < range && i < x; i++){
            for(int j = posY; j < range && j < y; j++){
                if(pos[i][j] == 0) pos[i][j] = tempCol;
                else if((pos[i][j] == 1 && tempCol == 2) || (pos[i][j] == 2 && tempCol == 1)) 
                    pos[i][j] = 6;
                else if((pos[i][j] == 2 && tempCol == 3) || (pos[i][j] == 3 && tempCol == 2))
                    pos[i][j] = 4;
                else if((pos[i][j] == 1 && tempCol == 3) || (pos[i][j] == 3 && tempCol == 1))
                    pos[i][j] = 5;
                else if(checkComponent(pos[i][j], tempCol))
                    pos[i][j] = 8;
                else pos[i][j] = 7;
            }
        }
    }
    int ttlCol = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            cout << pos[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(pos[i][j] == currColor) ttlCol++;
        }
    }
    cout << ttlCol << endl;
    return 0;
}