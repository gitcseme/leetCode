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
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int L[n], R[n];
        L[0] = R[n-1] = 0;
        int lMax = height[0], rMax = height[n-1];
        for(int i = 1, j = n-2; i < n && j >= 0; ++i, --j) {
            lMax = max(lMax, height[i]);
            rMax = max(rMax, height[j]);
            L[i] = lMax;
            R[j] = rMax;
        }

        int h, water = 0;
        for (int i = 1; i < n-1; ++i) {
            h = min(R[i], L[i]);
            if (h > height[i])
                water += h - height[i];
        }

        return water;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {3, 1, 3};
    cout << sln.trap(vec) << "\n";

    return 0;
}

