class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> p(105, 0);
        p[0] = arr[0];
        int len = arr.size();
        for (int i = 1; i < len; ++i) {
            p[i] = arr[i] + p[i-1];
        }
        
        int total = 0;
        for (int s = 1; ; s += 2) {
            if (s > len) 
                break;
            for (int i = 0; i < len-s+1; ++i) {
                if (i + s <= len) {
                    total += p[i+s-1] - (i == 0 ? 0 : p[i-1]);
                }
                else 
                    break;
            }
        }
        
        return total;
    }
};
