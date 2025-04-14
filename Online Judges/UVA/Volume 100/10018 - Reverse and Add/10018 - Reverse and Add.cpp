#include <stdio.h>

long long reverse(long long angka){
    long long hasil = 0;
    while(angka != 0){
        hasil = hasil * 10;
        hasil = hasil + angka%10;
        angka = angka/10;
    }
    return hasil;   
}

int main() {
    int kasus, jumlah;
    long long hasil, angka;
    
    scanf("%d", &kasus);
    getchar();
    
    for(int i=0; i<kasus; i++){
        jumlah = 0;
        scanf("%lli", &angka);
        getchar();
        
        hasil = reverse(angka);
        do{
            angka += hasil;
            hasil = reverse(angka);
            jumlah++;
        }while(angka != hasil);
        printf("%d %lli\n", jumlah, hasil);
        
    }
    
    return 0;
}