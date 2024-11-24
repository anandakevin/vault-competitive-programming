#include<stdio.h>

int main(){
	int kasus, banyak, min=100, max=0, angka;
	scanf("%d", &kasus);
	gethcar();
	for(int i=0; i<kasus; i++){
		scanf("%d", &banyak);
		getchar();
		min=100; max=0;
		for(int j=0; j<banyak; j++){
			scanf("%d", &angka);
			getchar();
			if(min > angka){
				min = angka;
			}
			if(max < angka){
				max = angka;
			}
		}
		printf("%d", (max - min)*2);
	}
	
	return 0;
}