#include <stdio.h>

int main () {
    int rep; scanf("%d", &rep);
    for(int i = 1; i <= rep; i++) {
        int n; scanf("%d", &n);
        int floors[20], numberofpressed = 0;
        for(int j = 0; j < 20; j++) floors[j] = 0;
        for(int j = 0; j < n; j++) {
            int currfloor; scanf("%d", &currfloor);
            if(floors[currfloor] != 1 && floors[currfloor - 1] != 1 && floors[currfloor + 1] != 1) {
                floors[currfloor] = 1;
                numberofpressed++;
            }
        }
        printf("Case #%d: %d\n", i, numberofpressed);
    }
    return 0;
}