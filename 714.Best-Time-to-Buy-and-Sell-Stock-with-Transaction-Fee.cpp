class Solution {
public:
    int n, tf;
    vector<vector<int>> mem;
    
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        tf = fee;
        mem.resize(n, vector<int>(2, -1));
        
        return solve(0, 1, prices);
    }
    
    int solve(int i, int buy, vector<int>& prices) {
        if (i == n) return 0;
        if (mem[i][buy] != -1) return mem[i][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(i+1, 0, prices), solve(i+1, 1, prices));
        }
        else {
            profit = max(prices[i] - tf + solve(i+1, 1, prices), solve(i+1, 0, prices));
        }

        return mem[i][buy] = profit;
    }
};
