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
    int climbStairs(int n) {
        vector<int> jmp(50);
        jmp[1] = 1;
        jmp[2] = 2;
        for (int i = 3; i <= 45; ++i) jmp[i] = jmp[i-1] + jmp[i-2];

        return jmp[n];
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    cout << sln.climbStairs(45);

    return 0;
}

