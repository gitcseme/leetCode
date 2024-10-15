class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sn = 0;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            sn = sn ^ nums[i];
        }

        return sn;
    }
};
