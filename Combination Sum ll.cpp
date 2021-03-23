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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> c;
        sort(candidates.begin(), candidates.end());
        subset_sum(candidates, target, 0, c, candidates.size(), res);
        return res;
    }

    void subset_sum(vector<int>& nums, int target, int i, vector<int> c, int n, vector<vector<int>>& res) {
        if (target < 0) return;

        if (target == 0) {
            res.push_back(c);
        }
        else if (i < n) {
            if (nums[i] <= target) {
                c.push_back(nums[i]);
                subset_sum(nums, target-nums[i], i+1, c, n, res);
                c.pop_back();

                while (i < n-1 && nums[i] == nums[i+1]) ++i;
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
    vector<vector<int>> ans = sln.combinationSum2(vec, 1);

    for (auto v : ans) {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

