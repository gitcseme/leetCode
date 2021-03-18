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
    bool isPalindrome(int x) {
        if (x < 0 || (x%10==0 && x!=0)) return false;

        int rev_x = 0;
        while (x > rev_x) {
            rev_x = rev_x * 10 + x%10;
            x = x / 10;
        }

        return (x == rev_x || (x == (rev_x/10)));
    }
};

int main() {
    //FI;
    Solution sln;
    string ans = sln.isPalindrome(13321) ? "true" : "false";
    cout << ans << "\n";

    return 0;
}
