#include <iostream>
using namespace std;

int main(){
	int a1[26], a2[26];
	for(int i = 0; i < 26; i++){
		a1[i] = a2[i] = 0;
	}
	string word1, word2; cin >> word1 >> word2;
	for(int i = 0; i < word1.length(); i++){
		a1[(int)(word1[i] - 'a')]++;
	}
	for(int i = 0; i < word2.length(); i++){
		a2[(int)(word2[i] - 'a')]++;
	}
	int check = 1;
	for(int i = 0; i < 26; i++){
		if(a2[i] != 0 && a2[i] > a1[i]) {
			check = 0; 
			break;
		}
	}
	if(check == 1) cout << "YES";
	else cout << "NO";
	return 0;
}