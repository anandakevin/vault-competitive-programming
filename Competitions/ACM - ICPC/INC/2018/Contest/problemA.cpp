#include <iostream>
using namespace std;

int main(){
	int rep; cin >> rep;
	int numOfStudent[rep];
	for(int i = 0; i < rep; i++){
		cin >> numOfStudent[i];
	}
	int num; 
	string dir;
	int ttlStudent = 0;
	cin >> num >> dir;
	if(dir == "right"){
		for(int i = num - 1; i < rep; i++) ttlStudent += numOfStudent[i];
	}
	else 
		for(int i = num - 1; i >= 0; i--) ttlStudent += numOfStudent[i];
	cout << ttlStudent << " ";
	cin >> num >> dir;
	int ttlEmptyClass = 0;
	if(dir == "right"){
		for(int i = num - 1; i < rep; i++) {
			if(numOfStudent[i] == 0) ttlEmptyClass++;
		}
	}
	else 
		for(int i = num - 1; i >= 0; i--) {
			if(numOfStudent[i] == 0) ttlEmptyClass++;
		}
	cout << ttlEmptyClass;
	return 0;
}