class Solution {
public:
    bool checkPossible(string &s, string &t) {
        int sl = s.length(), tl = t.length();
        if (sl != 1 + tl) return false;
        int diff = 0, i = 0, j = 0;
        
        while (i < sl || j < tl) {
            if (i < sl && j < tl && s[i] == t[j]) {
                ++i;
                ++j;
            }
            else {
                ++i;
                ++diff;
                if (diff > 1) return false;
            }
        }
        
        return diff == 1;
    }
    
    int longestStrChain(vector<string>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), [](string x, string y) {
            return x.length() < y.length();   
        });
        
        int maxi = 1;
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (checkPossible(a[i], a[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
                if (dp[i] > maxi) {
                    maxi = dp[i];
                }
            }
        }
        return maxi;
    }
};
