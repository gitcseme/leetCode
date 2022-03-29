class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r = mat.size();
        
        int sum = 0;
        for (int i = 0; i < r; ++i) {
            sum += mat[i][i];
            sum += mat[r-i-1][i];
        }
        
        if (r%2 == 1) {
            int c = r/2;
            sum -= mat[c][c];
        }
        
        return sum;
    }
};
