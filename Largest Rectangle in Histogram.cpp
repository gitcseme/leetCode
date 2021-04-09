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
            if (stk.empty() || heights[stk.top()] <= heights[i]) {
                stk.push(i);
            }
            else {
                while (!stk.empty() && heights[stk.top()] > heights[i]) {
                    int x = stk.top(); stk.pop();
                    if (stk.empty()) {
                        area = (long long) heights[x] * i;
                    }
                    else {
                        area = (long long) heights[x] * (i - stk.top() - 1);
                    }
                    maxArea = max(maxArea, area);
                }
                stk.push(i);
            }
        }

        while (!stk.empty()) {
            int x = stk.top(); stk.pop();
            if (stk.empty()) {
                area = N * heights[x];
            }
            else {
                area = (long long) heights[x] * (N - stk.top() - 1);
            }
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {2,4};
    cout << sln.largestRectangleArea(vec) << "\n";

    return 0;
}

