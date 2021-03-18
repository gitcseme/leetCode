#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> container[1005];
        int n = s.length();
        int pointer = 0;
        while(pointer < n) {
            for (int i = 1; i <= numRows && pointer < n; ++i)
                container[i].push_back(s[pointer++]);

            for (int i = numRows-1; i > 1 && pointer < n; --i)
                container[i].push_back(s[pointer++]);
        }

        string ans = "";
        for (int i = 1; i <= numRows; ++i) {
            for (char c : container[i])
                ans += c;
        }

        return ans;
    }
};

int main() {
    //FI;

    string s;
    int numRows;
    cin >> s >> numRows;

    Solution sln;
    cout << sln.convert(s, numRows) << "\n";


    return 0;
}



















