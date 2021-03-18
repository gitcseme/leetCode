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
    string longestPalindrome(string a) {
        string b = a;
        reverse(b.begin(), b.end());

        int n = a.length();
        int m = n;

        int dp[n+1][m+1];
        int lcs = 0, ans_r;

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }

                if (a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;

                if (dp[i][j] > lcs && is_palindrome(a.substr(i-dp[i][j], dp[i][j]) )) {
                    lcs = dp[i][j];
                    ans_r = i;
                }
            }
        }

        return a.substr(ans_r - lcs, lcs);
    }

    bool is_palindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r == s;
    }
};

int main() {
    //FI;

    string a, b;
    cin >> a;

    Solution sln;
    string ans = sln.longestPalindrome(a);
    cout << ans << "\n";

    return 0;
}



















