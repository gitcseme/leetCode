class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mw = 0, m = accounts[0].size(), n = accounts.size();
        
        for (int i = 0; i < n; ++i) {
            int local = 0;
            for (int j = 0; j < m; ++j) {
                local += accounts[i][j];
            }
            mw = max(mw, local);
        }
        
        return mw;
    }
};
