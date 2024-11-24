#include <stdio.h>
#include <string.h>

int main(){
	char inputan[15];
	int jumlah=0;
	
	do{
		scanf("%[^\n]", inputan);
		getchar();
		
		if(strcmp(inputan, "#") != 0){
			jumlah++;
			if(strcmp(inputan, "HELLO")==0){
				printf("Case %d: ENGLISH\n",jumlah);
			}else if(strcmp(inputan, "HOLA")==0){
				printf("Case %d: SPANISH\n",jumlah);
			}else if(strcmp(inputan, "HALLO")==0){
				printf("Case %d: GERMAN\n",jumlah);
			}else if(strcmp(inputan, "BONJOUR")==0){
				printf("Case %d: FRENCH\n",jumlah);
			}else if(strcmp(inputan, "CIAO")==0){
				printf("Case %d: ITALIAN\n",jumlah);
			}else if(strcmp(inputan, "ZDRAVSTVUJTE")==0){
				printf("Case %d: RUSSIAN\n",jumlah);
			}else{
				printf("Case %d: UNKNOWN\n",jumlah);
			}
		}
		
	}while(strcmp(inputan, "#") != 0);
	
	
	
}