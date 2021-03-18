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
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int mxArea = 0;
        while (l < r) {
            mxArea = max(mxArea, min(height[l], height[r]) * (r-l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return mxArea;
    }
};

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    int ans = sln.maxArea(vec);
    cout << ans << "\n";

    return 0;
}
