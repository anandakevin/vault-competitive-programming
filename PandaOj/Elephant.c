#include <stdio.h>

int main (){
    int x, jumlah_langkah;
    scanf("%d", &x);
    if(x%5==0){
        jumlah_langkah=x/5;
    }
    else{
        jumlah_langkah=(x/5)+1;
    }
    printf("%d", jumlah_langkah);
}
