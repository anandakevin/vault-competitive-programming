#include <iostream>
using namespace std;

struct times{
    long long first, sec;
};

times sch[4];

int main(){
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++){
        for(int j = 0; j < 4; j++){
            long long d, m, y, h, mnt, s;
            cin >> d >> m >> y >> h >> mnt >> s;
            y -= 3000;
            sch[j].first = y * 20 * 50 * 24 * 3600 + m * 50 * 24 * 3600 + d * 24 * 3600 + h * 3600 + mnt * 60 + s;
            cin >> d >> m >> y >> h >> mnt >> s;
            y -= 3000;
            sch[j].sec = y * 20 * 50 * 24 * 3600 + m * 50 * 24 * 3600 + d * 24 * 3600 + h * 3600 + mnt * 60 + s;
        }
        bool checkCond = true;
        for(int j = 0; j < 3; j++){
            if((sch[3].first >= sch[j].first && sch[3].first <= sch[j].sec) || (sch[3].sec >= sch[j].first && sch[3].sec <= sch[j].sec)) {
                checkCond = false; break;
            }
            if((sch[j].first >= sch[3].first && sch[j].first <= sch[3].sec) || (sch[j].sec >= sch[3].first && sch[j].sec <= sch[3].sec)) {
                checkCond = false; break;
            }
        }
        if(checkCond) cout << "Case #" << i << ": OK" << endl;
        else cout << "Case #" << i << ": COLLIDE" << endl;
    }
    return 0;
}
