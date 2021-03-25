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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int mem[1005];
        memset(mem, -1, sizeof(mem));
        return dp(nums, 0, n, mem);
    }

    int MAX_JUMP = 100005;

    int dp(vector<int> nums, int i, int n, int mem[]) {
        if (i == n-1) return 0;
        if (i >= n) return MAX_JUMP;

        if (mem[i] != -1) return mem[i];

        int min_jump = MAX_JUMP;
        for (int j = 1; j <= nums[i]; ++j) {
            int newJump = 1 + dp(nums, i+j, n, mem);
            min_jump = min(min_jump, newJump);
        }

        return mem[i] = min_jump;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {2,3,0,1,4};
    cout << sln.jump(vec) << "\n";

    return 0;
}

