#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define FIRSTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size()-1;
        vector<int> ret;

        while (L < R) {
            if (numbers[L]+numbers[R] == target) {
                ret = { ++L, ++R };
                break;
            }
            if (numbers[L] + numbers[R] < target)
                ++L;
            else
                --R;
        }
        return ret;
    }
};

int main() {
    //FI;
    vector<int> vec = {-8, -5, -3, 0, 2,7,11,15};
    int target = 3;
    Solution sln;
    auto ans = sln.twoSum(vec, target);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}
