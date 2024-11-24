#include <stdio.h>
#include <string.h>

void fungsi0(int i, int j, int size){
	if((i==0 || i==((2*size)+2)) && (j==0 || j==size+1) ){
		printf(" ");
	}else if(i==size+1){
		printf(" ");
	}else if((i == 0 ||  i==2*size+2) ){
		printf("-");
	}else if(j == 0 || j==size+1){
		printf("|");
	}else 
		printf(" ");
}

void fungsi1(int i, int j, int size){
	if(j==size+1 && (i!=0 && i!=size*2+2 && i!=size+1)){
		printf("|");
	}else{
		printf(" ");
	}
}

void fungsi2(int i, int j, int size){
	if((i==0 || i== size+1 || i==size*2+2) && j>0 && j < size+1){
		printf("-");
	}else if(j == 0 && i>size+1 && i<size*2+2){
		printf("|");
	}else if(j==size+1 && i>0 && i<size+1){
		printf("|");
	}else{
		printf(" ");
	}
	
}

void fungsi3(int i, int j, int size){
	if((i==0 || i== size+1 || i==size*2+2) && j>0 && j < size+1){
		printf("-");
	}else if(j==size+1 && (i>0 && i<size+1) || j==size+1 &&(i>size+1 && i<size*2+2)){
		printf("|");
	}else{
		printf(" ");
	}
}

void fungsi4(int i, int j, int size){
	if(i== size+1 && j>0 && j < size+1){
		printf("-");
	}else if(j==size+1 && (i>0 && i<size+1) || j==size+1 &&(i>size+1 && i<size*2+2)){
		printf("|");
	}else if(j == 0 && i>0 && i<size+1){
		printf("|");
	}else{
		printf(" ");
	}
}

void fungsi5(int i, int j, int size){
	if((i==0 || i== size+1 || i==size*2+2) && j>0 && j < size+1){
		printf("-");
	}else if(j == size+1 && i>size+1 && i<size*2+2){
		printf("|");
	}else if(j==0 && i>0 && i<size+1){
		printf("|");
	}else{
		printf(" ");
	}
}


void fungsi6(int i, int j, int size){
	if((i==0 || i== size+1 || i==size*2+2) && j>0 && j < size+1){
		printf("-");
	}else if(j==0 && (i>0 && i<size+1) ||j==0 && (i>size+1 && i<size*2+2)){
		printf("|");
	}else if(j == size+1 && i>size+1 && i<size*2+2){
		printf("|");
	}else{
		printf(" ");
	}
}

void fungsi7(int i, int j, int size){
	if(j==size+1 && (i!=0 && i!=size*2+2 && i!=size+1)){
		printf("|");
	}else if(i==0 && j>0 && j<size+1){
		printf("-");
	}else{
		printf(" ");
	}
}

void fungsi8(int i, int j, int size){
	if((i==0 || i==((2*size)+2)) && (j==0 || j==size+1) ){
		printf(" ");
	}else if(i==size+1 && j>0 && j<size+1){
		printf("-");
	}else if((i == 0 ||  i==2*size+2) ){
		printf("-");
	}else if(j == 0  && i!=size+1|| j==size+1 && i!=size+1){
		printf("|");
	}else 
		printf(" ");
}

void fungsi9(int i, int j, int size){
	if((i== size+1 || i==0 || i==size*2+2) && (j>0 && j < size+1)){
		printf("-");
	}else if(j==size+1 && (i>0 && i<size+1) ||j==size+1 && (i>size+1 && i<size*2+2)){
		printf("|");
	}else if(j == 0 && i>0 && i<size+1){
		printf("|");
	}else{
		printf(" ");
	}
}

void penentu(int i, int j, int size, char angka){
	if(angka == '0'){
		fungsi0(i, j, size);
	}else if(angka == '1'){
		fungsi1(i, j, size);
	}else if(angka == '2'){
		fungsi2(i, j, size);
	}else if(angka == '3'){
		fungsi3(i, j, size);
	}else if(angka == '4'){
		fungsi4(i, j, size);
	}else if(angka == '5'){
		fungsi5(i, j, size);
	}else if(angka == '6'){
		fungsi6(i, j, size);
	}else if(angka == '7'){
		fungsi7(i, j, size);
	}else if(angka == '8'){
		fungsi8(i, j, size);
	}else if(angka == '9'){
		fungsi9(i, j, size);
	}
}

int main(){
	int size;
	char angka[1000000];
	do{
		scanf("%d %s", &size, angka);
		getchar();
		
		if(size != 0){
			int row = 2*size+3;
			int column = (size+2)*strlen(angka)+(strlen(angka)-1);
			int index = 0, x=0;
			for(int i=0; i<row; i++){
				for(int j=0; j<column; j++){
					if(index != 0){
						if(j == (size+2)*(index+1)+index){
							printf(" ");
							index++;
							x=0;
						}else{
							penentu(i, x, size, angka[index]);
							x++;
						}
					}else{
						if(j == size+2){
							printf(" ");
							index++;
							x=0;
						}else{
							penentu(i, x, size, angka[index]);
							x++;
						}
					}
				}
				printf("\n");
				x = 0;
				index = 0;
			}
			printf("\n");
		}
		
	}while(size != 0);
	
	
	getchar();
	return 0;	
}