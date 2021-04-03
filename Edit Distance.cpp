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
    int mem[505][505];
    int M, N;
    string A, B;

    int minDistance(string word1, string word2) {
        M = word1.length();
        N = word2.length();
        A = word1;
        B = word2;
        memset(mem, -1, sizeof(mem));
        int ans = dp(0, 0);
        return ans;
    }

    int dp (int i, int j)
    {
        if (i == M && j == N) return 0;
        else if(i == M) return (N-j);
        else if(j == N) return (M-i);

        if (mem[i][j] != -1) return mem[i][j];

        int ans = 0;
        if (A[i] == B[j])
            ans = dp(i+1, j+1);
        else                 // insert      delete       replace
            ans = 1 + min ( min(dp(i, j+1), dp(i+1, j)), dp(i+1, j+1) );

        return mem[i][j] = ans;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    cout << sln.minDistance("intention", "execution") << "\n";

    return 0;
}

