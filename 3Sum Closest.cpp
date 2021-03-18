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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long closest = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int L = i+1, R = n-1;
            while (L < R) {
                long long tsum = nums[i] + nums[L] + nums[R];
                if (abs(tsum - target) < abs(closest-target))
                    closest = tsum;
                if (tsum > target) --R;
                else ++L;
            }
        }
        return closest;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<int> vec = {-1,2,1,-4};
    int target = 1;
    Solution sln;
    int ans = sln.threeSumClosest(vec, target);
    cout << ans << "\n";

    return 0;
}
