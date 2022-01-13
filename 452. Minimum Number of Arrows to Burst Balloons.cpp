class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> bals;
        int totalBallons = points.size(), arrowCount = 0;
        for (int i = 0; i < totalBallons; ++i) {
            bals.push_back({points[i][0], points[i][1]});
        }

        sort(bals.begin(), bals.end()); // Sort according to first value. default sort does it for us.
        int L = bals[0].first, R = bals[0].second;  // intersection points
        pair<int, int> c;
        
        for (int i = 1; i < totalBallons; ++i) {
            c = bals[i];

            if (c.first  <= R) {        // update intersection point
                L = max(L, c.first);
                R = min(R, c.second);
            }
            else {                      // new intersection point -> needs new arrow
                ++arrowCount;
                L = c.first;
                R = c.second;
            }
        }

        arrowCount += 1;                // to hit remaining ballons
        return arrowCount;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
