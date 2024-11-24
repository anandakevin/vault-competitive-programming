#include <iostream>
#include <algorithm>
using namespace std;

int countMin(long long num[], int ttlNum, int ttlGroup){
	long long min = 0;
	for(int i = 0; i < ttlGroup; i++) min += num[i];
	return min;
}

int countMax(long long num[], int ttlNum, int ttlGroup){
	long long max = 0;
	int ttlNumOfEachGroup = ttlNum / ttlGroup;
	int res = ttlNum % ttlGroup;
	int idx = 0, i = 0;
	for(; i < res; i++){
		max += num[idx];
		idx += (ttlNumOfEachGroup + 1);
	}
	for(; i < ttlGroup; i++){
		max += num[idx];
		idx += ttlNumOfEachGroup;
	}
	return max;
}

int main(){
	int rep, groups; cin >> rep >> groups;
	long long num[rep];
	for(int i = 0; i < rep; i++) cin >> num[i];
	sort(num, num + rep);
	cout << countMin(num, rep, groups) << " " << countMax(num, rep, groups);
	return 0;
}