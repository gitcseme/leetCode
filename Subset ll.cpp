#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generateSubsets(0, {}, nums);
        vector<vector<int>> res;
        for(auto v : ans)
            res.push_back(v);
        return res;
    }

    void generateSubsets(int i, vector<int> subset, vector<int> nums) {
        if (i == nums.size()) {
            //sort(subset.begin(), subset.end());
            ans.insert(subset);
        }
        else {
            subset.push_back(nums[i]);
            generateSubsets(i+1, subset, nums);

            subset.pop_back();
            generateSubsets(i+1, subset, nums);
        }
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> nums = {2, 2, 1};
    vector<vector<int>> ans = sln.subsetsWithDup(nums);

    for (auto v : ans) {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

