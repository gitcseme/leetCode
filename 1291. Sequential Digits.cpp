class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowd = to_string(low).length();
        int highd = to_string(high).length();

        vector<int> ans;
        for (int size = lowd; size <= highd; ++size) {
            getIncreasingNumbers(size, ans, low, high);
        }

        return ans;
    }

    void getIncreasingNumbers(int size, vector<int>& ans, int lo, int hi) {
        string digits = "123456789", n;
        int num;
        for (int i = 0; i <= 9-size; ++i) {
            n = digits.substr(i, size);
            stringstream sso(n);
            sso >> num;
            if (num >= lo && num <= hi) {
                ans.push_back(num);
            }
            else if (num > hi) {
                break;
            }
        }
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
