class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = 'a' + (s[i] - 'A');
            }
        }
        return s;
    }
};
