class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0, len = s.length(); i < len; ++i) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            else {
                if (stk.empty() || stk.top() != complement(c))
                    return false;
                
                stk.pop();
            }
        }
        
        return stk.empty();
    }
    
    char complement(char c) {
        if (c == ')') return '(';
        if (c == '}') return '{';        
        return '[';
    }
};
