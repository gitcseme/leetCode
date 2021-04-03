#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(auto i : v) {cout << i << " ";} cout << "\n";
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> increasedNum;
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            int n = digits[i];
            n = n + carry;
            carry = n / 10;
            increasedNum.push_back(n%10);
        }
        if (carry != 0) increasedNum.push_back(carry);
        reverse(increasedNum.begin(), increasedNum.end());
        return increasedNum;
    }
};

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int main() {
    //FI;
    Solution sln;
    vector<int> vec = {0};
    auto v = sln.plusOne(vec);
    FOR(v);

    return 0;
}

