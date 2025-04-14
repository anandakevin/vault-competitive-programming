#include <stdio.h>

int main() {
	int rep; scanf("%d", &rep); getchar();
	for(int i = 1; i <= rep; i++) {
		int len; scanf("%d", &len); getchar();
		char inp[100001]; scanf("%[^\n]", inp);
		int countzero = 0, countone = 0, tempzero = 0, tempone = 0;
		for(int j = 0; j < len; j++) {
			if(inp[j] == '0') {
			    tempone = 0;
			    tempzero++;
			}
			else if(inp[j] == '1') {
			    tempzero = 0;
			    tempone++;
			}
			if(countone < tempone) countone = tempone;
		    if(countzero < tempzero) countzero = tempzero;
		}
		if(countone > countzero) printf("Case #%d: %d %d\n", i, 1, countone);
		else printf("Case #%d: %d %d\n", i, 0, countzero);
	}
	return 0;
}