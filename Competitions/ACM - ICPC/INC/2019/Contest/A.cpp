#include <stdio.h>

int main(){
	int n;
	int sum = 0;
	scanf("%d", &n);
	int A[n+1], B[n+1];
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &B[i]);
	}
	
	for (int i = 0; i < n; i++){
		if (A[i] > B[i]) sum += 3;
		else if (A[i] == B[i]) sum += 1;
		else sum += 0;
	}
	
	printf("%d", sum);
	
	return 0;
}
