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
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;

        while (L < R) {
            int mid = (L+R) / 2;
            if (nums[mid] > nums[R])
                L = mid + 1;
            else
                R = mid;
        }

        int start = L;
        L = 0;
        R = nums.size()-1;
        if (target >= nums[start] && target <= nums[R])
            L = start;
        else
            R = start;

        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                L = mid + 1;
            }
            else
                R = mid - 1;
        }

        return -1;
    }
};


static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<int> vec = {4,5,6,7,0,1,2};
    Solution sln;
    cout << sln.search(vec, 0);

    return 0;
}



















