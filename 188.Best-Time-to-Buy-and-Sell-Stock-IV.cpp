class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for (int i = 0; i <= n; ++i)
            dp[i][0][0] = dp[i][1][0] = 0;

        for (int c = 0; c <= k; ++c) 
            dp[n][0][c] = dp[n][1][c] = 0;

        for (int i = n-1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cnt = 0; cnt <= k; ++cnt) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[i] + dp[i+1][0][cnt], dp[i+1][1][cnt]);
                    }
                    else {
                        if (cnt > 0)
                            profit = max(prices[i] + dp[i+1][1][cnt-1], dp[i+1][0][cnt]);
                    }

                    dp[i][buy][cnt] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
