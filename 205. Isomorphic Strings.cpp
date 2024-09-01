class Solution {
public:
    bool isOneWayIsomorphic(string& s, string& t) {
        unordered_map<char, char> map;

        for (int i = 0, len = s.size(); i < len; ++i) {
            if (map.count(s[i]) && map[s[i]] != t[i]) {
                return false;
            }
            map[s[i]] = t[i];
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        return isOneWayIsomorphic(s, t) && isOneWayIsomorphic(t, s);
    }
};
