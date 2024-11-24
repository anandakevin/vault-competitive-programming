#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'authEvents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY events as parameter.
 */

int modBy = 1000000007;

long pow(int num, int power) {
    int res = 1;
    if(power == 0) return res;
    for(int i = 1; i <= power; i++) {
        res *= num % modBy; 
        res %= modBy;
    }
    // cout << "pow(" << num << ", " << power << ") is " << res << endl;
    return res;
}

int setHashValue(string str) {
    int val = 0, len = str.length(), p = 131;
    for(int i = 0; i < len; i++) {
        // cout << "on i " << i << " with char " << str[i] << " ascii is " << int(str[i]) << endl;
        val += str[i] * pow(p, (len - (i + 1))) % modBy;
        val %= modBy;
        // cout << "val is " << val << endl;
    }
    return val;
}

bool checkAppend(long long hashValue, long currValue) {
    if(hashValue == currValue) return true;
    else {
        // cout << "checking on hv " << hashValue << " cv " << currValue << endl; 
        hashValue *= 131;
        hashValue %= modBy;
        int diff = hashValue - currValue;
        // cout << "diff is " << diff << endl;
        if(diff >= -127 && diff <= 127) return true;
        else return false;
    }
}

vector<int> authEvents(vector<vector<string>> events) {
    int currHashValue = 0;
    vector<int> results;
    for(int i = 0; i < events.size(); i++) {
        // cout << "on i " << i << " i0 is " << events[i][0] << " i1 is " << events[i][1] << endl;
        if(events[i][0] == "setPassword") {
            currHashValue = setHashValue(events[i][1]);
        } else if(events[i][0] == "authorize") {
            // cout << "comparing " << currHashValue << " with " << stoi(events[i][1]) << endl; 
            if(checkAppend(currHashValue, stoi(events[i][1]))) {
                results.push_back(1);
            } else results.push_back(0);
        }
    }

    // cout << "result is" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string events_rows_temp;
    getline(cin, events_rows_temp);

    int events_rows = stoi(ltrim(rtrim(events_rows_temp)));

    string events_columns_temp;
    getline(cin, events_columns_temp);

    int events_columns = stoi(ltrim(rtrim(events_columns_temp)));

    vector<vector<string>> events(events_rows);

    for (int i = 0; i < events_rows; i++) {
        events[i].resize(events_columns);

        string events_row_temp_temp;
        getline(cin, events_row_temp_temp);

        vector<string> events_row_temp = split(rtrim(events_row_temp_temp));

        for (int j = 0; j < events_columns; j++) {
            string events_row_item = events_row_temp[j];

            events[i][j] = events_row_item;
        }
    }

    vector<int> result = authEvents(events);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
