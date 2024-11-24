#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ttlPlant, m;
vector<vector<int>> plants;

int getIdx(int num){
  for(int i = 0; i < plants.size(); i++) {
    if(plants[i][0] == num) return i;
  }
  return -1;
}

bool check(const vector<int> a, const vector<int> b){
    return a[0]< b[0];
}

void show(){
    for(int i = 0; i < plants.size(); i++){
      for(int j = 0; j < plants[i].size(); j++) cout << plants[i][j] << " ";
      cout << endl;
    }
}

int checkPlantAround(int x, int y, int idx){
    // cout << "check " << plants[x][0] << " " << y << " " << x << " " << m << endl;
    int ttlFences = 4;
    if(x > 0) {
        // cout << "cek atas " << plants[x][0] << " " << y << " " <<  x << endl;
        for(int i = 1; i < plants[x - 1].size(); i++){
            // cout << "i awal " << " " << plants[x - 1][i] << " " << y << " " << x - 1 << endl;
            if(plants[x - 1][i] == y) ttlFences--;
            if(plants[x - 1][i] >= y) break;
        }
    }
    if(plants[x][idx - 1] == y - 1) ttlFences--;
    if(plants[x][idx + 1] == y + 1) ttlFences--;
    // cout << "ini " << x << " " << plants[x][0] << " " << y << endl;
    if(x < m - 1) {
        // cout << "untuk " << x + 1 << " dengan size " << plants[x + 1].size() << endl;
        for(int i = 1; i < plants[x + 1].size(); i++){
            if(plants[x + 1][i] == y) {
                // cout << " di " << plants[x + 1][i] << " " << y << endl;
                ttlFences--;
            }
            if(plants[x + 1][i] >= y) break;
        }
    }
    // cout << "total fence " << ttlFences << endl;
    return ttlFences;
}

int countFences(){
    int fences = 0;
    for(int i = 0; i < plants.size(); i++){
        for(int j = 1; j < plants[i].size(); j++) {
            //cout << "ini i j " << i << " " << j << " " << plants[i][0] << " " << plants[i][j] << " " << j << endl;
            fences += checkPlantAround(i, plants[i][j], j);
        }
    }
    return fences;
}

int main(){
  int rep; cin >> rep;
  while(rep--){
    ttlPlant = 0;
    int n, ctPlant;
    cin >> m >> n >> ttlPlant;
    ctPlant = ttlPlant;
    vector <int> temp;
    while(ctPlant--){
      int x, y; cin >> x >> y;
      int idx = getIdx(x);
      if(idx == -1) {
        temp.push_back(x);
        temp.push_back(y);
        plants.push_back(temp);
        temp.clear();
      }
      else plants[idx].push_back(y);
    }
    sort(plants.begin(), plants.end(), check);
    for(int i = 0; i < plants.size(); i++) sort(plants[i].begin() + 1, plants[i].end());
    // show();
    cout << countFences() << endl;
    plants.clear();
  }
  return 0;
}
