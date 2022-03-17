class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        for (int i = 0, len = s.length(); i < len; ++i) {
            if (s[i] == '(') {
                stk.push(0);
            }
            else {
                int cur = 0;
                while (stk.top() != 0)
                {
                    cur += stk.top();
                    stk.pop();
                }
                
                stk.pop();
                stk.push(max(2 * cur, 1));
            }
        }
        
        int score = 0;
        while (!stk.empty()) {
            score += stk.top();
            stk.pop();
        }

        return score;
    }
};
