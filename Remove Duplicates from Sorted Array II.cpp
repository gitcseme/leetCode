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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
                nums.erase(nums.begin() + i);
                --i;
            }
        }
        return nums.size();
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {0,0,1,1,1,1,2,3,3};
    cout << sln.removeDuplicates(vec) << "\n";

    for (int x : vec)
        cout << x << " ";

    return 0;
}

