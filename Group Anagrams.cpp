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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;
        string key;
        for (int i = 0; i < strs.size(); ++i) {
            key = strs[i];
            sort(key.begin(), key.end());
            groups[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            res.push_back(it->ss);
        }

        return res;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<string> vec = {"eat","tea","tan","ate","nat","bat"};
    auto ans = sln.groupAnagrams(vec);
    for (auto v : ans) {
        FOR(v);
    }

    return 0;
}

