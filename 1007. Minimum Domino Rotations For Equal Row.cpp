class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> top(7, 0);      
        vector<int> bot(7, 0);
        vector<int> same(7, 0);
        int len = tops.size();

        for (int i = 0; i < len; ++i) {
            ++top[tops[i]];
            ++bot[bottoms[i]];
            if (tops[i] == bottoms[i]) ++same[tops[i]];
        }

        int ans = 200000;
        for (int i = 1; i <= 6; ++i) {
            if (top[i] + bot[i] - same[i] == len) {
                ans = min(ans, min(top[i], bot[i]) - same[i]);
            }
        }

        return ans == 200000 ? -1 : ans;
    }
};
