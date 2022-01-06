class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = 1;
            }
            else {
                m[s[i]]++;
            }
        }
        
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (m[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
