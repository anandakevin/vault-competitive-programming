#include <iostream>
#include <stdio.h>
#define clear cin.clear(); cin.sync();
using namespace std;

int main() {
	int emp;
	cin >> emp; clear;
	float rating = 0;
    int ttlGoodEmployee = 0;
	for(int i = 0; i < emp; i++){
		int temp; cin >> temp; clear;
		if(temp >= 90){
			rating += temp; ttlGoodEmployee += 1;
		}
	}
    rating /= ttlGoodEmployee;
	printf("%.02f", rating);
	return 0;
}