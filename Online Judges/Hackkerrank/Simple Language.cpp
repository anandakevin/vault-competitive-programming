#include <iostream>
#define clear cin.clear(); cin.sync();
using namespace std;

int main() {
	int rpt;
	cin >> rpt; clear;
	long long int x = 0;
	for(int i = 0; i < rpt; i++){
		string cmd;
		long long int num;
		cin >> cmd; clear;
		if(cmd == "add"){
			cin >> num; clear;
			if(x + num > x) x += num;
		}
		else if(cmd == "set"){
			cin >> num; clear;
			if(num > x) x = num;
		}
	}
	cout << x;
	return 0;
}