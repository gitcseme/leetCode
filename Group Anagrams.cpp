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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> dict;

        for (auto& str : strs) {
            long long h = calculateHash(str);
            dict[h].push_back(str);
        }

        vector<vector<string>> grps;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            grps.push_back(it->second);
        }

        return grps;
    }
};



//-> Normal solution
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> groups;
    string key;
    for (int i = 0; i < strs.size(); ++i) {
        key = strs[i];
        sort(key.begin(), key.end());
        groups[key].push_back(strs[i]);
    }

    vector<vector<string>> res;
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        res.push_back(it->ss);
    }

    return res;
}
