#include <iostream>
using namespace std;

int main(){
	int rep; cin >> rep;
	for(int i = 0; i < rep; i++){
		long long num1, num2; cin >> num1 >> num2;
		long long ans = num1 * num2;
		cout << ans << endl;
	}
}