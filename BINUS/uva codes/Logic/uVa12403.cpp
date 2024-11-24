#include <stdio.h>
#include <string.h>

int main() {
	int kasus, donate=0, report, pemasukan;
	char pilihan[10];
	
	scanf("%d", &kasus);
	getchar();
	
	for(int i=0; i<kasus; i++){
		scanf("%s", pilihan);
		getchar();
		
		if(strcmp(pilihan, "donate")==0){
			scanf("%d", &pemasukan);
			getchar();
			donate += pemasukan;
		}else if(strcmp(pilihan, "report")==0){
			printf("%d\n", donate);
		}
		
	}
	
	
	return 0;
}