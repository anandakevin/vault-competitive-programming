#include <stdio.h>

int main(){
    int i, j, T;
    scanf("%d", &T); fflush(stdin);
    int N[T];
    for(i=0;i<T;i++){
        scanf("%d", &N[i]);
    }
    for(i=0;i<T;i++){
        printf("Kasus #%d: \n", i+1);
        for(j=0;j<N[i];j++){
            printf("---------\n");
            printf("|%% \\0\/ %%|\n");
            printf("|\"  |  \"|\n");
            printf("|%% \/ \\ %%|\n");
            printf("---------\n");
        }
    }
}
