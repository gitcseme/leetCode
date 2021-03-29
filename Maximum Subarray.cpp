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
    int maxSubArray(vector<int>& nums) {
        int mx = -1000005, sum = -1000005;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            sum = max(sum + nums[i], nums[i]);
            mx = max(mx, sum);
        }
        return mx;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sln.maxSubArray(vec) << "\n";

    return 0;
}

