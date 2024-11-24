#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
long long int n,m,npc[100001][5], spec[100001], memo[100001][5];

long long int solve(int day, int index){

	if(day == n + 1) return 0;
	if(memo[day][index] != -1) return memo[day][index];
	long long int res = -1,temp;

	for(int i = 1; i <= 4; ++i) {
		long long int add = (index == i) ? (npc[day][i] * 2) : npc[day][i];
		
		if(spec[day] != -1) temp = i;
		else temp = 0;

		long long int rtemp = solve(day + 1, temp) + add;
		if(rtemp > res) res = rtemp;
	}

	return memo[day][index] = res;
}

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

void reset(){
	memset(memo,-1, sizeof(memo));
	for(int i = 1; i <= n; ++i) {
		if(spec[i] != -1) spec[i] = -1;
	}
}

int main(){

	int tc,cs = 1;
	tc = readInt();	
	while(tc--){
		n = readInt();
		m = readInt();
		reset();
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= 4; ++j) {
				npc[i][j] = readInt();
			}
		}

		for(int i = 0; i < m; ++i) {
			int temp = readInt();
			spec[temp] = temp;
		}
		long long int res = solve(1,0);
		printf("%s%d%s%lld\n","Case #",cs, ": ",res);
		cs++;		
	}
	return 0;
}
