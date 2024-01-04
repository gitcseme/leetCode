#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> positions;

        for (int i = 0, n = matrix.size(); i < n; ++i) {
            for (int j = 0, m = matrix[0].size(); j < m; ++j) {
                if (matrix[i][j] == 0) {
                    positions.push_back({i, j});
                }
            }
        }

        for (auto p : positions) {
            fillWithZeros(matrix, p.first, p.second);
        }
    }

    void fillWithZeros(vector<vector<int>>& matrix, int n, int m) {
        for (int j = 0, len = matrix[0].size(); j < len; ++j) {
            matrix[n][j] = 0;
        }

        for (int i = 0, len = matrix.size(); i < len; ++i) {
            matrix[i][m] = 0;
        }
    }
};