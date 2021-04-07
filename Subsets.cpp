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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int subset = 0, c = pow(2, n); subset < c; ++subset) {
            vector<int> st;
            for (int i = 0; i < n; ++i)
                if ((subset & (1 << i)) != 0)
                    st.push_back(nums[i]);

            res.push_back(st);
        }
        return res;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {1,2,3};
    for (auto v : sln.subsets(vec)) {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

