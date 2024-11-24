#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Query
{
    int opt;
    int idx;
    string str;
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int queries;
    cin >> queries;

    stack<Query> stackOfQueries;
    string str = "";
    while (queries > 0)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            string tmp;
            cin >> tmp;
            Query query = {opt, (int)str.length(), tmp};
            str += tmp;
            stackOfQueries.push(query);
        }
        else if (opt == 2)
        {
            int len;
            cin >> len;
            string removedChar = str.substr(str.length() - len, len);
            Query query = {opt, (int)str.length() - len, removedChar};
            stackOfQueries.push(query);
            str.erase(str.length() - len, len);
        }
        else if (opt == 3)
        {
            int idx;
            cin >> idx;
            cout << str[idx - 1] << endl;
        }
        else if (opt == 4)
        {
            Query query = stackOfQueries.top();
            if (query.opt == 1)
            {
                str.erase(query.idx, query.str.length());
            }
            else if (query.opt == 2)
            {
                str.insert(query.idx, query.str);
            }
            stackOfQueries.pop();
        }
        queries--;
    }
    return 0;
}
