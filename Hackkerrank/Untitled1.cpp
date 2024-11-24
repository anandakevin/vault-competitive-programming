#include <iostream>
#define clear cin.clear(); cin.sync();
using namespace std;

int main() {
	// your code goes here
	int rpt;
	cin >> rpt; clear;
	for(int i = 0; i < rpt; i++){
		int row, col;
		cin >> row; clear;
		cin >> col; clear;
		int curr = 0;
		for(int j = 0; j < row; j++){
			if(row % 2 == 0){
				if(j % 2 == 1) curr = 1;
				else curr = 0;
			}
			for(int k = 0; k < col; k++){
				if(curr == 0){
					curr = 1;
					cout << '*';
				}
				else{
					curr = 0;
					cout << '.';
				}
			}
			if(j != row) cout << endl;
		}
		if(i != rpt) cout << endl;
	}
	return 0;
}
