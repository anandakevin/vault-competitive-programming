#include <iostream>
#include <vector>
using namespace std;

struct dancer{
    int point, currleftaround, prevleftaround;
    float currintpoint, previntpoint;
};

vector<vector<dancer>> map;

bool lose(int row, int col) {
    float intpoint;
    if(map.at(row).at(col).prevleftaround != 0) {
        intpoint = map.at(row).at(col).previntpoint / map.at(row).at(col).prevleftaround;   
    } else intpoint = 0;
    // cout << "at pos " << row << " " << col << " pt " << map.at(row).at(col).point << " intpoint " << map.at(row).at(col).previntpoint << " after divided " << intpoint << endl;
    if(map.at(row).at(col).point < intpoint) return true;
     
    return false;
}

void calibrate(long row, long col, long ttlrow, long ttlcol) {
    // cout << "for row " << row << " col " << col << endl;
    long left = -1, right = -1, up = -1, down = -1;
    long currrow = row, currcol = col-1;
    while(currcol > -1) {
        if(map.at(currrow).at(currcol).point != 0) {
            left = currcol;
            break;
        }
        currcol--;
    }
    // cout << "left " << left << endl;
    currrow = row-1, currcol = col;
    while(currrow > -1) {
        if(map.at(currrow).at(currcol).point != 0) {
            up = currrow;
            break;
        }
        currrow--;
    }
    // cout << "up " << up << endl;
    currrow = row+1, currcol = col;
    while(currrow < ttlrow) {
        if(map.at(currrow).at(currcol).point != 0) {
            down = currrow;
            break;
        }
        currrow++;
    }
    // cout << "down " << down << endl;
    currrow = row, currcol = col+1;
    while(currcol < ttlcol) {
        if(map.at(currrow).at(currcol).point != 0) {
            right = currcol;
            break;
        }
        currcol++;
    }
    // cout << "right " << right << endl;
    if(left != -1) {
        map.at(row).at(left).currintpoint -= map.at(row).at(col).point;
        map.at(row).at(left).currleftaround --;
        if(right != -1) {
            map.at(row).at(left).currintpoint += map.at(row).at(right).point;
            map.at(row).at(left).currleftaround ++;
        }
    }
    if(up != -1) {
        map.at(up).at(col).currintpoint -= map.at(row).at(col).point;
        map.at(up).at(col).currleftaround--;
        if(down != -1) {
            map.at(up).at(col).currintpoint += map.at(down).at(col).point;
            map.at(up).at(col).currleftaround++;
        }
    }
    if(right != -1) {
        map.at(row).at(right).currintpoint -= map.at(row).at(col).point;
        map.at(row).at(right).currleftaround--;
        if(left != -1) {
            map.at(row).at(right).currintpoint += map.at(row).at(left).point;
            map.at(row).at(right).currleftaround++;
        }
        
    }
    if(down != -1) {
        map.at(down).at(col).currintpoint -= map.at(row).at(col).point;
        map.at(down).at(col).currleftaround--;
        if(up != -1) {
            map.at(down).at(col).currintpoint += map.at(up).at(col).point;
            map.at(down).at(col).currleftaround++;
        }
    }
    map.at(row).at(col).point = map.at(row).at(col).currintpoint = map.at(row).at(col).previntpoint = 0;
}

long round(long row, long col) {
    long roundpoint = 0;
    for(long j = 0; j < row; j++) {
        for(long k = 0; k < col; k++) {
            if(map.at(j).at(k).point == 0) continue;
            roundpoint += map.at(j).at(k).point;
            if(lose(j, k)) {
                calibrate(j, k, row, col);
            }
            map.at(j).at(k).previntpoint = map.at(j).at(k).currintpoint;
            map.at(j).at(k).prevleftaround = map.at(j).at(k).currleftaround;
        }
    }
    return roundpoint;
}

void print(long row, long col) {
    for(long j = 0; j < row; j++) {
        for(long k = 0; k < col; k++) {
            cout << map.at(j).at(k).point << " ";
        }
        cout << endl;
    }
}

int main() {
    int rep; cin >> rep;
    vector <dancer> temprow;
    for(int i = 1; i <= rep; i++) {
        long row, col; cin >> row >> col;
        for(long j = 0; j < row; j++) {
            for(long k = 0; k < col; k++) {
                float num; cin >> num;
                dancer temp;
                temp.point = num;
                temprow.push_back(temp);
            }
            map.push_back(temprow);
            temprow.clear();
        }
        for(long j = 0; j < row; j++) {
            for(long k = 0; k < col; k++) {
                int intpoint = 0, around = 0;
                if(j > 0) {
                    intpoint += map.at(j-1).at(k).point;
                    around++;
                }
                if(k > 0) {
                    intpoint += map.at(j).at(k-1).point;
                    around++;
                }
                if(j < row - 1) {
                    intpoint += map.at(j+1).at(k).point;
                    around++;
                }
                if(k < col - 1) {
                    intpoint += map.at(j).at(k+1).point;
                    around++;
                }
                map.at(j).at(k).currintpoint = map.at(j).at(k).previntpoint = intpoint;
                map.at(j).at(k).currleftaround = map.at(j).at(k).prevleftaround = around;
            }
        }
        
        long ttlPoint = 0;
        long prevroundpoint = 0;
        int roundno = 1;
        while(true) {
            // cout << "beg round " << roundno << endl;
            // print(row, col);
            int roundpoint = round(row, col);
            // cout << "aft round " << roundno << endl;
            // print(row, col);
            // cout << "prev " << prevroundpoint << " curr " << roundpoint << endl; 
            if(prevroundpoint == roundpoint) break;
            else {
                ttlPoint += roundpoint;
                prevroundpoint = roundpoint;
            }
            roundno++;
        }
        
        cout << "Case #" << i << ": " << ttlPoint << endl;
        map.clear();
    }
    return 0;
}