#include <iostream>
#include <string.h>
using namespace std;

int countalphabet[26];

int main() {
    int len; cin >> len;
    memset(countalphabet, 0, sizeof(countalphabet)); 
    string a, b; cin >> a >> b;
    for(int i = 0; i < len; i++) {
        if(a[i] == b[i]) countalphabet[a[i] - 'a']++;
        else{
            countalphabet[a[i] - 'a']++;
            countalphabet[b[i] - 'a']++;
        }
    }
    int score = 0;
    for(int i = 0; i < 26; i++) score = max(countalphabet[i], score);
    cout << score << endl;
    return 0;
}