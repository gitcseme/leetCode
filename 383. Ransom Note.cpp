class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26, 0);
        for (int i = 0, len = ransomNote.length(); i < len; ++i) {
            int c = ransomNote[i] - 'a';
            --a[c];
        }
        
        for (int i = 0, len = magazine.length(); i < len; ++i) {
            int c = magazine[i] - 'a';
            ++a[c];
        }
        
        for (int i = 0; i < 26; ++i) {
            if (a[i] < 0)
                return false;
        }
        
        return true;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
