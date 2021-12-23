class Solution {
public:
    bool isPowerOfTwo(int n) {
        vector<long long> powers;
        long long p = 1;
        for (int i = 0; i <= 31; ++i) {
            powers.push_back(p);
            p = p * 2;
        }
        
        if (find(powers.begin(), powers.end(), n) != powers.end()) 
            return true;
        
        return false;
    }
};
