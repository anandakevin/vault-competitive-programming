#include <iostream>
using namespace std;

int matching[1000001];

void reset(){
  for(int i = 0; i < 1000001; i++) matching[i] = 0;
}


void show(int len){
    cout << endl;
    for(int i = 0; i < len; i++) cout << matching[i];
    cout << endl;
}

void count(string inp, char match){
  for(int i = 0; i < inp.length(); i++) {
    if(inp[i] == match) matching[i] = 1;
  }
}

int main(){
  int rep; cin >> rep;
  while(rep--){
    int len; cin >> len;
    string inp;
    char searched; cin >> inp >> searched;
    reset();
    count(inp, searched);
    long long ttlSubstring = 0;
    for(int i = 0; i < inp.length(); i++){
      for(int j = i; j < inp.length(); j++){
         if(matching[j] == 1) {
           long long temp = inp.length() - j;
           ttlSubstring += temp * (j - i + 1);
           i = j;
           break;
         }
      }
    }
    cout << ttlSubstring << endl;
  }
  return 0;
}
