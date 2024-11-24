#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> vect;
	int banyak, angka, index = 0, jumlah = 0;
	do{
		scanf("%d", &banyak);
		getchar();
		
		if(banyak != 0){
			vect.clear();
			index = 0;
			jumlah = 0;
			for(int i=0; i<banyak; i++){
					scanf("%d", &angka);
					vect.push_back(angka);
			}
			
			sort(vect.begin(), vect.begin()+banyak);
			
			jumlah = vect.at(0)+vect.at(1);
			vect.push_back(vect.at(0)+vect.at(1));
			vect.erase(vect.begin());
			vect.erase(vect.begin());
			
			sort(vect.begin(), vect.begin()+vect.size());
			while(vect.size() != 1){
				jumlah += vect.at(0)+vect.at(1);
				vect.push_back(vect.at(0)+vect.at(1));
				vect.erase(vect.begin());
				vect.erase(vect.begin());
				
				sort(vect.begin(), vect.begin()+vect.size());
			}
			
			printf("%d\n", jumlah);
		}
		
	}while(banyak!=0);
	
	return 0;
}