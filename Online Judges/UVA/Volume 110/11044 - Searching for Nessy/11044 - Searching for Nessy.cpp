#include <stdio.h>

int main() {
    int kasus, row, column;
    
    scanf("%d", &kasus);
    getchar();
    
    for(int i=0; i<kasus; i++){
        scanf("%d %d", &row, &column);
        getchar();
        
        row /= 3;
        column /=3;
        
        printf("%d\n", row*column);
    }
    
    
    return 0;
}