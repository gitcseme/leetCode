class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> dpf(n, 1), dpr(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i] && 1 + dpf[j] > dpf[i]) {
                    dpf[i] = 1 + dpf[j];
                }
            }
        }

        for (int i = n-1; i >= 0; --i) {
            for (int j = n-1; j > i; --j) {
                if (a[j] < a[i] && 1 + dpr[j] > dpr[i]) {
                    dpr[i] = 1 + dpr[j];
                }
            }
        }

        int mx_bitonic = 1;
        for (int i = 0; i < n; ++i) {
            if (dpf[i] == 1 || dpr[i] == 1)
                continue;
            
            mx_bitonic = max(mx_bitonic, dpf[i] + dpr[i] - 1);
        }
        
        return n - mx_bitonic;
    }
};

// LEET CODE
static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
