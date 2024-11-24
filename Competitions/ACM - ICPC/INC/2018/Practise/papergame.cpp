#include <iostream>
using namespace std;

int main(){
	int rep; cin >> rep;
	for(int i = 0; i < rep; i++){
		int x, y; cin >> x >> y;
		if((x*y - 1) % 2 == 0) cout << "Hussain" << endl;
		else cout << "Hasan" << endl;
	}
}