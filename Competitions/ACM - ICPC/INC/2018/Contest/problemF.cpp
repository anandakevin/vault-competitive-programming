#include <iostream>
using namespace std;

int main(){
	int rep1, rep2; cin >> rep1 >> rep2;
	int a1[rep1][26], a2[26];
	for(int i = 0; i < rep1; i++){
		for(int j = 0; j < 26; j++) a1[i][j] = 0;
	}
	string temp;
	getline(cin, temp);
	for(int i = 0; i < rep1; i++){
		string word; getline(cin, word);
		for(int j = 0; j < word.length(); j++){
			if(j == 0 || word[j - 1] == 32) a1[i][(int)(word[j] - 'A')]++;
		}
	}
	for(int i = 0; i < rep2; i++){
		string word; cin >> word;
		for(int j = 0; j < 26; j++) a2[j] = 0;

		for(int j = 0; j < word.length(); j++) a2[(int)(word[j] - 'A')]++;
		int check = 1, used[rep1];

		for(int j = 0; j < rep1; j++) used[j] = 0;

		for(int j = 0; j < 26; j++){
			if(a2[j] != 0){
				for(int k = 0; k < rep1; k++){
					if(used[k] == 1) continue;
					if(a2[j] == 0) break;
					if(a1[k][j] > 0){
						used[k] = 1;
						a2[j]--;
					}
				}	
			}
		}

		for(int j = 0; j < 26; j++){
			if(a2[j] != 0) {
				check = 0; break;
			}
		}

		if(check == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}