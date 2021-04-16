#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    int s1Len, s2Len, s3Len;
    string a, b, c;
    int mem[202][202];

    bool isInterleave(string s1, string s2, string s3) {
        s1Len = s1.length(), s2Len = s2.length(), s3Len = s3.length();
        if (s1Len + s2Len != s3Len) return false;

        a = s1, b = s2, c = s3;
        memset(mem, -1, sizeof(mem));

        return dp(0, 0, 0);
    }

    bool dp(int i, int j, int k) {
        if (k == s3Len && i == s1Len && j == s2Len) return true;

        if (mem[i][j] != -1) return mem[i][j];

        bool x = false, y = false;
        if (i < s1Len && a[i] == c[k]) x = dp(i+1, j, k+1);
        if (j < s2Len && b[j] == c[k]) y = dp(i, j+1, k+1);

        return mem[i][j] = (int)(x || y);
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution sln;
    cout << sln.isInterleave(s1, s2, s3) << "\n";

    return 0;
}

