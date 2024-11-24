#include <stdio.h>

int main(){
	int N, K;
	int arr[1010];
	int sum = 0;
	
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	
	if (sum % 2) printf("John");
	else printf("Preston");

	return 0;
}
