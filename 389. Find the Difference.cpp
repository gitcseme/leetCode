class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.length();
        int extraChar = 0;
        
        for (int i = 0; i < len; ++i) {
            extraChar -= (s[i] - 'a');
            extraChar += (t[i] - 'a');
        }
        
        extraChar += (t[len] - 'a');
        
        return (char)(extraChar+'a');
    }
};

