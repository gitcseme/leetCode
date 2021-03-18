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
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        if (strs.size() == 0) return lcp;

        int j = 0;
        while (1) {
            if (!(j < strs[0].length()))
                break;
            char c = strs[0][j];

            bool match = true;
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i].length()==0 || strs[i].length() < j || strs[i][j] != c) {
                    match = false;
                    break;
                }
            }

            if (!match) break;
            else {
                lcp += c;
                ++j;
            }
        }
        return lcp;
    }
};

int main() {
    //FI;
    Solution sln;
    vector<string> vec = {"a"};
    cout << sln.longestCommonPrefix(vec) << "\n";

    return 0;
}
