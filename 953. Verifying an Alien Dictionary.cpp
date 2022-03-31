class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        m['0'] = 0;
        for (int i = 0, len = order.length(); i < len; ++i) {
            m[order[i]] = i + 1;
        }
        
        for (int i = 1, len = words.size(); i < len; ++i) {
            int mx = max(words[i-1].length(), words[i].length());
            
            pad(words[i-1], mx);
            pad(words[i], mx);
            
            cout << words[i-1] << "\n" << words[i] << "\n";
            
            for (int j = 0; j < mx; ++j) {
                if (m[words[i-1][j]] < m[words[i][j]]) {
                    break;
                }
                if (m[words[i-1][j]] > m[words[i][j]]) {
                    //cout << words[i-1][j] << " " << words[i][j] << "\n";
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void pad(string &s, int n) {
        int len = s.length();
        
        while(len++ < n) s += '0';
    }
};
