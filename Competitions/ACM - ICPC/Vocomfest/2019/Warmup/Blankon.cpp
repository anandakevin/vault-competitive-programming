#include <iostream>
#include <string>
#include <cmath>
using namespace std;

char decode(string s){
    int temp = 0;
    for (int i = 0, j = s.length() - 2; i < s.length(); i++, j--) {
        if(s[j] == '-'){
            temp += pow(2,i);
        }
    }
    return (char)(temp - 1 + 65);
}


int main() {
	int n,tc = 1;
	string s, temp = "";
	cin >> n;
	while(n--){
	    cin >> s;
	    cout << "Case #" << tc << ": ";
	    tc++;
	    for (int i = 0; i < s.length(); i++) {
	        temp += s[i];
	        if(s[i] == '/'){
	            char c = decode(temp);
	            cout << c;
	            temp = "";
	        }else if(s[i] == '#') {
	            cout << " ";
	            i++;
	        }
	    }
	    cout << endl;
	    temp = "";
	}
	return 0;
}