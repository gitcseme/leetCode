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
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0, R = n-1;
        while (L < R) {
            int mid = L + (R-L)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) L = mid + 1;
            else R = mid;
        }
        if (L == 0 && target < nums[L]) return L;
        if (R == n-1 && target > nums[R]) return n;
        return L;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<int> nums = {1};
    Solution sln;
    int pos = sln.searchInsert(nums, -2);
    cout << pos << "\n";

    return 0;
}
