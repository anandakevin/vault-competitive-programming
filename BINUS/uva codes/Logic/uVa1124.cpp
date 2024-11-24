#include <stdio.h>

int main() {
	char input[100];
	
	while(scanf("%[^\n]", input)!=EOF){
		getchar();
		printf("%s\n", input);
	}
	return 0;
}