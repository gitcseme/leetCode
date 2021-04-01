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
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] = grid[i][j] + grid[i][j-1];
                else if (j == 0) grid[i][j] = grid[i][j] + grid[i-1][j];
                else grid[i][j] = grid[i][j] + min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << sln.minPathSum(grid) << "\n";

    return 0;
}

