class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26, 0);
        for (int i = 0, len = s.length(); i < len; ++i) ++a[(s[i]-'a')];        
        for (int i = 0, len = t.length(); i < len; ++i) --a[(t[i]-'a')];
        
        for (int i = 0; i < 26; ++i) 
            if (a[i] != 0) return false;
        
        return true;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
