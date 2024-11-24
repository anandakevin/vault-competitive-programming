#include <iostream>
#include <string.h>

using namespace std;

int a[100001];

long countsum(int start, int end) {
    long sum = 0;
    for(int i = start; i < end; i++) sum += a[i];
    return sum;
}

long countsummod(int start, int end, int k) {
    long sum = 0;
    for(int i = start; i < end; i++) sum += a[i] % k;
    return sum;
}

long countsummodleft(int start, int end, int k) {
    long sum = 0;
    for(int i = start; i < end; i++) sum += (a[i] % k == 0) ? 0 : k - a[i] % k;
    return sum;
}

long min(long a, long b) {
    return (a > b) ? b : a;
}

long max(long a, long b) {
    return (a > b) ? a : b;
}

void show(int len) {
    for(int i = 0; i < len; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int rep; cin >> rep;
    memset(a, 0, sizeof(a));
    for(int z = 0; z < rep; z++) {
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        // cout << "Case #" << z << ": " << endl;
        // show(n);
        long leftover = 1000000;
        for(int c = 0; c <= n; c++) {
            long sum0toc = countsum(0, c);
            long sumcplus1toend = countsummodleft(c, n, k);
            if(sumcplus1toend > sum0toc) continue;
            long diff = sum0toc - sumcplus1toend;
            diff %= k;
            // cout << "C: " << c << " " << sum0toc << " " << sumcplus1toend << " " << diff << endl;
            leftover = min(leftover, diff);
        }
        cout << leftover << endl;
    }
    return 0;
}