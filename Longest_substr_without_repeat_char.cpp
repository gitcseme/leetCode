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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> st;
        int maxLen = 0, i = 0, j = 0;

        while (i < n && j < n) {
            if (st.count(s[j]) == 0) {
                st.insert(s[j]);
                ++j;
                maxLen = max(maxLen, j-i);
            }
            else {
                st.erase(s[i]);
                ++i;
            }
        }

        return maxLen;
    }
};

int main() {
    //FI;
    string s;
    cin >> s;

    Solution sol;
    int len = sol.lengthOfLongestSubstring(s);
    cout << len << "\n";

    return 0;
}
