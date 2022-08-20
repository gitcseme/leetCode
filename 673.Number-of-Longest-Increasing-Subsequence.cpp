class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1), cnt(n, 1);
        
        int maxi = 1, mx_ind = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if (a[i] > a[j] && 1 + dp[j] == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        int lis = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxi)
                lis += cnt[i];
        }
        
        return lis;
    }
};
