#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

vector<string> mostActive(vector<string> customers) {
    unordered_map<string, int> custStats;
    vector<string> res;
    int ttl = 0;
    for(int i = 0; i < (int) customers.size(); i++) {
        if (custStats.find(customers[i]) != custStats.end()) {
            custStats[customers[i]]++;
        } else {
            custStats.insert({customers[i], 1});
        }
        ttl++;
    };
    
    unordered_map<string, int>:: iterator itr;
    cout << "\nAll Elements : \n";
    int itrNo = 1;
    for (itr = custStats.begin(); itr != custStats.end(); itr++)
    {
        double percentage = itr->second*100/ttl;
        cout << "onItr " << itrNo++ << " " << itr->first << "  " << itr->second << " perc " << percentage << endl;
        if(percentage >= 5) res.push_back(itr->first);
    }
    
    for(int i = 0; i < res.size(); i++) {
        cout << "i " << i << " res is " << res[i] << endl;
    }
    
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string customers_count_temp;
    getline(cin, customers_count_temp);

    int customers_count = stoi(ltrim(rtrim(customers_count_temp)));

    vector<string> customers(customers_count);

    for (int i = 0; i < customers_count; i++) {
        string customers_item;
        getline(cin, customers_item);

        customers[i] = customers_item;
    }

    vector<string> result = mostActive(customers);

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
