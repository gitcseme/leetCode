#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int L = i+1, R = n-1;
            while (L < R) {
                int tsum = nums[i] + nums[L] + nums[R];
                if (tsum > 0) --R;
                else if (tsum < 0) ++L;
                else {
                    res.push_back({nums[i], nums[L], nums[R]});
                    ++L;
                    while (nums[L] == nums[L-1] && L < R) ++L;
                }
            }
        }
        return res;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<int> vec = {-1,0,1,2,-1,-4};
    Solution sln;
    auto ans = sln.threeSum(vec);
    for(auto s : ans) {
        cout << s[0] << "," << s[1] << "," << s[2] << "\n";
    }

    return 0;
}
