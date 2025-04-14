#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
        int tc, jmlhList, jmlList, angka, cari, banyak;
        vector<int> newList, ga;
        vector<int>::iterator it;
        
        scanf("%d", &tc);
        getchar();
        
        for(int i=0; i<tc; i++){
            newList.clear();
            ga.clear();
            scanf("%d %d", &jmlhList, &jmlList);
            getchar();
            
            for(int j=0; j<jmlhList; j++){
                scanf("%d", &angka);
                getchar();
                newList.push_back(angka);
            }
            
            for(int j=0; j<jmlList; j++){
                scanf("%d", &cari);
                getchar();
                
                it = find(newList.begin(), newList.end(), cari);
                int pos = it- newList.begin();
                if(newList.size() != pos){
                     newList.erase(newList.begin()+pos);
                }else{
                    ga.push_back(cari);
                }
                
            }
            
            printf("%d\n",ga.size()+newList.size());
        }
    
    
    return 0;
}