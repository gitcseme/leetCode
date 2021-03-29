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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vpii;
        for (vector<int> v : intervals)
            vpii.push_back(make_pair(v[0], v[1]));

        sort(vpii.begin(), vpii.end());

        vector<vector<int>> res;
        int len = vpii.size();
        for (int i = 0; i < len; ++i) {
            int j = i;
            int mx_r = vpii[j].second;

            while (j < len-1 && mx_r >= vpii[j+1].first) {
                mx_r = max(mx_r, vpii[j+1].second);
                ++j;
            }

            res.push_back({vpii[i].first, mx_r});
            i = j;
        }

        return res;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    vector<vector<int>> vvi = { {1,3}, {2,6}, {8,10}, {15,18} };
    Solution sln;
    auto ans = sln.merge(vvi);

    for (auto v : ans) {
        cout << v[0] << " " << v[1] << "\n";
    }

    return 0;
}

