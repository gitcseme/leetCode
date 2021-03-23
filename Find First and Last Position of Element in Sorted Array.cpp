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
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};

        int lPos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lPos < nums.size() && nums[lPos] == target) {
            int rPos = lPos;
            while (1) {
                if (rPos < nums.size()-1 && nums[rPos+1] == nums[lPos])
                    ++rPos;
                else
                    break;
            }
            return {lPos, rPos};
        }

        return {-1, -1};
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<int> nums = {5,7,7,8,8,10};
    Solution sln;
    auto pos = sln.searchRange(nums, 8);
    cout << pos[0] << " " << pos[1] << "\n";

    return 0;
}



















