class Solution {
public:
    bool wordPattern(string pat, string s) {
        unordered_map<char, string> map;
        stringstream sso(s);
        
        vector<string> words;
        set<string> ws;
        string word;
        while (sso >> word) {
            words.push_back(word);
            ws.insert(word);
        }
        
        int pLen = pat.length();
        set<char> ps;
        for (int i = 0; i < pLen; ++i) ps.insert(pat[i]);
        
        int wLen = words.size();
        if (pLen != wLen || ws.size() != ps.size()) return false;
        
        for (int i = 0; i < pLen; ++i) {
            if (map.find(pat[i]) != map.end()) {
                if (map[pat[i]] != words[i])
                    return false;
            }
            else {
                map[pat[i]] = words[i];
            }
        }
        
        return true;
    }
};
