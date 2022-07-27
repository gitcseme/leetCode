class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        return (n - longestPalindromeSubseq(s, n));
    }
    
    int longestPalindromeSubseq(string s, int n) {
        string t = s;
        reverse(t.begin(), t.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s.at(i-1) == t.at(j-1))
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
