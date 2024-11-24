#include <iostream>
using namespace std;

void reset(int alphabet[]){
	for(int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}
}

string getRev(string word){
	string newString = "";
	for(int i = word.length() - 1; i >= 0; i--) newString += word[i];
	return newString;
}

int main(){
	int rep; cin >> rep;
	int alphabet[26];
	for(int i = 0; i < rep; i++){
		string word;
		cin >> word;
		reset(alphabet);
		for(int i = 0; i < word.length(); i++) alphabet[(int)(word[i] - 'a')]++;
		int odd, ct = 0;
		for(int i = 0; i < 26; i++){
			if(alphabet[i] % 2 == 1) {
				odd = i; ct++;
			}
		}
		string temp = "";
		if(ct > 1) temp = "impossible";
		else{
			for(int i = 0; i < 26; i++){
				for(int j = 0; j < (alphabet[i] / 2); j++)	temp += (char)(i + 'a');
			}
			if(ct > 0) temp += (char)(odd + 'a') + getRev(temp);
			else temp += getRev(temp);
		}
		cout << temp << endl;
	}
	return 0;
}