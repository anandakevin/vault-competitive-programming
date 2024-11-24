#include <iostream>
using namespace std;

string nonStringGenerator(string curr, int idx){
	if(curr[idx] != 'z') curr[idx] += 1;
	else if(idx == 0) {	
		curr[0] = 'a';
		curr += 'a';
	}
	else {
		curr[idx] = 'a';
		return nonStringGenerator(curr, idx - 1);
	}
	return curr;
}

bool checkSubStringCond1(string curr, string word){
	if(curr.length() > word.length()) return false;
	else 

}

bool checkSubStringCond2(string curr, string word){
	for(int i = 0; i < curr.length(); i++){
		if(curr[i] < word[i]) {
			int checkTrue = 1;
			for(int j = 0; j < i; j++) {
				if(word[j] != curr[j]) checkTrue = 0;
			}
			if(checkTrue == 1) return true;
		}
	}
	return false;
}

int main(){
	string word, theString = "a"; cin >> word;
	bool varCheck = false;
	do{
		if(varCheck == false) varCheck = checkSubStringCond2(theString, word);
		if(varCheck == false) theString = nonStringGenerator(theString, 0);
		if(varCheck == true) break;
	} while(varCheck == false);
	cout << theString;
	return 0;
}