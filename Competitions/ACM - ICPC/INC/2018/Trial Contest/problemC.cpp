#include <iostream>
using namespace std;

int main() {
    int n,q,arr[100001], dp[100001],t,l,r;
    string str;
    cin >> n >> q;
    cin >> str;
    for(int i = 0; i < n; i++) arr[i] = str[i]-48;
    while(q--){
        cin >> t >> l >> r;
        if(t == 1){
            for(int i = l-1; i <= r-1; i++){
                if(arr[i] == 0) arr[i] = 1;
                else arr[i] = 0;
            }
        }
        else{
            int temp = 1, ln = 1;
            for(int i = l-1; i <= r-1; i++){
                if(i != r-1 && arr[i] == arr[i+1])temp++;
                else{
                    ln = max(temp, ln);
                    temp = 1;
                }
            }
            cout << ln << endl;
       }
    }
 	return 0;
}