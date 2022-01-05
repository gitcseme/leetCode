class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (vector<int> v : matrix) {
            if (binary_search(v.begin(), v.end(), target)) {
                return true;
            }
        }
        
        return false;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
