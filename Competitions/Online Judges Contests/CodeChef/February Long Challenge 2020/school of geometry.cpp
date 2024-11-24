#include <iostream>
#include <string.h>
using namespace std;

void merge(int num[], int low, int mid, int hi){
    int tempSize = hi - low + 1;
    int tempArr[tempSize];
    int leftCurr = low;
    int rightCurr = mid + 1;
    int currIdx = 0;
    while(leftCurr <= mid && rightCurr <= hi) tempArr[currIdx++] = (num[leftCurr] <= num[rightCurr]) ? num[leftCurr++] : num[rightCurr++];
    while(leftCurr <= mid) tempArr[currIdx++] = num[leftCurr++];
    while(rightCurr <= hi) tempArr[currIdx++] = num[rightCurr++];
    for(int i = low, j = 0; i <= hi; i++, j++) num[i] = tempArr[j];
}

void mergeSort(int num[], int low, int high){
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(num, low, mid);
    mergeSort(num, mid + 1, high);
    merge(num, low, mid, high);
}

void show(int arr[], int len) {
    for(int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << endl;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main () {
    int rep; cin >> rep;
    int a[10001], b[10001], ttl;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    long sum;
    while (rep--) {
        cin >> ttl;
        for(int i = 0; i < ttl; i++) cin >> a[i];
        for(int i = 0; i < ttl; i++) cin >> b[i];
        mergeSort(a, 0, ttl-1);
        mergeSort(b, 0, ttl-1);

        sum = 0;
        for(int i = 0; i < ttl; i++) sum += min(a[i], b[i]);
        cout << sum << endl;
    }
    return 0;
}