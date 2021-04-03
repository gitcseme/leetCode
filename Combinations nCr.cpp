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
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        nCr({}, 1, k, n);
        return res;
    }

    void nCr(vector<int> com, int i, int k, int n) {
        if (com.size() == k ) {
            res.push_back(com);
            return;
        }
        if (i > n) return;
        else if (com.size() + (n-i+1) >= k) {
            com.push_back(i);
            nCr(com, i+1, k, n);

            com.pop_back();
            nCr(com, i+1, k, n);
        }
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    auto ans = sln.combine(4, 2);
    for (auto v : ans) {
        FOR(v);
    }

    return 0;
}

