class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (stk.empty() || stk.top().first != s[i]) {
                stk.push({ s[i], 1 });
            }
            else {
                int newCount = stk.top().second + 1;
                stk.pop();
                stk.push({ s[i], newCount });
            }
            
            if (stk.top().second == k) {
                stk.pop();
            }
        }
        
        string ans = "";
        while(!stk.empty()) {
            auto e = stk.top();
            stk.pop();
            
            while (e.second--) ans += e.first;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
