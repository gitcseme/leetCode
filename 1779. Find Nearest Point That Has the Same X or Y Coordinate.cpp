class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int smallest = INT_MAX, index = -1;
        for (int i = 0, len = points.size(); i < len; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            if (x == x1 || y == y1) {
                int d = abs(x - x1) + abs(y - y1);
                if (smallest > d) {
                    smallest = d;
                    index = i;
                }
            }
        }
        return index;
    }
};
