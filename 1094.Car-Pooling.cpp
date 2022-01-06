class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1001, 0);
        for (vector<int> p : trips) {
            road[p[1]] += p[0];
            road[p[2]] -= p[0];
        }
        
        int people = 0;
        for (int i = 0; i < 1001; ++i) {
            people += road[i];
            if (people > capacity) {
                return false;
            }
        }
        
        return true;
    }
};
