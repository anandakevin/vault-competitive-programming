
#include<stdio.h>
#include<string.h>


int max(int a, int b) { return (a > b)? a : b; }
int memo[1005][1005];

int knapSack(int W, int wt[], int val[], int n)
{	
	if (n == 0 || W == 0) return 0;

	if (wt[n-1] > W) return memo[W][n-2] = knapSack(W, wt, val, n-1);

	else if(memo[W][n-1] != -1 && memo[W-wt[n-1]][n-1] != -1) 
		return max( val[n-1] + memo[W-wt[n-1]][n-1], memo[W][n-1]);

	else if(memo[W][n-1] != -1){
		memo[W-wt[n-1]][n-1] = knapSack(W-wt[n-1], wt, val, n-1);
		return max(val[n-1] + memo[W-wt[n-1]][n-1], memo[W][n-1]);
	}

	else if(memo[W-wt[n-1]][n-1] != -1){
		memo[W][n-1] = knapSack(W, wt, val, n-1);
		return max( val[n-1] + memo[W-wt[n-1]][n-1], memo[W][n-1]);
	}

	else {
		memo[W][n-1] = knapSack(W, wt, val, n-1);
		memo[W-wt[n-1]][n-1] = knapSack(W-wt[n-1], wt, val, n-1);
		return max( val[n-1] + memo[W-wt[n-1]][n-1], memo[W][n-1]);
	}
}

// Driver program to test above function
int main()
{
		int tc, banyak, w, jumlah;
	int value[1005];
	int weight[1005];
	memset(memo, -1, sizeof(memo));
	scanf("%d", &tc);
	getchar();
	
	for(int i=0; i<tc; i++){
		scanf("%d",&banyak);
		getchar();
		
		for(int j=0; j<banyak; j++){
			scanf("%d %d", &value[j], &weight[j]);
			getchar();
		}
		
		scanf("%d",&jumlah);
		getchar();
		
		int total=0;
		
		for(int j=0; j<jumlah; j++){
			scanf("%d",&w);
			getchar();
			total += knapSack(w, weight, value, banyak);
		}
		printf("%d\n", total);
	memset(memo, -1, sizeof(memo));
	memset(value, '\0', sizeof(value));
	memset(weight, '\0', sizeof(weight));
	}
	
	
	getchar();
	return 0;
}
