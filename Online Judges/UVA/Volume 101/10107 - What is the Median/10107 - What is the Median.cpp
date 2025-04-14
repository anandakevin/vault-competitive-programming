#include <stdio.h>

int deretanAngka[10010];

void merge(int low, int mid, int high){
    int temp[10010];
    int index = low;
    int index1 = low;
    int index2 = mid+1;
    while(index1 <= mid && index2 <= high){
        if(deretanAngka[index1] <= deretanAngka[index2]){
            temp[index] = deretanAngka[index1];
            index1++;
        }else if(deretanAngka[index2] < deretanAngka[index1]){
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
    int angka;
    int index = 0;
    long long int median;
    while(scanf("%d", &angka) != EOF){
        getchar();
        deretanAngka[index] = angka;
        index++;
        split(0, index-1);
        int mid = (index-1)/2;
        if(index % 2 == 0){
            //printf("%d %d\n", deretanAngka[mid] , deretanAngka[mid+1]);
            median = ((long long int )deretanAngka[mid]+deretanAngka[mid+1])/2;
        }else{
        //  printf("%d\n", deretanAngka[mid]);
            median = deretanAngka[mid];
        }

        printf("%ld\n", median);
        
        
    }

    for(int i=0 ;i<index;i++){
        //printf("%d\n", deretanAngka[i]);
    }

    getchar();
    return 0;
}