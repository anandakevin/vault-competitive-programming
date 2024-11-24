#include <iostream>
#include <algorithm>
using namespace std;

struct ct{
    long long num, prime1, prime2;
};

ct numbers[101];
long long primes[26], characters[102], ttlPrime = 0, ttlChar = 0;

long long gcd(long long num1, long long num2){
    if(num1 == 0) return num2;
    return gcd(num2 % num1, num1);
}

int findPrime(long long num){
    for(int i = 0; i < ttlPrime; i++) {
        if(primes[i] == num) return i;
    }
    return -1;
}

string getAns(){
    string temp = "";
    for(int i = 0; i < ttlChar; i++){
        temp += findPrime(characters[i]) + 'A';
    }
    return temp;
}

void reset(){
    ttlPrime = 0;
    ttlChar = 0;
    for(int j = 0; j < 101; j++) {
        numbers[j].num = 0;
        numbers[j].prime1 = 0;
        numbers[j].prime2 = 0;
        primes[j] = 0;
        characters[j] = 0;
    }
    for(int j = 0; j < 26; j++) primes[j] = 0;
}

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        reset();
        long long maxPrime;
        int len; cin >> maxPrime >> len;
        for(int j = 0; j < len; j++) cin >> numbers[j].num;
        for(int j = 0; j < len - 1; j++){
            long long firstPrime = gcd(numbers[j].num, numbers[j + 1].num);
            long long secPrime = numbers[j].num / firstPrime;
            long long thirdPrime = numbers[j + 1].num / firstPrime;
            numbers[j].prime2 = firstPrime;
            numbers[j].prime1 = secPrime;
            numbers[j + 1].prime1 = firstPrime;
            numbers[j + 1].prime2 = thirdPrime;
            characters[ttlChar++] = numbers[j].prime1;
            if(findPrime(firstPrime) == -1) primes[ttlPrime++] = firstPrime;
            if(findPrime(secPrime) == -1) primes[ttlPrime++] = secPrime;
            if(findPrime(thirdPrime) == -1) primes[ttlPrime++] = thirdPrime;
        }
        characters[ttlChar++] = numbers[len - 1].prime1;
        characters[ttlChar++] = numbers[len - 1].prime2;
        sort(begin(primes), end(primes));
        cout << "Case #" << i << ": " << getAns() << endl;
    }
    return 0;
}