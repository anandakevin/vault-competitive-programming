#include <stdio.h>

int main(){
    int i, T, Wj[100], Wp[100], Mj[100], Mp[100], Jj[100], Jp[100];
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d %d %d %d %d %d", &Wj[i], &Wp[i], &Mj[i], &Mp[i], &Jj[i], &Jp[i]);
    }
    for(i=0;i<T;i++){
        if(Wp[i]>Wj[i]){
            printf("Kasus #%d: TIME LIMIT EXCEEDED / TIMELIMIT\n", i+1);
        }
        else if(Mp[i]>Mj[i]){
            printf("Kasus #%d: MEMORY LIMIT EXCEEDED\n", i+1);
        }
        else if(Jp[i]!=Jj[i]){
            printf("Kasus #%d: WRONG-ANSWER\n", i+1);
        }
        else{
            printf("Kasus #%d: ACCEPTED / CORRECT\n", i+1);
        }
    }
}
