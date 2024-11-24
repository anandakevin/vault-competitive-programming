#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {
    string tempS = s;
    int idx = -1;
    for(int i = 0, j = tempS.length() - 1; i < j; i++, j--) {
        // cout << i << " " << tempS[i] << " " << j << " " << tempS[j] << " " << idx << " " << tempS << endl;
        if(tempS[i] != tempS[j]){
            if(idx == -1) {
                if(tempS[i+1] == tempS[j] && tempS[i+2] == tempS[j-1]) {
                    idx = i; 
                    tempS.erase(i, 1); 
                    j-=1;
                }
                else if(tempS[i] == tempS[j-1] && tempS[i+1] == tempS[j-2]) {
                    idx = j; 
                    tempS.erase(j, 1); 
                    j -= 1;
                }    
            } else {idx = -1; break;}
        }
    }
    cout << idx << endl;
    return idx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

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
