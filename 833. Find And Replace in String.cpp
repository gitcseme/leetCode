class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> updates;
        for (int i = 0, len = indices.size(); i < len; ++i) {
            updates.push_back({indices[i], i});
        }

        sort(updates.rbegin(), updates.rend());

        for (auto& update : updates) {
            int pos = update.first;
            string& source = sources[update.second];
            string& target = targets[update.second];

            int sLen = source.size();
            if (s.substr(pos, sLen) == source) {
                s = s.substr(0, pos) + target + s.substr(pos + sLen);
            }
        }

        return s;
    }
};
