// longest strictly increasing subsequence

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int memo[1000];
int arr[] = {3, 5, 1, 2, 4, 5, 0, -2};

int f(int idx){
	if(memo[idx] != -1) return memo[idx];
	int ans = 1;
	for(int i=0; i<idx; i++){
		if(arr[i] < arr[idx]){
			ans = max(ans, 1 +f(i));
		}
	}
	return memo[idx] = ans;
}

int main(){
	memset(memo, -1, sizeof(memo));
	int ans = 0;
	for(int i=0; i<8; i++){
		ans = max(ans, 1+f(i));
	}
	printf("%d\n", ans);
}

