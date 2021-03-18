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
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        map<char, vector<string>> letters = {
            {'2', {"a","b","c"}}, {'3', {"d","e","f"}}, {'4', {"g","h","i"}}, {'5', {"j","k","l"}},
            {'6', {"m","n","o"}}, {'7', {"p","q","r","s"}}, {'8', {"t","u","v"}}, {'9', {"w","x","y","z"}}
        };

        vector<string> combinations = letters[digits[0]];

        for (int i = 1; i < digits.length(); ++i)
            combinations = combine(combinations, letters[digits[i]]);

        return combinations;
    }

    vector<string> combine(vector<string> set1, vector<string> set2) {
        vector<string> res;
        for (string a : set1)
            for (string b : set2)
                res.push_back(a+b);
        return res;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    string digits = "2";
    Solution sln;
    vector<string> ans = sln.letterCombinations(digits);
    FOR(ans);


    return 0;
}
