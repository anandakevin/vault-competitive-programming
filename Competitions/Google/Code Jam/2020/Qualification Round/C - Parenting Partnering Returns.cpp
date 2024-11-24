#include <iostream>
#include <algorithm>
using namespace std;

struct assignment{
    int start, end, taskno;
    char takenby;
};

assignment schedule[1000];

void reset(int ttl) {
    for(int i = 0; i < ttl; i++) {
        schedule[i].start = 0;
        schedule[i].end = 0;
        schedule[i].taskno = 0;
        schedule[i].takenby = 'N';
    }
}

bool byFinishTime(const assignment &t1, const assignment &t2) { return t1.end < t2.end; }

bool byStartTime(const assignment &t1, const assignment &t2) { return t1.start < t2.start; }

bool byTaskno(const assignment &t1, const assignment &t2) {return t1.taskno < t2.taskno; }

void assign(int ttl) {
    int i = 0;
    schedule[0].takenby = 'C';
    int ccurr = 0;
    schedule[1].takenby = 'J';
    int jcurr = 1;
    for(int j = 2; j < ttl; j++) {
        if(schedule[j].start >= schedule[ccurr].end) {
            schedule[j].takenby = 'C';
            ccurr = j;
        } else if(schedule[j].start >= schedule[jcurr].end) {
            schedule[j].takenby = 'J';
            jcurr = j;
        }
    }
}

bool checkimpo(int ttl) {
    for(int j = 0; j < ttl; j++) {
        if(schedule[j].takenby == 'N') return true;
    }
    return false;
}

void printres(int ttl) {
    if(checkimpo(ttl)) {
        cout << "IMPOSSIBLE"; return;
    }
    for(int j = 0; j < ttl; j++) cout << schedule[j].takenby;
}

int main() {
    int rep; cin >> rep;
    for(int i = 1; i <= rep; i++) {
        int ttlasg; cin >> ttlasg;
        reset(ttlasg);
        for(int j = 0; j < ttlasg; j++) {
            cin >> schedule[j].start >> schedule[j].end;
            schedule[j].taskno = j + 1;
        }
        sort(schedule, schedule + ttlasg, byStartTime);
        assign(ttlasg);
        sort(schedule, schedule + ttlasg, byTaskno);
        cout << "Case #" << i << ": ";
        printres(ttlasg);
        cout << endl;
    }
    return 0;
}