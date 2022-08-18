class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> dp(n, 1), path(n), lds;
        
        int maxi = 0, mx_ind = 0;
        for (int i = 0; i < n; ++i) {
            path[i] = i;
            for (int j = 0; j < i; ++j) {
                if (a[i]%a[j] == 0 && 1+dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    path[i] = j;
                }
            }
            
            if (dp[i] > maxi) {
                maxi = dp[i];
                mx_ind = i;
            }
        }
        
        lds.push_back(a[mx_ind]);
        while(path[mx_ind] != mx_ind) {
            mx_ind = path[mx_ind];
            lds.push_back(a[mx_ind]);
        }
        reverse(lds.begin(), lds.end());
        
        return lds;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
