#include <stdio.h>

int main(){
    float h, d, u, f, now, pengurangan;
    int day = 0;
    
    do{
        scanf("%f %f %f %f", &h, &u, &d, &f);
        getchar();
        day = 0;
        pengurangan = u*f/100;
        now = h;
        while(now > 0){
            //printf("%f %f %f %f %f\n",h, now, u, pengurangan, d);
            ++day;
            now = now - u;
            if(now < 0){
                printf("success on day %d\n", day);
                break;
            }
            
            now += d;
            
            if(u - pengurangan > 0){
                u -= pengurangan;
            }else{
                u = 0;
            }
            
            if(h < now){
                printf("failure on day %d\n", day);
                break;
            }
            
        }
    }while(h != 0);
    
    
    
}