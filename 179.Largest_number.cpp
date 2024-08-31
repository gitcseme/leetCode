class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int& a, int& b) {
            auto sa = to_string(a);
            auto sb = to_string(b);
            return (sa + sb) > (sb + sa);
        });

        if (nums[0] == 0) return "0";

        string ans = "";
        for (auto& num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};
