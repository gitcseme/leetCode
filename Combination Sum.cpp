#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int len = candidates.size();
        vector<int> c;
        subset_sum(candidates, target, 0, c, len, res);
        return res;
    }

    void subset_sum(vector<int>& nums, int target, int i, vector<int> c, int n, vector<vector<int>>& res) {

        //FOR(c);
        if (target < 0) return;

        if (target == 0) {
            res.push_back(c);
        }
        else if (i < n) {
            if (nums[i] <= target) {
                c.push_back(nums[i]);
                subset_sum(nums, target-nums[i], i, c, n, res);
                c.pop_back();
            }
            subset_sum(nums, target, i+1, c, n, res);
        }
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {1};
    vector<vector<int>> ans = sln.combinationSum(vec, 2);

    for (auto v : ans) {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

