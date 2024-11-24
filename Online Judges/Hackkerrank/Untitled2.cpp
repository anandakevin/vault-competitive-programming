#include <iostream>
#define clear cin.clear(); cin.sync();
using namespace std;

int main() {
	int len;
	cin >> len; clear;
	for(int i = 0; i < len; i++){
		for(int j = len - i; j > 1; j--) cout << ' ';
		for(int j = 0; j < i + 1; j++) cout << '#';
		if(i != len - 1) cout << endl;
	}
	return 0;
}
