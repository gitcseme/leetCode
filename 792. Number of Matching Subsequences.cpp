class Solution {
public:
    unordered_map<char, vector<int>> cp_map;
    int numMatchingSubseq(string s, vector<string>& words) {
        for (int i = 0, n = s.size(); i < n; ++i) {
            cp_map[s[i]].push_back(i);
        }

        int subCount = 0;
        for(string& word : words) {
            if (isSubsequence(word)) {
                ++subCount;
            }
        }

        return subCount;
    }

    bool isSubsequence(string& word) {
        int match_idx = -1, w_len = word.size();

        for (int i = 0; i < w_len; ++i) {
            vector<int>& f = cp_map[word[i]];
            int pos = upper_bound(f.begin(), f.end(), match_idx) - f.begin();

            if (pos < f.size()) {
                match_idx = f[pos];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
