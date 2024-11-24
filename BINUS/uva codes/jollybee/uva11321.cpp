#include <stdio.h>

struct data{
	int angka;
	int modulo;
}deretanAngka[10005];

int index = 0;

void merge(int low, int mid, int high){
	struct data temp[10005];
	int index = low;
	int index1 = low;
	int index2 = mid+1;
	while(index1 <= mid && index2 <= high){
		if(deretanAngka[index1].modulo == deretanAngka[index2].modulo ){
			if(deretanAngka[index1].angka % 2 != 0 && deretanAngka[index2].angka % 2 != 0){
				if(deretanAngka[index1].angka > deretanAngka[index2].angka){
					temp[index] = deretanAngka[index1];
					index1++;
				}else{
					temp[index] = deretanAngka[index2];
					index2++;
				}
			}else if(deretanAngka[index1].angka % 2 == 0 && deretanAngka[index2].angka % 2 == 0){
				if(deretanAngka[index1].angka > deretanAngka[index2].angka){
					temp[index] = deretanAngka[index2];
					index2++;
				}else{
					temp[index] = deretanAngka[index1];
					index1++;
				}
			}else{
				if(deretanAngka[index1].angka % 2 != 0){
					temp[index] = deretanAngka[index1];
					index1++;
				}else{
					temp[index] = deretanAngka[index2];
					index2++;
				}
			}
		}
		else if(deretanAngka[index1].modulo < deretanAngka[index2].modulo){
			
			temp[index] = deretanAngka[index1];
			index1++;
		}else if(deretanAngka[index2].modulo < deretanAngka[index1].modulo){
			temp[index] = deretanAngka[index2];
			index2++;
		}
		index++;
	}

	if(index1 <= mid){
		for(int i = index1; i<=mid; i++){
			temp[index] = deretanAngka[i];
			index++;
		}
	}else{
		for(int i = index2; i<=high; i++){
			temp[index] = deretanAngka[i];
			index++;
		}
	}

	 for(int i=low; i<=high; i++){
	 	//printf("%d \n", temp[i].angka);
	 	deretanAngka[i] = temp[i];
	 }
}

void split(int low, int high){
	if(low < high){
		int mid = (low+high)/2;
		split(low, mid);
		split(mid+1, high);
		merge(low, mid, high);
	}
}


int main(){
	int banyak, modulo, angka, temp;
	
	long long int median;
	do{
		scanf("%d %d", &banyak, &modulo);
		getchar();
		if(banyak != 0 && modulo!=0){
			for(int i=0; i<banyak; i++){
				scanf("%d", &angka);
				getchar();
				deretanAngka[index].angka = angka;
				deretanAngka[index].modulo = (angka%modulo);
				index++;
			}
			split(0, index-1);
			printf("%d %d\n", banyak, modulo);
			for(int i=0; i<banyak; i++){
				printf("%d\n", deretanAngka[i].angka);
			}
		}
		index = 0;
		
	}while(banyak != 0 && modulo != 0);
	printf("0 0\n");

	getchar();
	return 0;
}