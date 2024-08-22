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


class Solution {
public:
    long long calculateHash(string& str) {
        long long H = 1;
        static long long BASE = 789;
        static long long MOD = 1000000000 + 7;

        for (char& c : str) {
            H = (H * (BASE + c)) % MOD;
        }

        return H;
    }

    bool isAnagram(string s, string t) {
        auto h1 = calculateHash(s);
        auto h2 = calculateHash(t);
        return h1 == h2;
    }
};
