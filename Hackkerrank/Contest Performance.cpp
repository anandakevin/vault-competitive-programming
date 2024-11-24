#include <iostream>
#define clear cin.clear(); cin.sync();
using namespace std;


int main(){
    int currNum, currLoop = 1;
    while(cin >> currNum){
        if(currNum - currLoop < 0){
            cout << "Problem " << currNum << " is solved on day " << currLoop << ", when two days have passed and it's worth " <<  << " points. " << endl;
        } 
        else cout << "Problem " << currNum << " is solved on day " << currLoop << ", while it's still worth 100 points. " << endl;
    }
    return 0;
}