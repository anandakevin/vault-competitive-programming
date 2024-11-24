#include <iostream>
#include <string.h>
using namespace std;

long long int arr[100010];
// long long int memo[100010]

long long int knap(int idx, long long int mult, int take){ // 1 ambil, 0 ngga

	if(idx < 0 || take == 0){
		//cout << "mul " << mult  << endl;
		if(mult % 4 == 0){
			//cout << "bsia  " << mult  << endl;
			return 1;
		} 

		return 0;
	}

	int pos = 0;
	pos += knap(idx-1, mult * arr[idx], 1);
	pos += knap(idx-1, mult, 0);

	return pos;
}

int main()
{
	
	int box;

	cin >> box;

	for (int i = 0; i < box; ++i){
		cin >> arr[i];

	}

	int ans = 0;

	for(int i = box - 1; i >= 0; i--){
		ans += knap(i, 1, 0);
		ans += knap(i, 1, 1);
	}

	cout << ans ;
	
	return 0;
}