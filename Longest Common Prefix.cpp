string longestCommonPrefix(vector<string>& strs) {
    int min_length = INT_MAX;
    for (auto &s : strs) {
        min_length = min(min_length, (int)s.size());
    }
    
    int lcp = 0, n = strs.size();
    for (int i = 0; i < min_length; ++i) {
        bool match = true;
        for (int j = 0; j + 1 < n; ++j) {
            match = match & (strs[j][i] == strs[j+1][i]);
        }

        if (!match) break;
        ++lcp;
    }

    return strs[0].substr(0, lcp);
}
