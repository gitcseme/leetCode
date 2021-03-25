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
    bool canJump(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for (int i = 0; i < n && i <= mx; ++i) {
            mx = max(mx, i + nums[i]);
            if (mx >= n-1)
                return true;
        }
        return false;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {1};
    cout << sln.canJump(vec) << "\n";

    return 0;
}

