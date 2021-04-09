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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0,  area = 0, N = heights.size();

        for (int i = 0; i < N; ++i) {
            if (stk.empty() || heights[stk.top()] <= heights[i])
                stk.push(i);
            else {
                while (!stk.empty() && heights[stk.top()] > heights[i]) {
                    int x = stk.top(); stk.pop();
                    area = stk.empty() ? (heights[x] * i) : (heights[x] * (i - stk.top() - 1));
                    maxArea = max(maxArea, area);
                }
                stk.push(i);
            }
        }

        while (!stk.empty()) {
            int x = stk.top(); stk.pop();
            area = stk.empty() ? (heights[x] * N) : (heights[x] * (N - stk.top() - 1));
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int mxRec = 0;

        for (int i = 0, len = matrix.size(); i < len; ++i) {
            for (int j = 0, len2 = matrix[0].size(); j < len2; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            mxRec = max(mxRec, largestRectangleArea(heights));
        }

        return mxRec;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<vector<char>> vec = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << sln.maximalRectangle(vec) << "\n";

    return 0;
}

