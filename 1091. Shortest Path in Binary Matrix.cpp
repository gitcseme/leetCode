class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(101, vector<bool>(101, false));
        
        if (grid[0][0] == 1) return -1;
        if (n == 1) {
            return grid[0][0] == 0 ? 1 : -1;
        }
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0] = true;
        
        int dx[8] = {-1, -1, 0, +1, 1, +1, +0, -1};
        int dy[8] = {+0, +1, 1, +1, 0, -1, -1, -1};
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            
            for (int i = 0; i <8; ++i) {
                int x = u.first.first + dx[i];
                int y = u.first.second + dy[i];
                int level = u.second;
                
                if (isSafe(x, y, n) && grid[x][y] == 0 && !vis[x][y]) {
                    q.push({ {x, y}, level+1 });
                    vis[x][y] = true;
                    
                    if(x == n-1 && y == n-1)
                        return level + 1;
                }
            }
        }
        
        return -1;
    }
    
    bool isSafe(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};
