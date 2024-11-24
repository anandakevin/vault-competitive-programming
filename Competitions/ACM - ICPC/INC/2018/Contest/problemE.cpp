#include <iostream>
using namespace std;

int countGood(int num[], int ttlNum){

}

int countGreat(int num[], int ttlNum){
	int numOfModif = 0;
	
}

int countSuperb(int num[], int ttlNum){
	int ctNum[10], maxRes = 0;
	for(int i = 0; i < 10; i++) ctNum[i] = 0;
	for(int i = 0; i < ttlNum - 1; i++){
		ctNum[num[i]]++;
	}
	for(int i = 0; i < 10; i++) maxRes = max(ctNum[i], maxRes);
	return ttlNum - maxRes;
}

int main(){
	int rep; cin >> rep;
	int num[rep];
	for(int i = 0; i < rep; i++) cin >> num[i];
	cout << countSuperb(num, rep);

}