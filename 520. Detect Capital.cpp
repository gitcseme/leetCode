class Solution {
public:
    bool detectCapitalUse(string s) {
        int len = s.length();
        
        bool allCap = true, allLow = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                allCap = false;
            }
            else {
                allLow = false;
            }
        }
        
        if (allCap || allLow) return true;
        
        for (int i = 0; i < len; ++i) {
            if (i == 0) {
                if (s[i] >= 'a' && s[i] <= 'z')
                    return false;
            }
            else if ((s[i] >= 'A' && s[i] <= 'Z')) {
                return false;
            }
        }
        
        return true;
    }
};
