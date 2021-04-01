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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1) return obstacleGrid[0][0] == 0 ? 1 : 0;
        bool pos0 = obstacleGrid[0][0] == 1;

        int way = 1;
        for (int i = 1; i < obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i] == 1 || pos0) way = 0;
            obstacleGrid[0][i] = way;
        }

        way = 1;
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] == 1 || pos0) way = 0;
            obstacleGrid[i][0] = way;
        }

        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }

        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<vector<int>> grid = {{0}};
    cout << sln.uniquePathsWithObstacles(grid) << "\n";

    return 0;
}

