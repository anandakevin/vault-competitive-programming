#include <iostream>
using namespace std;

int canBeBought[100001];

void reset(int budget) {
    for(int i = 0; i <= budget; i++)  canBeBought[i] = 0;
}

void check(int budget) {
    for(int i = 0; i <= budget; i++)  cout << "with budget " << i << " can buy " << canBeBought[i] << endl;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++) {
        
        int maxHouse = 0;
        int numOfHouse, budget; cin >> numOfHouse >> budget;
        reset(budget);
        int housePrices[numOfHouse + 1];
        for(int j = 0; j < numOfHouse; j++) cin >> housePrices[j];
        for(int j = 0; j < numOfHouse; j++) {
            
            for(int k = budget; k >= housePrices[j]; k--) {
                canBeBought[k] = max(canBeBought[k - housePrices[j]] + 1, canBeBought[k]);
            }
            // check(budget);
        }
        // check(budget);
        // for(int j = 0; j <= budget; j++) maxHouse = max(maxHouse, canBeBought[j]);
        cout << "Case #" << i << ": " << canBeBought[budget] << endl;
    } 
    return 0;
}