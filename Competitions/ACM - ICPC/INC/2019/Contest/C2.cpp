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
    // cout << "cari untuk tambah " << num << " " << len << endl;
    int i = 0;
    for(; i < len; i++) {
        // cout << i << " " << vec[i] << " " << num << endl;
        if(vec[i] > num) return i;
    }
    return i;
}

int square(int a) {
    return a*a;
}

int diff(int a, int b) {
    return max(a, b) - min(a, b);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    vector<int> stones;
    int n, m, q; cin >> n >> m >> q;
    int currnumber = 1;
    for(int i = 0; i < m; i++) {
        int temp; cin >> temp;
        stones.push_back(temp);
    }
    for(int i = 0; i < q; i++) {
        for (int x : stones) cout << x << " ";
        cout << endl;
        string cmd; cin >> cmd;
        if(cmd == "go") {
            int dist = 0;
            int a, b; cin >> a >> b;
            if(a > b) swap(a, b);
            int currpos = a;
            int curridx = getIdxBefore(a, stones, m), lenOfHole = 0;
            cout << "GO yang " << a << " " << b << endl;
            while(stones[curridx] < b && curridx <= m) {
                cout << curridx << " " << stones[curridx] << " " << stones[curridx + 1] << " " << lenOfHole << " " << dist << endl;
                if(diff(stones[curridx], stones[curridx + 1]) == 1) lenOfHole++;
                else {
                    dist += square(lenOfHole + 1);
                    lenOfHole = 0;
                }
                curridx++;
            }
            cout << dist << endl;
        } else {
            int modif; cin >> modif;
            if(cmd == "rem") {
                int idx = getIdxBefore(modif, stones, m);
                stones.insert(stones.begin() + idx, modif);
            }
            if(cmd == "add") {
                int idx = searchIdx(modif, stones, m);
                stones.erase(stones.begin() + idx);
            }
        }
    }
}