#include <stdio.h>

int main() {
	int rep; scanf("%d", &rep);
	for(int i = 1; i <= rep; i++) {
	    printf("Case #%d:\n", i);
		int n, x, m, sum = 0;
		scanf("%d %d %d", &n, &x, &m);
		for(int j = 1; j <= n; j++) {
			sum += j;
			if(sum > x) {
				printf("%d\n", sum);
				if((sum - x) % m == 0) sum = x;
				else sum = sum - m * ((sum - x)/m + 1);
			}
		}
	}
	return 0;
}