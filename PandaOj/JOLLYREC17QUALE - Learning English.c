#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int i, j, T;
    scanf("%d", &T); fflush(stdin);
    int cek[T];
    char input[100];
    for(i=0;i<T;i++){
        cek[i]=0;
        scanf("%[^\n]", input); fflush(stdin);
        for(j=0;j<strlen(input);j++){
            if(input[j]=='A'||input[j]=='a'){j++;
                if(input[j]=='P'||input[j]=='p'){j++;
                    if(input[j]=='P'||input[j]=='p'){j++;
                        if(input[j]=='L'||input[j]=='l'){j++;
                            if(input[j]=='E'||input[j]=='e'){j++;
                                if(isspace(input[j])){
                                    cek[i]++;
                                }
                                else if(isdigit(input[j])||isalpha(input[j])){
                                    continue;
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<T;i++){
        if(cek[i]>=1){
            printf("Kasus #%d: Inggris\n", i+1);
        }
        else{
            printf("Kasus #%d: Indonesia\n", i+1);
        }
    }
    return 0;
}

