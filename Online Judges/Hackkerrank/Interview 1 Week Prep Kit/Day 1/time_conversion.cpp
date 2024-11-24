#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string &s) {
    
    int hour = stoi(s.substr(0, 2));
    if(s.substr(8, 2) == "AM") {
        if (hour == 12) hour = 0;
    } else if (s.substr(8, 2) == "PM") {
        if (hour != 12) hour += 12;
    };
    
    size_t n = 2;
    int precision = n - std::min(n, to_string(hour).size());    
    string res = string(precision, '0').append(to_string(hour)) + s.substr(2, 6);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
