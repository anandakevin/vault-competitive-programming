#include <stdio.h>

int main() {
	int rep; scanf("%d", &rep);
	for(int i = 1; i <= rep; i++) {
		int num; scanf("%d", &num);
		int jojo = 0, lili = 0;
		for(int j = 0; j < num; j++) {
			int x; scanf("%d", &x);
			if((x % 2) == (j % 2)) {
				if(j % 2 == 0) jojo++;
				else if(j % 2 == 1) lili++;
			}
		}
		printf("Case #%d: ", i);
		int jw = 0, lw = 0;
		if(jojo % 2 == 0) jw = 1;
		if(lili % 2 == 1) lw = 1;
		if(jw == lw) printf(":|\n");
		else if(jw == 1) printf(":)\n");
		else if(lw == 1) printf(":(\n");
	}
	return 0;
}