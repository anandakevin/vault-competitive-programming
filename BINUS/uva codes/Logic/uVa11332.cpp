#include <stdio.h>
#include <string.h>

int main() {
	int angka, total=0, temp, pembagi = 1000000000;
	do{
		scanf("%d", &angka);
		getchar();
		if(0 != angka){
			while(angka > 9){
				pembagi = 1000000000;
				total = 0;
				while(pembagi > 0){
					temp = angka / pembagi;
					angka -= temp*pembagi;
					total += temp;
					pembagi /= 10;
				}
				angka = total;
			}
			printf("%d\n", angka);
		}
	}while(0 != angka);
	
	
	return 0;
}