#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> m = { {'(', ')'}, {'{','}'}, {'[',']'} };

        for (int i = 0, len = s.length(); i < len; ++i) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.empty() || m[stk.top()] != c)
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {
    //FI;
    Solution sln;
    string exp = "([)]";
    cout << sln.isValid(exp) << "\n";

    return 0;
}
