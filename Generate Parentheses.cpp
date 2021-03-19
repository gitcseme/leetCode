#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        s.resize(n*2);
        generateAllCombinitions(s, 0, res, n*2);
        return res;
    }

    void generateAllCombinitions(string s, int pos, vector<string>& res, int n) {
        if (pos == n) {
            if (validParentheses(s))
                res.push_back(s);
        }
        else {
            s[pos] = '(';
            generateAllCombinitions(s, pos+1, res, n);
            s[pos] = ')';
            generateAllCombinitions(s, pos+1, res, n);
        }
    }

    bool validParentheses(string s) {
        int balance = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') ++balance;
            else --balance;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<string> res = sln.generateParenthesis(8);
    for (string s : res)
        cout << s << ", ";

    return 0;
}



















