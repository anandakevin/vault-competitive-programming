#include <iostream>
using namespace std;

int main(){
  int rep; cin >> rep;
  int maxFirst = 0, maxSec = 0;
  cin >> maxFirst; maxSec = maxFirst;
  for(int i = 0; i < rep - 1; i++){
    int inp; cin >> inp;
    if(inp > maxFirst){
      maxSec = maxFirst;
      maxFirst = inp;
    }
  }
  cout << maxSec % maxFirst << endl;
  return 0;
}
