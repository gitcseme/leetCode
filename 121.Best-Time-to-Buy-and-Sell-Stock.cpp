// Solution 1 O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0, len = prices.size(); i < len; ++i) {
            if (minProfit > prices[i]) {
                minProfit = prices[i];
            }
            else if (prices[i] - minProfit > maxProfit) {
                maxProfit = prices[i] - minProfit;
            }
        }
        
        return maxProfit;
    }
};

// Solution 2 DP
class Solution {
    map<pair<int, int>, int> mem;
public:
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, prices.size()-1);
    }

    int solve(vector<int>& prices, int i, int j) {
        if (i >= j) return 0;

        if (mem.find({i, j}) != mem.end()) {
            return mem[{i, j}];
        }

        int way1 = max({(prices[j] - prices[i]),  solve(prices, i+1, j), 0});
        int way2 = max({(prices[j] - prices[i]), solve(prices, i, j-1), 0});

        int best = max(way1, way2);
        mem[{i, j}] = best;
        cout << i << " " << j << " =>" << best << "\n";
        return best;
    }
};
