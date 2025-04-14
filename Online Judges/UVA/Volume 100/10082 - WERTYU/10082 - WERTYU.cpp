#include <stdio.h>
#include <string.h>

int main() {
    char kalimat[1000];
    char key[50] = {'`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G','H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/'};
    
    while(scanf("%[^\n]", kalimat) != EOF){
        getchar();
        for(int i=0; i<strlen(kalimat); i++){
            for(int j=0; j<strlen(key); j++){
                if(kalimat[i] == key[j]){
                    kalimat[i] = key[j-1];
                    break;
                }
            }
        }
        printf("%s\n", kalimat);
    }
    
    return 0;
}