#include <iostream>
#include <vector>
using namespace std;

int searchIdx(int num, vector<int> vec, int len) {
    for(int i = 0; i < len; i++) {
        if(vec[i] == num) return i;
    }
    return -1;
}

int getIdxBefore(int num, vector<int> vec, int len) {
    for(int i = 0; i < len; i++) {
        if(vec[i] > num) return i;
    }
    return -1;
}

int square(int a) {
    return a*a;
}

int countDist(int a, int b){
    return square(max(a, b) - min(a, b) - 1);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    vector<int> stones;
    int numOfStones = 0;
    int n, m, q; cin >> n >> m >> q;
    int currnumber = 1;
    for(int i = 0; i < m; i++) {
        int temp; cin >> temp;
        for(;currnumber < temp;currnumber++) {
            stones.push_back(currnumber);
            numOfStones++;
        }
        currnumber++;
    }
    for(;currnumber <= n; currnumber++) {
        numOfStones++;
        stones.push_back(currnumber);
    }
    for(int i = 0; i < q; i++) {
        for (int x : stones) cout << x << " ";
        // cout << endl;
        string cmd; cin >> cmd;
        if(cmd == "go") {
            int dist = 0;
            int a, b; cin >> a >> b;
            if(a > b) swap(a, b);
            // cout << "GO yang " << a << " " << b << endl;
            int idxa = searchIdx(a, stones, numOfStones);
            int idxb = searchIdx(b, stones, numOfStones);
            // cout << "idxnya " << idxa << " " << idxb << endl;
            for(int i = idxa; i < idxb; i++) {
                // cout << "Dist: " << dist << endl;
                dist += countDist(stones[i], stones[i + 1]);
            }
            cout << dist << endl;
        } else {
            int modif; cin >> modif;
            if(cmd == "rem") {
                int idx = searchIdx(modif, stones, numOfStones);
                stones.erase(stones.begin() + idx);
            }
            if(cmd == "add") {
                int idx = getIdxBefore(modif, stones, numOfStones);
                stones.insert(stones.begin() + idx, modif);
            }
        }
    }
}