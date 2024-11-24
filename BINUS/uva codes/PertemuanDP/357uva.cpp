#include <stdio.h>

int memo[1000];

int f(int x){
	if(x < 0) return 0;
	if(x == 0) return 1;
	if(memo[x] != -1) return memo[x];
	return memo[x] = f(x-7) || f(x-12);
}

int main(){
	memset(memo, -1, sizeof(memo));
	f(100);
	return 0;
}
