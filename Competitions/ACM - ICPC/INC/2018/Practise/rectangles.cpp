#include <iostream>
using namespace std;

int map[101][101];

void reset(){
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++) map[i][j] = 0;
	}
}

void fill(int i, int x, int y){
	for(int a = i; a < x; a++){
		for(int j = 0; j < y; j++) map[a][j] = 1;
	}
}

int findArea(){
	int area = 0;
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++) if(map[i][j] == 1) area++;
	}
	return area;
}

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		reset();
		int rect; cin >> rect;
		for(int j = 0; j < rect; j++){
			int a, x, y; cin >> a >> x >> y;
			fill(a, x, y);
		}
		cout << findArea() << endl;
	}
	return 0;
}