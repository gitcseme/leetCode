class Solution {
public:
    string getSmallestString(int n, int k) {
        deque<char> ans;
        for (int i = n; i >= 1; --i) {
            int val = k - (i - 1);
            if (val >= 26) {
                ans.push_back('z');
                k = k - 26;
            }
            else {
                char c = 'a' + (val - 1);
                ans.push_front(c);
                k = k - val;
            }
        }

        string t = "";
        for (int i = 0; i < ans.size(); ++i) t += ans[i];
        
        return t;
    }
};
