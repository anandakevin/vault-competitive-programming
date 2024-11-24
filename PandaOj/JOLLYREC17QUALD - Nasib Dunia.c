#include <stdio.h>

int main(){
    int i, j, T;
    long long int a[1000], b[1000], hasil, temp[1000], pengali;
    scanf("%d", T);
    int N[T];
    for(i=0;i<T;i++){
        int hasil[i]=1;
        scanf("%d", &N);
        for(j=0;j<N;j++){
            scanf("%lld", &a[j]);
        }
        for(j=0;j<N;j++){
            scanf("%lld", &b[j]);
        }
        pengali=1;
        for(j=1;j<=N;j++){
            pengali=pengali*j;
        }
        for(j=0;j<pengali;j++){
            if(a[j]>b[j]){
               a[j]/b[j]=temp[j];
               }
             else{
                b[j]/a[j]=temp[j];
             }
             hasil[i]=temp[j]*hasil[i];
        }
    }
    for(i=0;i<T;i++){
        printf("Kasus #%d: %lld", i+1, hasil[i]);
    }
}
