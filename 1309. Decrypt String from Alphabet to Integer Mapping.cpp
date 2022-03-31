class Solution {
public:
    string freqAlphabets(string s) {
        string d = "";
        for (int i = s.length()-1; i >= 0; --i) {
            if (s[i] == '#') {
                int n = to_number(s.substr(i-2, 2)) - 1;
                d = (char)('a' + n) + d;
                i -= 2;
            }
            else {
                d = (char)('a' + (s[i] - '0') - 1) + d;
            }
        }
        
        return d;
    }
    
    int to_number(string t) {
        return (t[0] - '0') * 10 + (t[1] - '0');
    }
};
