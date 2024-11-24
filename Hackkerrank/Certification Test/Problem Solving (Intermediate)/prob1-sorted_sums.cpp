#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'sortedSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int sortedSum(vector<int> a) {

    cout << "in sortedSum" << endl;
    // long minNum = 1000001, maxNum = -1;
    // int numPos[1000001];
    // for(int i = 0; i < 1000001; i++) numPos[i] = 0;
    int modBy = 1000000007;
        
    // for(int i = 0; i < a.size(); i++) {
    //     cout << "assigning " << a[i] << " on i " << i << endl;
    //     numPos[a[i]] = i+1;
    //     if(minNum > a[i]) minNum = a[i];
    //     if(maxNum < a[i]) maxNum = a[i];
    // }
    
    // for(int i = minNum; i <= maxNum; i++) {
    //     cout << "for i " << i << " pos is " << numPos[i] << endl;
    // }
    
    long ttl = 0;
    // for(int i = 1; i <= a.size(); i++) {
    //     long tempTtl = 0;
    //     int currPos = 1;
    //     for(int j = minNum; j <= maxNum; j++) {
    //         if(numPos[j] > 0 && numPos[j] <= i) {
    //             tempTtl += (j*currPos) % modBy;
    //             tempTtl %= modBy;
    //             currPos++;
    //         }
    //     }
    //     ttl += tempTtl;
    //     ttl %= modBy;
    // }
    
    cout << "ttl is " << ttl << endl;
    
    return ttl;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    cout << "in main" << endl;
    for(int i = 0; i < a.size(); i++) {
        cout << "a[i] is " << a[i] << " on i " << i << endl;
    }
    int result = sortedSum(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
