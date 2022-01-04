class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0);
        vector<int> out(n+1, 0);
        
        for (vector<int> v : trust) {
            ++in[v[1]];
            ++out[v[0]];
        }
        
        int label = -1;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == n-1 && out[i] == 0) {
                label = i;
                break;
            }
        }
        
        return label;
    }
};
