#include <stdio.h>
#include <string.h>

#define phi 22/7

int main(){
    int rep;
    scanf("%d", &rep);
    for(int i = 0; i < rep; i++){
        char sentence[121];
        scanf("%[^\n]", sentence);
        float time = 0;
        time += 1*strlen(sentence);
        
    }
    printf("%f", phi);
    return 0;
}