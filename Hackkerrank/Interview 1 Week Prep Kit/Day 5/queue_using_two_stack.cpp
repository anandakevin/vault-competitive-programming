#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    queue<int> q;
    int cmds;
    cin >> cmds;
    while (cmds > 0)
    {
        int currcmd;
        cin >> currcmd;
        switch (currcmd)
        {
        case 1:
            int num;
            cin >> num;
            q.push(num);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout << q.front() << endl;
            break;
        }
        cmds--;
    }
    return 0;
}
