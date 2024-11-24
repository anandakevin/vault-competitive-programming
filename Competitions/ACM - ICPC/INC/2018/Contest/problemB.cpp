#include <iostream>
using namespace std;

int main(){
	int ttlNum, rep; cin >> ttlNum >> rep;
	int num[ttlNum];
	for(int i = 0; i < ttlNum; i++) num[i] = i+1;
	for(int i = 0; i < rep; i++){
		int from, to;
		cin >> from >> to;
		int movement;
		for(int i = 0; i < ttlNum; i++) cout << num[i] << " ";
		if(num[to] > num[from]){
			movement = num[to] - num[from];
			for(int i = 0; i < ttlNum; i++) {
				if(num[i] > num[from] || num[i] < num[to]) num[i]--;
			}
			num[from] = num[to];
			num[to]--;
		}
		else if(num[to] < num[from]){
			movement = num[to] - num[from] + 1;
			for(int i = 0; i < ttlNum; i++) {
				cout << 
				if(num[i] < num[from] || num[i] > num[to]) num[i]++;
			}
			num[from] = num[to] + 1;
		}
		cout << endl;
		cout << movement << endl;
	}
	return 0;
}