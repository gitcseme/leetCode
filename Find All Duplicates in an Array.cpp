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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int numIndex = abs(nums[i]) - 1;
            if (nums[numIndex] > 0) {
                nums[numIndex] = -nums[numIndex];
            }
            else ans.push_back(numIndex + 1);
        }

        return ans;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<int> vec = {4,3,2,7,8,2,3,1};
    Solution sln;
    for(int n : sln.findDuplicates(vec))
        cout << n << " ";

    return 0;
}



















